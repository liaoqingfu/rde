#include "networkconfigurationmodel.h"
/*                                                                                               */
NetworkConfigurationModel::NetworkConfigurationModel():Model()
{
    QNetworkConfigurationManager m_manager;

    //foreach(QNetworkConfiguration config,m_manager.allConfigurations(QNetworkConfiguration::Defined)){
    foreach(QNetworkConfiguration config,m_manager.allConfigurations(QNetworkConfiguration::Discovered)){
        if(config.isValid()){
            m_list.append(config);
        }
    }
}
/*                                                                                               */
QHash<int, QByteArray> NetworkConfigurationModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Name";
    hash[1]="Bearer";
    hash[2]="IsActive";
    return hash;
}
/*                                                                                               */
QVariant NetworkConfigurationModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case Name:return m_list.at(index.row()).name();
        case Bearer:return m_list.at(index.row()).bearerTypeName();
        case IsActive:return m_list.at(index.row()).state().testFlag(QNetworkConfiguration::Active);
        }
    }
    return QVariant();
}
/*                                                                                               */
void NetworkConfigurationModel::select(const int &index)
{
    //ConfigurationManager::instance()->session->open();
}
/*                                                                                               */
void NetworkConfigurationModel::hold(const int &index)
{
    //ConfigurationManager::instance()->session->close();
}
/*                                                                                               */