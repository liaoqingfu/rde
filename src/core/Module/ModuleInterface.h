#ifndef MODULEINTERFACE_H
#define MODULEINTERFACE_H
#define Plugin_iid "org.rde.interface"
/*                                                                                               */
#include <QtPlugin>
#include <QtQml>
#include <QQmlContext>
#include <QQuickImageProvider>
#include <QSettings>
/*                                                                                               */
class ModuleInterface
{
public:
    enum Type{Dock,Display,Icon,Configure};
    virtual Type type()=0;
    virtual bool initialize()=0;
    QQmlContext *context;
    QSettings *settings;
};
/*                                                                                               */
Q_DECLARE_INTERFACE(ModuleInterface,Plugin_iid)
#endif