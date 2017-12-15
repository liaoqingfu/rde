#include "security.h"
/*                                                                                               */
bool Security::initialize()
{
    m_clam=Clam::instance();
    qmlRegisterType<Window>(URI,1,0,"SecurityWindow");
    return true;
}
/*                                                                                               */