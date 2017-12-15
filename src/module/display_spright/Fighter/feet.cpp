#include "feet.h"
/*                                                                                               */
Feet::Feet()
{
}
/*                                                                                               */
Feet::~Feet()
{
    if(m_footWear)
        delete m_footWear;
}
/*                                                                                               */