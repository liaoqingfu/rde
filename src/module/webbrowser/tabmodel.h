#ifndef TABMODEL_H
#define TABMODEL_H
#include "Model.h"
#include "webpage.h"
class TabModel : public Model
{
    Q_OBJECT
public:
    explicit TabModel(QObject *parent = 0);

//public slots:
    //void acceptURL(const QString &url);

private:
    enum Roles{URL=257,Icon=258};
    QHash<int, QByteArray> roleNames() const;
    QList<WebPage*> list;
    int rowCount(const QModelIndex &parent)const{return list.count();}
    QVariant data(const QModelIndex &index,int role)const;
};
#endif