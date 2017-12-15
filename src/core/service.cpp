#include "service.h"
/*                                                                                               */
Service::Service(const QString &serviceName):QObject()
{
    Q_UNUSED(serviceName);
    Service::services.append(this);
}
/*                                                                                               */
QQmlEngine *Service::engine;
QScreen *Service::primaryScreen;
QVector<Service*> Service::services;