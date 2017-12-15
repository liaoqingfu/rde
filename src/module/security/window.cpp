#include "window.h"
/*                                                                                               */
Window::Window()
{
}
/*                                                                                               */
bool Window::clamReady()
{
    Clam::instance()->isReady();
}
/*                                                                                               */