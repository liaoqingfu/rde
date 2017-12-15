#include "screensavermodel.h"
/*                                                                                               */
ScreensaverModel::ScreensaverModel(QObject *parent):Model(parent)
{
    fileWatcher=new QFileSystemWatcher(this);
    connect(fileWatcher,SIGNAL(directoryChanged(QString)),this,SLOT(directoryChanged(QString)));
    fileWatcher->addPath(Path);


    QDir dir(Path);
    dir.setFilter(QDir::Files|QDir::Executable);
    if(dir.isReadable()){
        list=dir.entryInfoList();
    }

    //QDir::entryInfoList()

    //list=QDir::entryInfoList("/usr/lib/xscreensaver");

    //QMimeDatabase db;
    //foreach(QFileInfo file,list){
        //QMimeType type=db.mimeTypeForFile(file.absoluteFilePath());
        //qDebug() << "Found " << file.absoluteFilePath() << ":" << type.name();
    //}
}
/*                                                                                               */
QHash<int, QByteArray> ScreensaverModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[257]="File";
    //hash[258]="Description";
    //hash[259]="Icon";
    //hash[260]="Version";
    return hash;
}
/*                                                                                               */
QVariant ScreensaverModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        return list.at(index.row()).baseName();
        //        switch(Roles(role)){/*
        //        case IID:return ModuleManager::modules.at(index.row())->iid();
        //        case Description:return ModuleManager::modules.at(index.row())->description();
        //        case Icon:return ModuleManager::modules.at(index.row())->icon();
        //        case Version:return ModuleManager::modules.at(index.row())->version();*/
        //        }
    }
    return QVariant();
}
/*                                                                                               */
void ScreensaverModel::directoryChanged(const QString &directory)
{
}
/*                                                                                               */
void ScreensaverModel::setCurrentIndex(const int &index)
{

    //qDebug() << "Selected screensaver " << list.at(index).absoluteFilePath();
    Session session(list.at(index).absoluteFilePath());
    m_currentIndex=index;
    emit currentIndexChanged();
}
/*                                                                                               */