#include "networkservice.h"
/*                                                                                               */
NetworkService ::NetworkService():Service("Network")
{
    //Service::engine->rootContext()->setContextProperty("Network",this);
    qmlRegisterType<NetworkConfigurationModel>("org.rde.network",1,0,"ConfigurationModel");
    qmlRegisterType<NetworkInterfaceModel>("org.rde.network",1,0,"InterfaceModel");


    m_configurationManager=new QNetworkConfigurationManager(this);



    connect(m_configurationManager,SIGNAL(configurationAdded(QNetworkConfiguration)),this,SLOT(configurationAdded(QNetworkConfiguration)));
    connect(m_configurationManager,SIGNAL(configurationChanged(QNetworkConfiguration)),this,SLOT(configurationChanged(QNetworkConfiguration)));
    connect(m_configurationManager,SIGNAL(configurationRemoved(QNetworkConfiguration)),this,SLOT(configurationRemoved(QNetworkConfiguration)));
    connect(m_configurationManager,SIGNAL(onlineStateChanged(bool)),this,SLOT(onlineStateChanged(bool)));
    //connect(m_manager,SIGNAL(updateCompleted()),this,SLOT(updateCompleted()));

    if(m_configurationManager->defaultConfiguration().isValid()){
        m_session=new QNetworkSession(m_configurationManager->defaultConfiguration(),this);

        connect(m_session,SIGNAL(closed()),this,SLOT(sessionClosed()));
        connect(m_session,SIGNAL(opened()),this,SLOT(sessionOpened()));
        connect(m_session,SIGNAL(error(QNetworkSession::SessionError)),this,SLOT(sessionError(QNetworkSession::SessionError)));
        connect(m_session,SIGNAL(stateChanged(QNetworkSession::State)),this,SLOT(sessionStateChanged(QNetworkSession::State)));
        connect(m_session,SIGNAL(usagePoliciesChanged(QNetworkSession::UsagePolicies)),this,SLOT(sessionUsagePoliciesChanged(QNetworkSession::UsagePolicies)));
        connect(m_session,SIGNAL(newConfigurationActivated()),this,SLOT(sessionNewConfigurationActivated()));
        connect(m_session,SIGNAL(preferredConfigurationChanged(QNetworkConfiguration,bool)),this,SLOT(sessionPreferredConfigurationChanged(QNetworkConfiguration,bool)));
        m_session->open();
    }

    //qmlRegisterType<NetworkModel>("org.rde.Network",1,0,"NetworkModel");
}
/*                                                                                               */
bool NetworkService::configure(QSettings &settings)
{
    Q_UNUSED(settings)
    return true;
}
/*                                                                                               */
void NetworkService::configurationAdded(const QNetworkConfiguration &config)
{
    Q_UNUSED(config)
    //qDebug() << "NETWORK: Configuration Added: " << config.name();
}
/*                                                                                               */
void NetworkService::configurationChanged(const QNetworkConfiguration &config)
{
    Q_UNUSED(config)
    //qDebug() << "NETWORK: Configuration Changed:" << config.name();
}
/*                                                                                               */
void NetworkService::configurationRemoved(const QNetworkConfiguration &config)
{
    //qDebug() << "NETWORK: Configuration Removed:" << config.name();
}
/*                                                                                               */
void NetworkService::updateCompleted()
{
    //qDebug() << "NETWORK: Update Completed";
}
/*                                                                                               */
void NetworkService::onlineStateChanged(const bool &online)
{
    //emit isOnlineChanged();
}
/*                                                                                               */
void NetworkService::sessionOpened()
{
    //qDebug() << "NETWORK: Session opened";
}
/*                                                                                               */
void NetworkService::sessionClosed()
{
    //qDebug() << "NETWORK: Session closed";
}
/*                                                                                               */
void NetworkService::sessionError(QNetworkSession::SessionError error)
{
    switch(error){
    case QNetworkSession::UnknownSessionError:
        qDebug() << "NETWORK: Error: Unknown session:" << m_session->errorString();
        break;
    case QNetworkSession::SessionAbortedError:
        qDebug() << "NETWORK: Error: Session aborted:" << m_session->errorString();
        break;
    case QNetworkSession::RoamingError:
        qDebug() << "NETWORK: Error: Roaming:" << m_session->errorString();
        break;
    case QNetworkSession::OperationNotSupportedError:
        qDebug() << "NETWORK: Error: Operation not supported:" << m_session->errorString();
        break;
    case QNetworkSession::InvalidConfigurationError:
        qDebug() << "NETWORK: Error: Invalid configuration:" << m_session->errorString();
        break;
    }
}
/*                                                                                               */
void NetworkService::sessionStateChanged(QNetworkSession::State state)
{
    switch(state){
    case QNetworkSession::Invalid:
        qDebug() << "NETWORK: State: Invalid";
        break;
    case QNetworkSession::NotAvailable:
        qDebug() << "NETWORK: State: Not available";
        break;
    case QNetworkSession::Connecting:
        qDebug() << "NETWORK: State: Connecting";
        break;
    case QNetworkSession::Connected:
        qDebug() << "NETWORK: State: Connected";
        break;
    case QNetworkSession::Closing:
        qDebug() << "NETWORK: State: Closing";
        break;
    case QNetworkSession::Disconnected:
        qDebug() << "NETWORK: State: Disconnecting";
        break;
    case QNetworkSession::Roaming:
        qDebug() << "NETWORK: State: Roaming";
        break;
    }
}
/*                                                                                               */
void NetworkService::sessionUsagePoliciesChanged(QNetworkSession::UsagePolicies policies)
{
    switch(policies){
    case QNetworkSession::NoPolicy:
        qDebug() << "NETWORK: Usage policy: None";
        break;
    case QNetworkSession::NoBackgroundTrafficPolicy:
        qDebug() << "NETWORK: Usage policy: No background traffic";
        break;
    }
}
/*                                                                                               */
void NetworkService::sessionPreferredConfigurationChanged(const QNetworkConfiguration &config, bool isSeamless)
{
    qDebug() << "Network: Preferred configuration changed to " << config.name();
}
/*                                                                                               */
void NetworkService::sessionNewConfigurationActivated()
{
}
/*                                                                                               */
NetworkService* NetworkService::m_instance;
NetworkService* NetworkService::instance(){if(!m_instance)m_instance=new NetworkService;return m_instance;}