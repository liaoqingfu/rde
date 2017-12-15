#include "volumemodel.h"
/*                                                                                               */
VolumeModel::VolumeModel(QObject *parent):Model(parent)
{
    vector.append(new Volume("Home","Home","Location",QDir::homePath()));

    // add volumes
    foreach(QStorageInfo volume,QStorageInfo::mountedVolumes()){
        if(volume.isValid() && volume.isReady() && volume.device()!="tmpfs" && !volume.name().isEmpty()){
            vector.append(new Volume(volume.name(),volume.displayName(),volume.device(),volume.rootPath()));
        }
    }
}
/*                                                                                               */
QHash<int,QByteArray> VolumeModel::roleNames()const
{
    QHash<int,QByteArray> hash;
    hash[0]="Name";
    hash[1]="DisplayName";
    hash[2]="Device";
    hash[3]="RootPath";
    hash[4]="BytesTotal";
    hash[5]="BytesAvailable";
    hash[6]="Ready";
    return hash;
}
/*                                                                                               */
QVariant VolumeModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){

        case Name:
            return vector.at(index.row())->name();
        case DisplayName:
            return vector.at(index.row())->displayName();
        case Device:{
            QString device=vector.at(index.row())->device();
            device=device.mid(device.lastIndexOf("/")+1,3);
            return device;
        }
        case RootPath:return vector.at(index.row())->rootPath();
        //case BytesTotal:;return vector.at(index.row()).bytesTotal();
        //case BytesAvailable:return;// list.at(index.row()).bytesAvailable();
        //case Ready:return;// list.at(index.row()).isReady();
        }
    }
    return QVariant();
}
/*                                                                                               */
void VolumeModel::setCurrentIndex(const int &index)
{
    qDebug() << "Selected " << vector.at(index)->displayName();
}
/*                                                                                               */