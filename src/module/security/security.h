#ifndef SECURITY_H
#define SECURITY_H
/*                                                                                               */
#define URI "org.rde.security"
/*                                                                                               */
#include "security_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
#include "clam/clam.h"
#include "window.h"
/*                                                                                               */
class Security:public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Security" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)

private:
    bool initialize();
    Clam *m_clam;
    Type type(){return Icon;}
};
/*                                                                                               */
#endif