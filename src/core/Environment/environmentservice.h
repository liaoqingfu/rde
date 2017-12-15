#ifndef ENVIRONMENTSERVICE_H
#define ENVIRONMENTSERVICE_H
/*                                                                                               */
#include "service.h"
#include <QStandardPaths>
#include <QDir>
/*                                                                                               */
class EnvironmentService: public Service
{
    Q_OBJECT
    Q_PROPERTY(QString cache READ cache NOTIFY cacheChanged)
    Q_PROPERTY(QString genericCache READ genericCache NOTIFY genericCacheChanged)
    Q_PROPERTY(QString config READ config NOTIFY configChanged)
    Q_PROPERTY(QString genericConfig READ genericConfig NOTIFY genericConfigChanged)
    Q_PROPERTY(QString data READ data NOTIFY dataChanged)
    Q_PROPERTY(QString genericData READ genericData NOTIFY genericDataChanged)
    Q_PROPERTY(QString appData READ appData NOTIFY appDataChanged)
    Q_PROPERTY(QString appLocalData READ appLocalData NOTIFY appLocalDataChanged)
    Q_PROPERTY(QString appConfig READ appConfig NOTIFY appConfigChanged)
    Q_PROPERTY(QString temp READ temp NOTIFY tempChanged)
    Q_PROPERTY(QString applications READ applications NOTIFY applicationsChanged)
    Q_PROPERTY(QString fonts READ fonts NOTIFY fontsChanged)

public:
    static EnvironmentService *instance();

private:
    EnvironmentService();
    static EnvironmentService *m_instance;
    bool exists(QStringList list);

    QString cache(){return QStandardPaths::standardLocations(QStandardPaths::CacheLocation).join(";");}
    QString genericCache(){return QStandardPaths::standardLocations(QStandardPaths::GenericCacheLocation).join(";");}
    QString config(){return QStandardPaths::standardLocations(QStandardPaths::ConfigLocation).join(";");}
    QString genericConfig(){return QStandardPaths::standardLocations(QStandardPaths::GenericConfigLocation).join(";");}
    QString data(){return QStandardPaths::standardLocations(QStandardPaths::DataLocation).join(";");}
    QString genericData(){return QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation).join(";");}

    QString appData(){return QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).join(";");}
    QString appLocalData(){return QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation).join(";");}
    QString appConfig(){return QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation).join(";");}

    QString temp(){return QStandardPaths::standardLocations(QStandardPaths::TempLocation).join(";");}
    QString applications(){return QStandardPaths::standardLocations(QStandardPaths::ApplicationsLocation).join(";");}
    QString fonts(){return QStandardPaths::standardLocations(QStandardPaths::FontsLocation).join(";");}

signals:
    void cacheChanged();
    void genericCacheChanged();
    void configChanged();
    void genericConfigChanged();
    void dataChanged();
    void genericDataChanged();
    void appDataChanged();
    void appLocalDataChanged();
    void appConfigChanged();
    void tempChanged();
    void applicationsChanged();
    void fontsChanged();
};
/*                                                                                               */
#endif