#include "legs.h"
/*                                                                                               */
Legs::Legs()
{
    m_feet=new Feet();
}
/*                                                                                               */
void Legs::isHit(Attack *attack)
{
}
/*                                                                                               */
Legs::~Legs()
{
    delete m_feet;
}
/*                                                                                               */