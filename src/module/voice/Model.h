#ifndef MODEL_H
#define MODEL_H
/*                                                                                               */
#include <QAbstractItemModel>
/*                                                                                               */
class Model : public QAbstractItemModel
{
    Q_OBJECT
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)
public:
    explicit Model(){}
    int currentIndex()const{return m_currentIndex;}
protected:
    int m_currentIndex;
private:
    QModelIndex index(int row, int column, const QModelIndex &parent)const{Q_UNUSED(parent);return createIndex(row,column);}
    QModelIndex parent(const QModelIndex &child)const{Q_UNUSED(child);return QModelIndex();}
    int columnCount(const QModelIndex &parent)const{Q_UNUSED(parent);return 1;}
    virtual void setCurrentIndex(const int &index){Q_UNUSED(index)}

signals:
    void currentIndexChanged();
};
/*                                                                                               */
#endif