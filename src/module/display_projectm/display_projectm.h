#ifndef DISPLAY_PROJECTM_H
#define DISPLAY_PROJECTM_H
/*                                                                                               */
#include "display_projectm_global.h"
#include "/development/Neon-DE/src/core/Module/ModuleInterface.h"
#include <QProcess>
/*                                                                                               */
class display_projectm: public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "ProjectM" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)

public:
    void suspend();
    void resume();

private:
    Type type(){return Display;}
    bool initialize();
    QProcess *m_process;
};
/*                                                                                               */
#endif