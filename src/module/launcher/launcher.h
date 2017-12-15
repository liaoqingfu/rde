#ifndef LAUNCHER_H
#define LAUNCHER_H
/*                                                                                               */
#include "launcher_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
#include "desktopfilesmodel.h"
/*                                                                                               */
class Launcher:public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Launcher" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)

private:
    Type type(){return Dock;}
    bool initialize();
};
/*                                                                                               */
#endif