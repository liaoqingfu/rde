#include "networkinterfacemodel.h"
/*                                                                                               */
NetworkInterfaceModel::NetworkInterfaceModel():Model()
{
    foreach(QNetworkInterface interface,QNetworkInterface::allInterfaces()){
        if(interface.isValid() && !interface.flags().testFlag(QNetworkInterface::IsLoopBack)){
            m_list.append(interface);
        }
    }
}
/*                                                                                               */
QHash<int, QByteArray> NetworkInterfaceModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Name";
    hash[1]="IsUp";
    hash[2]="IsRunning";
    hash[3]="MacAddress";
    //hash[4]="IconSource";
    return hash;
}
/*                                                                                               */
QVariant NetworkInterfaceModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case Name:return m_list.at(index.row()).humanReadableName();
        case IsUp:return m_list.at(index.row()).flags().testFlag(QNetworkInterface::IsUp);
        case IsRunning:return m_list.at(index.row()).flags().testFlag(QNetworkInterface::IsRunning);
        case MacAddress:return m_list.at(index.row()).hardwareAddress();
        }
    }
    return QVariant();
}
/* eof                                                                                           */