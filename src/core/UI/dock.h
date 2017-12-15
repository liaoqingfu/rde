#ifndef DOCK_H
#define DOCK_H
/*                                                                                               */
#include "basewindow.h"
#include "service.h"
/*                                                                                               */
class Dock : public BaseWindow
{
    Q_OBJECT
public:
    static Dock *instance();
    static QQuickItem *column;

private:
    Dock();
    static Dock *m_instance;
    void ready();
};
/*                                                                                               */
#endif