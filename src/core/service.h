#ifndef SERVICE_H
#define SERVICE_H
/*                                                                                               */
#include <QQmlContext>
#include <QQmlEngine>
#include <QSettings>
#include <QScreen>
#include <QDebug>
/*                                                                                               */
class Service : public QObject
{
    Q_OBJECT
public:
    Service(const QString &serviceName);
    static QQmlEngine *engine;
    static QScreen *primaryScreen;

protected:
    virtual bool configure(QSettings &settings){Q_UNUSED(settings);return true;}

private:
    static QVector<Service*> services;
};
/*                                                                                               */
#endif