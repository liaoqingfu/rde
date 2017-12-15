#ifndef CONSOLE_H
#define CONSOLE_H
/*                                                                                               */
#include "console_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
/*                                                                                               */
class Console:public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Console" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)

public:
    Type type(){return Dock;}

public slots:

private:
    bool initialize();
};
/*                                                                                               */
#endif