#ifndef ACCESSPOINTMODEL_H
#define ACCESSPOINTMODEL_H
#include "Model.h"
#include <QNetworkConfigurationManager>
#include <QNetworkConfiguration>
#include <QFutureWatcher>
#include <QtConcurrentRun>
class AccessPointModel : public Model
{
    Q_OBJECT
public:
    explicit AccessPointModel(QObject *parent = 0);

public slots:
    void update();

private:
    enum Roles{Name=257,Identifier=258,Bearer=259,Icon=260};
    QHash<int,QByteArray> roleNames() const;
    QList<QNetworkConfiguration> list;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return list.count();}
    QNetworkConfigurationManager *manager;
    QList<QNetworkConfiguration> thread();
    QFutureWatcher<QList<QNetworkConfiguration> > *watcher;

private slots:
    void finished();
    void configurationAdded(const QNetworkConfiguration & config);
    void configurationChanged(const QNetworkConfiguration & config);
    void configurationRemoved(const QNetworkConfiguration & config);
    void updateCompleted();
};
#endif