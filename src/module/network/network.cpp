#include "network.h"
/*                                                                                               */
bool Network::initialize()
{
    context->setContextProperty("Network",this);
    qmlRegisterType<ConfigurationModel>("org.rde.network",1,0,"ConfigurationModel");
    qmlRegisterType<InterfaceModel>("org.rde.network",1,0,"InterfaceModel");

    m_manager=new QNetworkConfigurationManager(this);
    connect(m_manager,SIGNAL(configurationAdded(QNetworkConfiguration)),this,SLOT(configurationAdded(QNetworkConfiguration)));
    connect(m_manager,SIGNAL(configurationChanged(QNetworkConfiguration)),this,SLOT(configurationChanged(QNetworkConfiguration)));
    connect(m_manager,SIGNAL(configurationRemoved(QNetworkConfiguration)),this,SLOT(configurationRemoved(QNetworkConfiguration)));
    connect(m_manager,SIGNAL(onlineStateChanged(bool)),this,SLOT(onlineStateChanged(bool)));
    //connect(m_manager,SIGNAL(updateCompleted()),this,SLOT(updateCompleted()));

    if(m_manager->defaultConfiguration().isValid()){
        m_session=new QNetworkSession(m_manager->defaultConfiguration(),this);

        connect(m_session,SIGNAL(closed()),this,SLOT(sessionClosed()));
        connect(m_session,SIGNAL(opened()),this,SLOT(sessionOpened()));
        connect(m_session,SIGNAL(error(QNetworkSession::SessionError)),this,SLOT(sessionError(QNetworkSession::SessionError)));
        connect(m_session,SIGNAL(stateChanged(QNetworkSession::State)),this,SLOT(sessionStateChanged(QNetworkSession::State)));
        connect(m_session,SIGNAL(usagePoliciesChanged(QNetworkSession::UsagePolicies)),this,SLOT(sessionUsagePoliciesChanged(QNetworkSession::UsagePolicies)));
        connect(m_session,SIGNAL(newConfigurationActivated()),this,SLOT(sessionNewConfigurationActivated()));
        connect(m_session,SIGNAL(preferredConfigurationChanged(QNetworkConfiguration,bool)),this,SLOT(sessionPreferredConfigurationChanged(QNetworkConfiguration,bool)));
        m_session->open();
    }
    return true;
}
/*                                                                                               */
void Network::configurationAdded(const QNetworkConfiguration &config)
{
    //qDebug() << "NETWORK: Configuration Added: " << config.name();
}
/*                                                                                               */
void Network::configurationChanged(const QNetworkConfiguration &config)
{
    //qDebug() << "NETWORK: Configuration Changed:" << config.name();
}
/*                                                                                               */
void Network::configurationRemoved(const QNetworkConfiguration &config)
{
    //qDebug() << "NETWORK: Configuration Removed:" << config.name();
}
/*                                                                                               */
void Network::updateCompleted()
{
    //qDebug() << "NETWORK: Update Completed";
}
/*                                                                                               */
void Network::onlineStateChanged(const bool &online)
{
    emit isOnlineChanged();
}
/*  eof                                                                                          */