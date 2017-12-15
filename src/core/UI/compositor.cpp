#include "compositor.h"
/*                                                                                               */
Compositor::Compositor():QObject()
{
    Service::engine->rootContext()->setContextProperty("Compositor",this);
    m_process=new QProcess(this);
    connect(m_process,SIGNAL(started()),this,SLOT(started()));
    connect(m_process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finished(int,QProcess::ExitStatus)));
    m_process->setProgram("compton");
    setEnabled(true);
}
/*                                                                                               */
void Compositor::setEnabled(const bool &enabled)
{
    if(m_enabled!=enabled){
        if(enabled)
            start();
        else
            stop();
    }
}
/*                                                                                               */
void Compositor::start()
{
    //if(m_process->open(QIODevice::ReadOnly));
}
/*                                                                                               */
void Compositor::started()
{
    m_enabled=true;
    emit enabledChanged();
}
/*                                                                                               */
void Compositor::stop()
{
//    if(m_process && m_process->isOpen())
//        m_process->close();
}
/*                                                                                               */
void Compositor::finished(int exitCode,QProcess::ExitStatus status)
{
    switch(status){
    case QProcess::NormalExit:break;
    case QProcess::CrashExit:break;
    }

    m_enabled=false;
    emit enabledChanged();
}
/*                                                                                               */
Compositor *Compositor::m_instance;
Compositor *Compositor::instance(){if(!m_instance)m_instance=new Compositor;return m_instance;}