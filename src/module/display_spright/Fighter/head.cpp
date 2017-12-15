#include "head.h"
/*                                                                                               */
Head::Head():BodyPart()
{
}
/*                                                                                               */
void Head::isHit(Attack *attack)
{
}
/*                                                                                               */
Head::~Head()
{
    if(m_headWear)
        delete m_headWear;
}
/*                                                                                               */