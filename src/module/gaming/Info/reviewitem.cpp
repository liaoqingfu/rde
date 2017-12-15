#include "reviewitem.h"
/*                                                                                               */
ReviewItem::ReviewItem()
{
    m_watcher=new QFutureWatcher<QByteArray>(this);
    connect(m_watcher,SIGNAL(finished()),this,SLOT(finishedReading()));
}
/*                                                                                               */
void ReviewItem::updateReview(const QString &module, const QString &game)
{
    m_module=module;
    m_game=game;
    if(m_watcher->isRunning())
        m_watcher->cancel();
    m_watcher->setFuture(QtConcurrent::run(this,&ReviewItem::readThread,module,game));
}
/*                                                                                               */
extern QByteArray ReviewItem::readThread(const QString &module, const QString &game)
{
    QFile file("/gamemeta/review/"+module+"/"+game+".txt");
    if(file.open(QIODevice::ReadOnly)){
        return file.readAll().trimmed();
        file.close();
    }
    return NULL;
}
/*                                                                                               */
void ReviewItem::finishedReading()
{
    m_text=m_watcher->result();
    emit textChanged();
}
/*                                                                                               */
void ReviewItem::writeText(const QByteArray &text)
{
    m_text=text;
    QFileInfo info("/mame/ui/review/"+m_module+"/"+m_game+".txt");
    if(info.dir().mkpath(info.path()));
    QFile file("/mame/ui/review/"+m_module+"/"+m_game+".txt");
    if(file.open(QIODevice::WriteOnly)){
        file.write(text.trimmed());
        file.close();
    }
}
/*                                                                                               */