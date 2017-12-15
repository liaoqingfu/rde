#include "tabmodel.h"

TabModel::TabModel(QObject *parent):Model(parent)
{
    //map[createIndex(0,0)]=new WebPage("http://www.mameworld.info");
    //map[createIndex(1,0)]=new WebPage("http://www.google.com");
}

//void TabModel::acceptURL(const QString &url)
//{
//    beginInsertRows(QModelIndex(),map.size(),0);

//    map[createIndex(0,0)]=new WebPage(url);


//    endInsertRows();
//}

QHash<int, QByteArray> TabModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[257]="URL";
    hash[258]="Icon";
    return hash;
}

QVariant TabModel::data(const QModelIndex &index,int role)const
{
    if(index.isValid()){
        switch(Roles(role)){
        case URL:return list.at(index.row())->getURL();
        case Icon:return list.at(index.row())->getIcon();
        }
    }
    return QVariant();
}