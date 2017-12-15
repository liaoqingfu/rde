#include "desktop.h"
/*                                                                                               */
Desktop::Desktop():BaseWindow("/rde/Desktop.qml")
{
    setTitle("RDE-Desktop");
    setColor(Qt::black);
    setFlags(Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint|Qt::WindowStaysOnBottomHint|Qt::WindowDoesNotAcceptFocus|Qt::WindowTransparentForInput);//Qt::BypassWindowManagerHint
    //Service::engine->rootContext()->setContextProperty("DesktopRoot",contentItem());
    setGeometry(qGuiApp->primaryScreen()->geometry());
    showNormal();
}
/*                                                                                               */
void Desktop::ready()
{
}
/*                                                                                               */
Desktop* Desktop::m_instance;
Desktop* Desktop::instance(){if(!m_instance)m_instance=new Desktop;return m_instance;}