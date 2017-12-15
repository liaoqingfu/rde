#ifndef EVENTMODEL_H
#define EVENTMODEL_H
/*                                                                                               */
#include <QAbstractItemModel>
#include "event.h"
#include <QDate>
#include <QFutureWatcher>
#include <QtConcurrentRun>
/*                                                                                               */
class EventModel : public QAbstractItemModel
{
    Q_OBJECT
    Q_PROPERTY(QString selectedDate READ selectedDate WRITE setSelectedDate NOTIFY selectedDateChanged)
public:
    explicit EventModel(QObject *parent = 0);
    ~EventModel();

private:
    enum Roles{Hour=257,Minute=258,Second=259,Description=260};
    QHash<int, QByteArray> roleNames() const;
    QVector<Event*> list;
    QVector<Event*> thread(const QString &date);
    QFutureWatcher<QVector<Event*> > *watcher;

    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return list.size();}
    int columnCount(const QModelIndex &parent)const{Q_UNUSED(parent);return 1;}
    QModelIndex index(int row, int column, const QModelIndex &parent)const{Q_UNUSED(parent);return createIndex(row,column);}
    QModelIndex parent(const QModelIndex &child)const{Q_UNUSED(child);return QModelIndex();}
    QString m_selectedDate;
    void setSelectedDate(const QString &date);
    QString selectedDate()const{return m_selectedDate;}

private slots:
    void started();
    void finished();

signals:
    void selectedDateChanged();
};
#endif