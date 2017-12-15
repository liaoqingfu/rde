#include "launcher.h"
/*                                                                                               */
bool Launcher::initialize()
{
    qmlRegisterType<DesktopFilesModel>("org.rde.launcher",1,0,"DesktopFilesModel");
    return true;
}
/*                                                                                               */