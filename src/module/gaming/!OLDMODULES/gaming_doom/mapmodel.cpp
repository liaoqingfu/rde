#include "mapmodel.h"
/*                                                                                               */
MapModel::MapModel():Model()
{
    QDir dir("/games/doom/map","*.wad *.zip *.pk3 *.pk7 *.7z");
    foreach(QFileInfo info,dir.entryInfoList()){
        new Map(info.absoluteFilePath());
    }
}
/*                                                                                               */
QHash<int, QByteArray> MapModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="name";
    hash[1]="path";
    return hash;
}
/*                                                                                               */
QVariant MapModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        if(role==0)
        return Map::maps.at(index.row())->name();
        else if(role==1)
            return Map::maps.at(index.row())->path();
    }
    return QVariant();
}
/*                                                                                               */