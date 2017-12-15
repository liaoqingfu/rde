#ifndef MODEL_H
#define MODEL_H
/*                                                                                               */
#include <QAbstractItemModel>
/*                                                                                               */
class Model : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = 0){}

private:
    int columnCount(const QModelIndex &parent)const{Q_UNUSED(parent);return 1;}
    QModelIndex index(int row, int column, const QModelIndex &parent)const{Q_UNUSED(parent);return createIndex(row,column);}
    QModelIndex parent(const QModelIndex &child)const{Q_UNUSED(child);return QModelIndex();}
};
/*                                                                                               */
#endif