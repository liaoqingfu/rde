#include "imagemodel.h"

ImageModel::ImageModel():Model()
{
    QSettings settings("/SQEW/","Gallery");
    path=settings.value("Path",QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).at(0)).toString();
    QDir dir(path,"*.jpg *.png *.bmp *.tiff");
    list=dir.entryInfoList();
}

QHash<int,QByteArray> ImageModel::roleNames()const
{
    QHash<int,QByteArray> hash;
    hash[257]="FilePath";
    hash[258]="FileName";
    //    hash[259]="fileBaseName";
    //    hash[260]="fileIsDir";
    //    hash[261]="suffix";
    return hash;
}

QVariant ImageModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case FilePath:return list.at(index.row()).absoluteFilePath();
        case FileName:return list.at(index.row()).baseName();
        //case fileBaseName:return list.at(index.row()).baseName();
        //case fileIsDir:return list.at(index.row()).isDir();
        //case suffix:return list.at(index.row()).suffix();
        }
    }
    return QVariant();
}