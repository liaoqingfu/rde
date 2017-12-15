#include "display_projectm.h"
/*                                                                                               */
bool display_projectm::initialize()
{
    m_process=new QProcess(this);
    m_process->setProgram("projectM-pulseaudio");
    resume();
    return true;
}
/*                                                                                               */
void display_projectm::suspend()
{
    m_process->kill();
}
/*                                                                                               */
void display_projectm::resume()
{
    m_process->start();
}
/*                                                                                               */