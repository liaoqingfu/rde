#include "listmodel.h"
/*                                                                                               */
ListModel::ListModel(QObject *parent):Model(parent)
{
    m_watcher=new QFileSystemWatcher(this);
    connect(m_watcher,SIGNAL(directoryChanged(QString)),this,SLOT(directoryChanged(QString)));
    QSettings settings;
    settings.beginGroup("Gaming");
    m_watcher->addPath(settings.value("ListPath","/system/config/rde/list").toString());
    settings.endGroup();

    directoryChanged(m_watcher->directories().at(0));
}
/*                                                                                               */
void ListModel::directoryChanged(const QString &directory)
{
    beginResetModel();
    QDir dir(directory,"*.conf");
    list=dir.entryInfoList();
    endResetModel();
}
/*                                                                                               */
QHash<int, QByteArray> ListModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="File";
    hash[1]="Name";
    return hash;
}
/*                                                                                               */
QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case File:return list.at(index.row()).absoluteFilePath();
        case Name:return list.at(index.row()).baseName();
        }
    }
    return QVariant();
}
/*                                                                                               */