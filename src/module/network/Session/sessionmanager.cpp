#include "sessionmanager.h"
/*                                                                                               */
SessionManager::SessionManager():QObject()
{
}
/*                                                                                               */
void SessionManager::createSession(const QNetworkConfiguration &conf)
{
    m_session=new QNetworkSession(conf,this);
    //connect(m_session,SIGNAL(closed()),this,SIGNAL(closed()));
    //connect(m_session,SIGNAL(opened()),this,SIGNAL(opened()));
    connect(m_session,SIGNAL(error(QNetworkSession::SessionError)),this,SLOT(sessionError(QNetworkSession::SessionError)));
    connect(m_session,SIGNAL(newConfigurationActivated()),this,SLOT(newConfigurationActivated()));
    connect(m_session,SIGNAL(stateChanged(QNetworkSession::State)),this,SLOT(stateChanged(QNetworkSession::State)));
    connect(m_session,SIGNAL(preferredConfigurationChanged(QNetworkConfiguration,bool)),this,SLOT(preferredConfigurationChanged(QNetworkConfiguration,bool)));
    connect(m_session,SIGNAL(usagePoliciesChanged(QNetworkSession::UsagePolicies)),this,SLOT(usagePoliciesChanged(QNetworkSession::UsagePolicies)));
    m_session->open();
}
/*                                                                                               */
void SessionManager::sessionError(QNetworkSession::SessionError error)
{
    switch(error){
    case QNetworkSession::UnknownSessionError:

        break;
    case QNetworkSession::SessionAbortedError:

        break;
    case QNetworkSession::RoamingError:

        break;
    case QNetworkSession::OperationNotSupportedError:

        break;
    case QNetworkSession::InvalidConfigurationError:

        break;
    }
}
/*                                                                                               */
void SessionManager::stateChanged(QNetworkSession::State state)
{
    switch(state){
    case QNetworkSession::Invalid:

        break;
    case QNetworkSession::NotAvailable:

        break;
    case QNetworkSession::Connecting:

        //emit connecting();
        break;
    case QNetworkSession::Connected:

        //emit connected();
        break;
    case QNetworkSession::Closing:

        break;
    case QNetworkSession::Disconnected:
        //emit disconnected();
        break;
    case QNetworkSession::Roaming:

        break;
    }
}
/*                                                                                               */
void SessionManager::newConfigurationActivated()
{
}
/*                                                                                               */
void SessionManager::preferredConfigurationChanged(QNetworkConfiguration conf,bool isSeamless)
{
}
/*                                                                                               */
void SessionManager::usagePoliciesChanged(QNetworkSession::UsagePolicies policies)
{
    switch(policies){
    case QNetworkSession::NoPolicy:

        break;
    case QNetworkSession::NoBackgroundTrafficPolicy:

        break;
    }
}
/* static                                                                                        */
SessionManager *SessionManager::m_instance;
SessionManager *SessionManager::getInstance(){if(!m_instance)m_instance=new SessionManager;return m_instance;}