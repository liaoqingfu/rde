#include "bookmarkmodel.h"
/*                                                                                               */
BookmarkModel::BookmarkModel(QObject *parent):Model(parent)
{
    QStringList ll;
    ll << "YouTube" << "http://www.youtube.com","hticon";
    list << ll;
}
/*                                                                                               */
QHash<int, QByteArray> BookmarkModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[257]="Name";
    hash[258]="Icon";
    hash[259]="URL";
    return hash;
}
/*                                                                                               */
QVariant BookmarkModel::data(const QModelIndex &index,int role)const
{
    if(index.isValid()){
        switch(Roles(role)){
        case Name:return list.at(index.row()).at(0);
        case Icon:return list.at(index.row()).at(1);
        case URL:return list.at(index.row()).at(2);
        }
    }
    return QVariant();
}
/*                                                                                               */