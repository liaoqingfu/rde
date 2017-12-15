#ifndef MODULE_H
#define MODULE_H
/*                                                                                               */
#include "service.h"
#include "ModuleInterface.h"
#include "moduledockitem.h"
#include "UI/traymodel.h"
#include <QPluginLoader>
#include <QQuickItem>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QResource>
#include <QFileInfo>
/*                                                                                               */
class TrayModel;
/*                                                                                               */
class Module : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("Author", "Ralf Van Bogaert")

public:
    explicit Module(const QString &path,QObject *parent);
    QString filePath()const{return m_loader->fileName();}
    QString iid()const{return m_iid;}
    QString description()const{return m_description;}
    QString version()const{return m_version;}
    QString icon()const{return m_icon;}
    bool isLoaded()const{return m_loader->isLoaded();}
    QQmlContext *context(){return m_interface->context;}
    bool load();
    bool unload();
    bool createUserInterface();

    static QVector<Module*> vector;

private:
    QString m_iid;
    QString m_description;
    QString m_version;
    QString m_icon;
    QPluginLoader *m_loader;
    QQmlComponent *m_component;
    QObject *m_instance;
    ModuleDockItem *m_moduleDockItem;
    //QQuickItem *trayIcon;
    ModuleInterface *m_interface;

private slots:
    void dockItemStatusChanged(QQmlComponent::Status status);
};
/*                                                                                               */
#endif
