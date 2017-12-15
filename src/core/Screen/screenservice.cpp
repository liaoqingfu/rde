#include "screenservice.h"
/*                                                                                               */
ScreenService::ScreenService():Service("Screen")
{
    qmlRegisterType<ScreenModel>("org.rde.screen",1,0,"ScreenModel");
}
/*                                                                                               */
bool ScreenService::configure(QSettings &settings)
{
    return true;
}
/*                                                                                               */
void ScreenService::screenAdded(QScreen *screen)
{
}
/*                                                                                               */
void ScreenService::screenRemoved(QScreen *screen)
{
}
/*                                                                                               */
void ScreenService::primaryScreenChanged(QScreen *screen)
{
}
/*                                                                                               */
ScreenService* ScreenService::m_instance;
ScreenService* ScreenService::instance(){if(!m_instance)m_instance=new ScreenService;return m_instance;}