#include "eventmodel.h"
/*                                                                                               */
EventModel::EventModel(QObject *parent):QAbstractItemModel(parent)
{
    watcher=new QFutureWatcher<QVector<Event*> >(this);
    connect(watcher,SIGNAL(started()),this,SLOT(started()));
    connect(watcher,SIGNAL(finished()),this,SLOT(finished()));
}
/*                                                                                               */
QHash<int, QByteArray> EventModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[257]="Hour";
    hash[258]="Minute";
    hash[259]="Second";
    hash[260]="Description";
    return hash;
}
/*                                                                                               */
QVariant EventModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case Hour:return list.at(index.row())->getHour();
        case Minute:return list.at(index.row())->getMinute();
        case Second:return list.at(index.row())->getSecond();
        case Description:return list.at(index.row())->getDescription();
        }
    }
    return QVariant();
}
/*                                                                                               */
void EventModel::setSelectedDate(const QString &date)
{
    watcher->setFuture(QtConcurrent::run(this,&EventModel::thread,date));
}
/*                                                                                               */
extern QVector<Event*> EventModel::thread(const QString &date)
{
    QVector<Event*> l;
    qDebug() << "Date set to " << date;
    return l;
}
/*                                                                                               */
void EventModel::started()
{
    beginResetModel();
}
/*                                                                                               */
void EventModel::finished()
{
    list=watcher->result();
    endResetModel();
}
/*                                                                                               */
EventModel::~EventModel()
{
}
/*                                                                                               */