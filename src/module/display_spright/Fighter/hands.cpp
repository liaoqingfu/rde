#include "hands.h"
/*                                                                                               */
Hands::Hands()
{
}
/*                                                                                               */
Hands::~Hands()
{
    if(m_handWear)
        delete m_handWear;
}
/*                                                                                               */