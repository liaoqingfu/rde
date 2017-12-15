#ifndef DISPLAY_XSS_H
#define DISPLAY_XSS_H
/*                                                                                               */
#include "display_xss_global.h"
#include "/development/Neon-DE/src/core/Display/DisplayInterface.h"
#include <QProcess>
/*                                                                                               */
class display_xss: public QObject,public DisplayInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "XScreenSaver" FILE "metadata.json")
    Q_INTERFACES(DisplayInterface)

public:
    void suspend();
    void resume();

private:
    bool initialize();
    QProcess *m_process;
    QString m_path;
};
/*                                                                                               */
#endif