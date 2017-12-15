#include "textpreview.h"
/*                                                                                               */
TextPreview::TextPreview():QQuickItem()
{
    watcher=new QFutureWatcher<QByteArray>(this);
    connect(watcher,SIGNAL(started()),this,SIGNAL(started()));
    connect(watcher,SIGNAL(finished()),this,SLOT(finished()));
    fileWatcher=new QFileSystemWatcher(this);
    connect(fileWatcher,SIGNAL(fileChanged(QString)),this,SLOT(fileChanged(QString)));
}
/*                                                                                               */
void TextPreview::setFile(const QString &newFile)
{
    fileWatcher->addPath(newFile);
    fileChanged(newFile);
}
/*                                                                                               */
void TextPreview::fileChanged(const QString &file)
{
    watcher->setFuture(QtConcurrent::run(this,&TextPreview::thread,file));
}
/*                                                                                               */
extern QByteArray TextPreview::thread(const QString &file)
{
    QFile f(file);
    if(f.open(QIODevice::ReadOnly))
        return f.readAll();
    return 0;
}
/*                                                                                               */
void TextPreview::finished()
{
    text=watcher->result();
    emit textChanged();
}
/*                                                                                               */