#include "cdripper.h"
/*                                                                                               */
CDRipper::CDRipper(QObject *parent) : QObject(parent)
{
    tempPath="/download/cdrip";
    //connect(m_process,SIGNAL(started()),this,SLOT(startQuery()));


    //m_process->setWorkingDirectory(tempPath);

    m_process=new QProcess(this);

    connect(m_process,SIGNAL(readyReadStandardOutput()),this,SLOT(readOutput()));
    connect(m_process,SIGNAL(error(QProcess::ProcessError)),this,SLOT(error(QProcess::ProcessError)));
    connect(m_process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finished(int,QProcess::ExitStatus)));
    m_process->setProgram("cdparanoia");
    m_process->setProcessChannelMode(QProcess::MergedChannels);
    m_process->setArguments(QStringList("-B"));

    m_process->open();
}
/*                                                                                               */
void CDRipper::readOutput()
{
    while(m_process->canReadLine()){
        qDebug() << m_process->readLine().constData();
    }
}
/*                                                                                               */
void CDRipper::error(QProcess::ProcessError error)
{
    switch(error){
    case QProcess::FailedToStart:return; //break
    case QProcess::Crashed:return;
    case QProcess::Timedout:return;
    case QProcess::WriteError:return;
    case QProcess::ReadError:return;
    case QProcess::UnknownError:return;
    }
}
/*                                                                                               */
void CDRipper::finished(int exitCode, QProcess::ExitStatus status)
{
    qDebug() << "Finished ripping!";
}
/*                                                                                               */