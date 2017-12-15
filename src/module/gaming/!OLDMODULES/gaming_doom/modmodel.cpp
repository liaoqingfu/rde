#include "modmodel.h"
/*                                                                                               */
ModModel::ModModel():Model()
{
    QDir dir("/games/doom/mod","*.wad *.zip *.pk3 *.pk7 *.7z");
    foreach(QFileInfo info,dir.entryInfoList()){
        new Mod(info.absoluteFilePath());
    }
}
/*                                                                                               */
QHash<int, QByteArray> ModModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="name";
    return hash;
}
/*                                                                                               */
QVariant ModModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        if(role==0)
            return Mod::mods.at(index.row())->name();
        else if(role==1)
            return Mod::mods.at(index.row())->path();
    }
    else
        return QVariant();
}
/*                                                                                               */