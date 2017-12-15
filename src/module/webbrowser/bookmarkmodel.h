#ifndef BOOKMARKMODEL_H
#define BOOKMARKMODEL_H
/*                                                                                               */
#include "Model.h"
/*                                                                                               */
class BookmarkModel : public Model
{
    Q_OBJECT
public:
    explicit BookmarkModel(QObject *parent = 0);
private:
    enum Roles{Name=257,Icon=258,URL=259};
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent)const{return list.count();}
    QVariant data(const QModelIndex &index,int role)const;
    QList<QStringList> list;
};
/*                                                                                               */
#endif