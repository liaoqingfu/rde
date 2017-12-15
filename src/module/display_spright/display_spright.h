#ifndef DISPLAY_SPRIGHT_H
#define DISPLAY_SPRIGHT_H
/*                                                                                               */
#include "/development/Neon-DE/src/core/Module/ModuleInterface.h"
#include "display_spright_global.h"
//#include "arenaitem.h"
//#include "Fighter/fightermodel.h"
//#include "Character/charactermodel.h"
//#include "Fighter/fighteritem.h"

//#include <player.h>
//#include <QQmlComponent>
//#include <QQuickItem>
//#include <QQuickWindow>
//#include <QGuiApplication>
//#include <QScreen>
//#include "archive.h"

#include <QDebug>
#include "fightermanager.h"
/*                                                                                               */
class display_spright: public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Spright" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)

public:
    void suspend();
    void resume();
    //~display_spright();

private:
    Type type(){return Display;}
    bool initialize();

    FighterManager *m_manager;

    //QQmlComponent *m_component;
    //QQuickItem *m_item;
    //QQuickWindow *m_window;
    //Archive *m_archive;

//private slots:
    //void closeEvent(QQuickCloseEvent *event);
    //void statusChanged(QQmlComponent::Status status);
};
/*                                                                                               */
#endif