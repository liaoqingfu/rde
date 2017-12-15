#ifndef WEBBROWSER_H
#define WEBBROWSER_H
/*                                                                                               */
#define URI "org.rde.webbrowser"
/*                                                                                               */
#include "webbrowser_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
#include "bookmarkmodel.h"
/*                                                                                               */
class WebBrowser: public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "WebBrowser" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)

private:
    bool initialize();
    Type type(){return Icon;}
};
/*                                                                                               */
#endif