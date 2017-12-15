#ifndef NETWORK_H
#define NETWORK_H
/*                                                                                               */
#include "network_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"

#include "Configuration/configurationmodel.h"
#include "Interface/interfacemodel.h"

#include <QNetworkConfigurationManager>
#include <QNetworkSession>
/*                                                                                               */
class Network: public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Network" FILE "metadata.json")
    Q_PROPERTY(bool isOnline READ isOnline NOTIFY isOnlineChanged)
    Q_INTERFACES(ModuleInterface)

private:
    bool initialize();
    UI ui(){return Dock;}
    QNetworkConfigurationManager *m_manager;
    QNetworkSession *m_session;
    bool isOnline()const{return m_manager->isOnline();}

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

signals:
    void isOnlineChanged();
};
/*                                                                                               */
#endif
