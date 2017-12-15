#include "arms.h"
/*                                                                                               */
Arms::Arms()
{
    m_hands=new Hands();
}
/*                                                                                               */
void Arms::isHit(Attack *attack)
{
}
/*                                                                                               */
Arms::~Arms()
{
    delete m_hands;
}
/*                                                                                               */