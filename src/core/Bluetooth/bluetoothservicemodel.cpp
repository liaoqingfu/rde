#include "bluetoothservicemodel.h"
/*                                                                                               */
BluetoothServiceModel::BluetoothServiceModel():Model()
{
    m_agent=new QBluetoothServiceDiscoveryAgent(this);
    connect(m_agent,SIGNAL(serviceDiscovered(QBluetoothServiceInfo)),this,SLOT(serviceDiscovered(QBluetoothServiceInfo)));
    connect(m_agent,SIGNAL(error(QBluetoothServiceDiscoveryAgent::Error)),this,SLOT(error(QBluetoothServiceDiscoveryAgent::Error)));
    connect(m_agent,SIGNAL(finished()),this,SLOT(finished()));
    m_agent->start(QBluetoothServiceDiscoveryAgent::MinimalDiscovery);
}
/*                                                                                               */
QHash<int, QByteArray> BluetoothServiceModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Name";
    //hash[1]="IconName";
    return hash;
}
/*                                                                                               */
QVariant BluetoothServiceModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        //switch(Roles(role)){
        //case Name:return m_devices.at(index.row()).name();
        //case IconName:return getIconName(m_devices.at(index.row()));
        //}
    }
    return QVariant();
}
/*                                                                                               */
void BluetoothServiceModel::serviceDiscovered(const QBluetoothServiceInfo &info)
{

}
/*                                                                                               */
void BluetoothServiceModel::finished()
{
    beginResetModel();
    endResetModel();
    m_agent->deleteLater();
}
/*                                                                                               */
void BluetoothServiceModel::error(QBluetoothServiceDiscoveryAgent::Error error)
{
    switch(error){
    case QBluetoothServiceDiscoveryAgent::NoError:break;
    case QBluetoothServiceDiscoveryAgent::PoweredOffError:break;
    case QBluetoothServiceDiscoveryAgent::InputOutputError:break;
    case QBluetoothServiceDiscoveryAgent::InvalidBluetoothAdapterError:break;
    case QBluetoothServiceDiscoveryAgent::UnknownError:break;
    }
}
/*                                                                                               */