#include "session.h"
/*                                                                                               */
Session::Session(const QString &file,QObject *parent):QObject(parent)
{
    process=new QProcess(this);
    connect(process,SIGNAL(started()),this,SLOT(started()));
    connect(process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finished(int,QProcess::ExitStatus)));
    connect(process,SIGNAL(error(QProcess::ProcessError)),this,SLOT(error(QProcess::ProcessError)));
    connect(process,SIGNAL(readyReadStandardOutput()),this,SLOT(readOutput()));
    process->setProgram(file);

    //QStringList args;
    //args << "-window";

    //process->setArguments(args);
    //connect(process)

    //setProgram(file);
//    if(process->open(QIODevice::ReadOnly)){
//        qDebug() << "Opened";
//    }

    if(QProcess::startDetached(file));
}
/*                                                                                               */
void Session::readOutput()
{
    while(process->canReadLine()){
        QString line=process->readAllStandardOutput().constData();
        qDebug() << "Out:" << line;
    }
}
/*                                                                                               */
void Session::error(QProcess::ProcessError error)
{
    switch(error){
    case QProcess::FailedToStart:qDebug() << "Error: failed to start"; break;
    case QProcess::Crashed:qDebug() << "Error: crashed"; break;
    case QProcess::Timedout:qDebug() << "Error: timed out"; break;
    case QProcess::WriteError:qDebug() << "Error: write error"; break;
    case QProcess::ReadError:qDebug() << "Error: read error"; break;
    case QProcess::UnknownError:qDebug() << "Error: unknown"; break;
    }
}
/*                                                                                               */
void Session::started()
{
    qDebug() << "Started";
}
/*                                                                                               */
void Session::finished(const int &exitCode, QProcess::ExitStatus status)
{
    qDebug() << "Finished!";
}
/*                                                                                               */