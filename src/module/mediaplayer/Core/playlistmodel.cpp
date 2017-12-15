#include "playlistmodel.h"
/*                                                                                               */
PlaylistModel::PlaylistModel()
{
    connect(Player::instance()->playlist(),SIGNAL(loaded()),this,SLOT(loaded()));
    connect(Player::instance()->playlist(),SIGNAL(loadFailed()),this,SLOT(loadFailed()));
    connect(Player::instance()->playlist(),SIGNAL(mediaAboutToBeInserted(int,int)),this,SLOT(mediaAboutToBeInserted(int,int)));
    connect(Player::instance()->playlist(),SIGNAL(mediaInserted(int,int)),this,SLOT(mediaInserted(int,int)));
    connect(Player::instance()->playlist(),SIGNAL(mediaAboutToBeRemoved(int,int)),this,SLOT(mediaAboutToBeRemoved(int,int)));
    connect(Player::instance()->playlist(),SIGNAL(mediaRemoved(int,int)),this,SLOT(mediaRemoved(int,int)));
    connect(Player::instance()->playlist(),SIGNAL(currentIndexChanged(int)),this,SLOT(indexChanged(int)));
}
/*                                                                                               */
void PlaylistModel::loaded()
{
    //    beginResetModel();

    //    endResetModel();
}
/*                                                                                               */
void PlaylistModel::loadFailed()
{
    //qDebug() << "Failed to load playlist " << m_file;
}
/*                                                                                               */
void PlaylistModel::mediaAboutToBeInserted(const int &start, const int &end)
{
    beginInsertRows(QModelIndex(),start,end);
}
/*                                                                                               */
void PlaylistModel::mediaInserted(const int &start, const int &end)
{
    endInsertRows();
    Player::instance()->playlist()->setCurrentIndex(start);
}
/*                                                                                               */
void PlaylistModel::mediaAboutToBeRemoved(const int &start, const int &end)
{
    beginRemoveRows(QModelIndex(),start,end);
}
/*                                                                                               */
void PlaylistModel::mediaRemoved(const int &start, const int &end)
{
    endRemoveRows();
}
/*                                                                                               */
void PlaylistModel::indexChanged(const int &index)
{
    //emit currentIndexChanged();
}
/*                                                                                               */
QHash<int,QByteArray> PlaylistModel::roleNames()const
{
    QHash<int,QByteArray> hash;
    hash[0]="Title";
    hash[1]="Artist";
    return hash;
}
/*                                                                                               */
QVariant PlaylistModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        QFileInfo info(Player::instance()->playlist()->media(index.row()).canonicalUrl().toLocalFile());
        QString str=info.baseName();
        switch(Roles(role)){
        case Title:{
            if(str.contains(" - "))
                return str.mid(str.indexOf(" - ")+3);
            break;
        }
        case Artist:
            if(str.contains(" - "))
                return str.left(str.indexOf(" - "));
            break;
        }
    }
    return QVariant();
}
/*                                                                                               */
PlaylistModel::~PlaylistModel()
{
    Player::instance()->savePlaylist();
}
/*                                                                                               */