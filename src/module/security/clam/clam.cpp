#include "clam.h"
/*                                                                                               */
Clam::Clam()
{
    QString e=QStandardPaths::findExecutable(Program);
    if(!e.isEmpty()){
        m_process=new QProcess(this);
        connect(m_process,SIGNAL(started()),this,SLOT(started()));
        connect(m_process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finished(int,QProcess::ExitStatus)));
        connect(m_process,SIGNAL(readyReadStandardError()),this,SLOT(readError()));
        connect(m_process,SIGNAL(readyReadStandardOutput()),this,SLOT(readOutput()));
        m_process->setProgram(Program);
        m_watcher=new QFileSystemWatcher(this);
        connect(m_watcher,SIGNAL(fileChanged(QString)),this,SLOT(fileChanged(QString)));
        m_watcher->addPath(e);
        m_ready=true;
    }
    else
        qDebug() << "Unable to find clamscan, install the Clam package please";
}
/*                                                                                               */
void Clam::scan(const QString &dir)
{
    m_process->setArguments(QStringList() << "-r" << dir);
    if(m_process->open(QProcess::ReadOnly)){
        qDebug() << "Clamscan opened!";
    }
}
/*                                                                                               */
void Clam::fileChanged(QString file)
{
    qDebug() << "Clam: " << file << "has changed!";
}
/*                                                                                               */
void Clam::started()
{
    qDebug() << "Clamscan started";
}
/*                                                                                               */
void Clam::readError()
{
    QString line=m_process->readAllStandardError();

    //qDebug() << "CLAM ERROR:" << line;
}
/*                                                                                               */
void Clam::readOutput()
{
    QString line=m_process->readLine().constData();
    line.chop(1);
    //qDebug() << "CLAM:" << line;
}
/*                                                                                               */
void Clam::finished(const int &exitCode, QProcess::ExitStatus status)
{
}
/*                                                                                               */
Clam *Clam::m_instance;
Clam *Clam::instance(){if(!m_instance)m_instance=new Clam();return m_instance;}