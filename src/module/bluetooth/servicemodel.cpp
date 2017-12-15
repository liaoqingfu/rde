#include "servicemodel.h"
/*                                                                                               */
ServiceModel::ServiceModel(QObject *parent):Model(parent)
{
    scan();
}
/*                                                                                               */
QHash<int, QByteArray> ServiceModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[257]="Name";
    hash[258]="Description";
    hash[259]="UUID";
    return hash;
}
/*                                                                                               */
QVariant ServiceModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case Name:return list.at(index.row()).serviceName();
        case Description:return list.at(index.row()).serviceDescription();
        case UUID:return list.at(index.row()).serviceUuid().toByteArray();
        }
    }
    return QVariant();
}
/*                                                                                               */
void ServiceModel::scan()
{
    agent=new QBluetoothServiceDiscoveryAgent(this);
    connect(agent,SIGNAL(serviceDiscovered(QBluetoothServiceInfo)),this,SLOT(serviceDiscovered(QBluetoothServiceInfo)));
    connect(agent,SIGNAL(error(QBluetoothServiceDiscoveryAgent::Error)),this,SLOT(error(QBluetoothServiceDiscoveryAgent::Error)));
    connect(agent,SIGNAL(canceled()),this,SLOT(scanCanceled()));
    connect(agent,SIGNAL(finished()),this,SLOT(scanFinished()));
    agent->start();
}
/*                                                                                               */
void ServiceModel::serviceDiscovered(const QBluetoothServiceInfo &info)
{
    list.append(info);
}
/*                                                                                               */
void ServiceModel::error(QBluetoothServiceDiscoveryAgent::Error error)
{
    qDebug() << agent->errorString();
    switch(error){
    case QBluetoothServiceDiscoveryAgent::NoError:
        qDebug() << "No error";
        break;
    case QBluetoothServiceDiscoveryAgent::PoweredOffError:
        qDebug() << "Powered off error";
        break;
    case QBluetoothServiceDiscoveryAgent::InputOutputError:
        qDebug() << "I/O error";
        break;
    case QBluetoothDeviceDiscoveryAgent::InvalidBluetoothAdapterError:
        qDebug() << "Invalid bluetooth adapter";
        break;
    case QBluetoothDeviceDiscoveryAgent::UnknownError:
        qDebug() << "Unknown bluetooth error";
        break;
    }
}
/*                                                                                               */
void ServiceModel::scanFinished()
{
    beginResetModel();
    endResetModel();
}
/*                                                                                               */
void ServiceModel::scanCanceled()
{
    qDebug() << "Scanning for services cancelled...";
}
/*                                                                                               */