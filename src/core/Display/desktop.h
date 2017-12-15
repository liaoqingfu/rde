#ifndef DESKTOP_H
#define DESKTOP_H
/*                                                                                               */
#include "UI/basewindow.h"
#include "service.h"
#include <QGuiApplication>
/*                                                                                               */
class Desktop : public BaseWindow
{
public:
    static Desktop *instance();

private:
    Desktop();
    static Desktop *m_instance;
    void ready();
};
/*                                                                                               */
#endif