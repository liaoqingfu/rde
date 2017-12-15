#include "accesspointmodel.h"
/*                                                                                               */
AccessPointModel::AccessPointModel(QObject *parent):Model(parent)
{
    manager=new QNetworkConfigurationManager(this);
    connect(manager,SIGNAL(configurationAdded(QNetworkConfiguration)),this,SLOT(configurationAdded(QNetworkConfiguration)));
    connect(manager,SIGNAL(configurationChanged(QNetworkConfiguration)),this,SLOT(configurationChanged(QNetworkConfiguration)));
    connect(manager,SIGNAL(configurationRemoved(QNetworkConfiguration)),this,SLOT(configurationRemoved(QNetworkConfiguration)));
    connect(manager,SIGNAL(updateCompleted()),this,SLOT(updateCompleted()));

    watcher=new QFutureWatcher<QList<QNetworkConfiguration> >(this);
    connect(watcher,SIGNAL(finished()),this,SLOT(finished()));

    update();
}
/*                                                                                               */
void AccessPointModel::update()
{
    manager->updateConfigurations();
}
/*                                                                                               */
void AccessPointModel::updateCompleted()
{
    watcher->setFuture(QtConcurrent::run(this,&AccessPointModel::thread));
}
/*                                                                                               */
QList<QNetworkConfiguration> AccessPointModel::thread()
{
    QList<QNetworkConfiguration> list;
    foreach(QNetworkConfiguration configuration,manager->allConfigurations(QNetworkConfiguration::Discovered)){
        if(configuration.isValid() && configuration.bearerType()==QNetworkConfiguration::BearerWLAN){
            list << configuration;
        }
    }
    return list;
}
/*                                                                                               */
void AccessPointModel::finished()
{
    beginResetModel();
    list=watcher->result();
    endResetModel();
}
/*                                                                                               */
QHash<int,QByteArray> AccessPointModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[257]="Name";
    hash[258]="Identifier";
    hash[259]="Bearer";
    return hash;
}
/*                                                                                               */
QVariant AccessPointModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case Name:return list.at(index.row()).name();
        case Identifier: return list.at(index.row()).identifier();
        case Bearer: return list.at(index.row()).bearerTypeName();
        }
    }
    return QVariant();
}
/*                                                                                               */
void AccessPointModel::configurationAdded(const QNetworkConfiguration &config)
{
    //"Network configuration " << config.name() << " added";
}
/*                                                                                               */
void AccessPointModel::configurationChanged(const QNetworkConfiguration &config)
{
    //<< "Network configuration " << config.name() << " changed";
}
/*                                                                                               */
void AccessPointModel::configurationRemoved(const QNetworkConfiguration &config)
{
    //<< "Network configuration " << config.name() << " removed";
}
/* EOF                                                                                           */