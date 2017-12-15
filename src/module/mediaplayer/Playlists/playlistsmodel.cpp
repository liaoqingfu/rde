#include "playlistsmodel.h"
/*                                                                                               */
PlaylistsModel::PlaylistsModel(QObject *parent):Model(parent)
{
    m_path=QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation).at(0)+"/playlist";
    startScan();
}
/*                                                                                               */
void PlaylistsModel::startScan()
{
    m_watcher=new QFutureWatcher<QFileInfoList>(this);
    connect(m_watcher,SIGNAL(finished()),this,SLOT(scanFinished()));
    m_watcher->setFuture(QtConcurrent::run(this,&PlaylistsModel::scan));
}
/*                                                                                               */
extern QFileInfoList PlaylistsModel::scan()
{
    QDir dir(m_path,"*.m3u");
    return dir.entryInfoList();
}
/*                                                                                               */
void PlaylistsModel::scanFinished()
{
    beginResetModel();
    m_list=m_watcher->result();
    endResetModel();
    m_watcher->deleteLater();
}
/*                                                                                               */
QHash<int,QByteArray> PlaylistsModel::roleNames()const
{
    QHash<int,QByteArray> hash;
    hash[0]="File";
    hash[1]="Name";
    return hash;
}
/*                                                                                               */
QVariant PlaylistsModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case File:return m_list.at(index.row()).absoluteFilePath();
        case Name:return m_list.at(index.row()).baseName();
        }
    }
    return QVariant();
}
/*                                                                                               */