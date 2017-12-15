#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H
/*                                                                                               */
#include <QNetworkSession>
/*                                                                                               */
class SessionManager : public QObject
{
    Q_OBJECT
public:
    static SessionManager *getInstance();
    void createSession(const QNetworkConfiguration &conf);
private:
    static SessionManager *m_instance;
    SessionManager();
    QNetworkSession *m_session;
private slots:
    void sessionClosed();
    void sessionError(QNetworkSession::SessionError error);
    void newConfigurationActivated();
    void stateChanged(QNetworkSession::State state);
    void preferredConfigurationChanged(QNetworkConfiguration conf,bool isSeamless);
    void usagePoliciesChanged(QNetworkSession::UsagePolicies policies);
};
/*                                                                                               */
#endif