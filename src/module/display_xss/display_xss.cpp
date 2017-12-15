#include "display_xss.h"
/*                                                                                               */
bool display_xss::initialize()
{

    m_path="/usr/lib/xscreensaver";
    QStringList args;
    args << "--root";
    m_process=new QProcess(this);
    m_process->setProgram(m_path+"/hyperspace");
    m_process->setArguments(args);
    resume();
    return true;
}
/*                                                                                               */
void display_xss::suspend()
{
    m_process->kill();
}
/*                                                                                               */
void display_xss::resume()
{
    m_process->start();
}
/*                                                                                               */