#include "ini.h"
//-------------------------------------------------------------------------------------------------
Ini::Ini(const QString &newFile,QObject *parent):QObject(parent)
{
    file=newFile;
    QFile f(file);
    if(f.exists()){
        fileWatcher=new QFileSystemWatcher(this);
        fileWatcher->addPath(file);
        connect(fileWatcher,SIGNAL(fileChanged(QString)),this,SLOT(fileChanged(QString)));
        watcher=new QFutureWatcher<QMap<QString,QVariant> >(this);
        connect(watcher,SIGNAL(finished()),this,SLOT(finished()));
        fileChanged(file);
    }
    else;
        //"Could not find " << newFile;
}
//-------------------------------------------------------------------------------------------------
void Ini::fileChanged(const QString &file)
{
    watcher->setFuture(QtConcurrent::run(this,&Ini::thread,file));
}
//-------------------------------------------------------------------------------------------------
extern QMap<QString,QVariant> Ini::thread(const QString &file)
{
    QMap<QString,QVariant> map;
    QFile f(file);
    if(f.open(QFile::ReadOnly)){
        while(!f.atEnd()){
            QString line=f.readLine();
            if(!line.startsWith("#") && line.length()>1){
                line.chop(1);
                //qDebug() << line.left(line.indexOf(" ")) << ":" << line.mid(line.lastIndexOf(" ")+1);
                map.insert(line.left(line.indexOf(" ")),line.mid(line.lastIndexOf(" ")+1));
            }
        }
        f.close();
    }
    return map;
}
//-------------------------------------------------------------------------------------------------
void Ini::finished()
{
    settings=watcher->result();

    //qDebug() << "Found " << settings.size() << " entries in " << file;
    readSettingsReady();
}
//-------------------------------------------------------------------------------------------------