#include "screensaver.h"
/*                                                                                               */
bool ScreenSaver::initialize()
{
    model=new ScreensaverModel(this);

    context->parentContext()->setContextProperty("Screensaver",this);
    context->parentContext()->setContextProperty("ScreensaverModel",model);


    process=new QProcess(this);
    process->setProgram(QStandardPaths::findExecutable("xscreensaver"));
    connect(process,SIGNAL(started()),this,SLOT(started()));
    connect(process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finished(int,QProcess::ExitStatus)));
    connect(process,SIGNAL(readyReadStandardError()),this,SLOT(readError()));
    connect(process,SIGNAL(readyReadStandardOutput()),this,SLOT(readOutput()));
    connect(process,SIGNAL(error(QProcess::ProcessError)),this,SLOT(error(QProcess::ProcessError)));

    QStringList args;
    args << "-no-splash";
    process->setArguments(args);

    return process->open(QProcess::ReadOnly);
}
/*                                                                                               */
void ScreenSaver::started()
{
}
/*                                                                                               */
void ScreenSaver::finished(const int &exitCode, QProcess::ExitStatus status)
{
    switch(status){
    case QProcess::NormalExit:
        //qDebug() << "Screensaver exited with code " << exitCode;
        break;
    case QProcess::CrashExit:
        //qDebug() << "Screensaver crashed!!";
        break;
    }
}
/*                                                                                               */
void ScreenSaver::error(QProcess::ProcessError error)
{
    switch(error){
    case QProcess::FailedToStart:break;
    case QProcess::Crashed:break;
    case QProcess::Timedout:break;
    case QProcess::ReadError:break;
    case QProcess::WriteError:break;
    case QProcess::UnknownError:break;
    }
}
/*                                                                                               */
void ScreenSaver::readError()
{
    //qDebug() << "Screensaver error:" << process->readAllStandardError();
}
/*                                                                                               */
void ScreenSaver::readOutput()
{
    while(process->canReadLine()){
        QString line=process->readLine().constData();
        //qDebug() << "Screensaver output:" << line;
    }
}
/*                                                                                               */
void ScreenSaver::demo()
{
    sendCommand("-demo");
}
/*                                                                                               */
void ScreenSaver::activate()
{
    sendCommand("-activate");
}
/*                                                                                               */
void ScreenSaver::deactivate()
{
    sendCommand("-deactivate");
}
/*                                                                                               */
void ScreenSaver::prefs()
{
    sendCommand("-prefs");
}
/*                                                                                               */
void ScreenSaver::cycle()
{
    sendCommand("-cycle");
}
/*                                                                                               */
void ScreenSaver::next()
{
    sendCommand("-next");
}
/*                                                                                               */
void ScreenSaver::prev()
{
    sendCommand("-prev");
}
/*                                                                                               */
void ScreenSaver::select(const int &number)
{
    sendCommand("-select "+number);
}
/*                                                                                               */
void ScreenSaver::exit()
{
    sendCommand("-exit");
}
/*                                                                                               */
void ScreenSaver::restart()
{
    sendCommand("-restart");
}
/*                                                                                               */
void ScreenSaver::lock()
{
    sendCommand("-lock");
}
/*                                                                                               */
void ScreenSaver::version()
{
    sendCommand("-version");
}
/*                                                                                               */
void ScreenSaver::time()
{
    sendCommand("-time");
}
/*                                                                                               */
void ScreenSaver::watch()
{
    sendCommand("-watch");
}
/*                                                                                               */
void ScreenSaver::sendCommand(const QString &cmd)
{
    QProcess cmdProc;
    cmdProc.start("xscreensaver-command",QStringList() << cmd);
    cmdProc.waitForFinished();
}
/*                                                                                               */