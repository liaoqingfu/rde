#ifndef NETWORKSERVICE_H
#define NETWORKSERVICE_H
/*                                                                                               */
#include "service.h"
#include "networkconfigurationmodel.h"
#include "networkinterfacemodel.h"
#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QDebug>
/*                                                                                               */
class NetworkService : public Service
{
    Q_OBJECT
public:
    static NetworkService *instance();
    bool configure(QSettings &settings);

private:
    NetworkService();
    static NetworkService *m_instance;
    QNetworkConfigurationManager *m_configurationManager;
    QNetworkSession *m_session;

private slots:
    void configurationAdded(const QNetworkConfiguration &config);
    void configurationChanged(const QNetworkConfiguration &config);
    void configurationRemoved(const QNetworkConfiguration &config);
    void updateCompleted();
    void onlineStateChanged(const bool &online);
    void sessionOpened();
    void sessionClosed();
    void sessionError(QNetworkSession::SessionError error);
    void sessionStateChanged(QNetworkSession::State state);
    void sessionUsagePoliciesChanged(QNetworkSession::UsagePolicies policies);
    void sessionNewConfigurationActivated();
    void sessionPreferredConfigurationChanged(const QNetworkConfiguration &config,bool isSeamless);
};
/*                                                                                               */
#endif