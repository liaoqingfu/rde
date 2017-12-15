#ifndef SCREENSAVER_H
#define SCREENSAVER_H
/*                                                                                               */
#include "screensaver_global.h"
#include "/development/Neon-DE/src/core/Module/ModuleInterface.h"
#include <QProcess>
#include <QStandardPaths>
#include "screensavermodel.h"
/*                                                                                               */
class ScreenSaver: public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Screensaver" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)

private:
    bool initialize();
    Type type(){return Display;}
    QProcess *process;
    void sendCommand(const QString &cmd);
    ScreensaverModel *model;

private slots:
    void error(QProcess::ProcessError error);
    void readError();
    void readOutput();
    void started();
    void finished(const int &exitCode,QProcess::ExitStatus status);

public slots:
    void demo();
    void activate();
    void deactivate();
    void prefs();
    void cycle();
    void next();
    void prev();
    void select(const int &number);
    void exit();
    void restart();
    void lock();
    void version();
    void time();
    void watch();
};
/*                                                                                               */
#endif
