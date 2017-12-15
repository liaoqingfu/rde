#include "dock.h"
/*                                                                                               */
Dock::Dock():BaseWindow("/rde/Dock.qml")
{
    setFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::BypassWindowManagerHint|Qt::BypassGraphicsProxyWidget);
    setTitle("rde-Dock");
    Service::engine->rootContext()->setContextProperty("Dock",this);
}
/*                                                                                               */
void Dock::ready()
{
    //column=m_item->childItems().at(0);
    column=m_item;
}
/*                                                                                               */
Dock* Dock::m_instance;
Dock* Dock::instance(){if(!m_instance)m_instance=new Dock;return m_instance;}
QQuickItem *Dock::column;