#ifndef ATTACK_H
#define ATTACK_H
/*                                                                                               */
#include "Element/element.h"
/*                                                                                               */
class Attack
{
public:
    Attack(Element *element=nullptr);
    virtual ~Attack();
    int force()const{return m_force;}

protected:
    int m_force=10;
};
/*                                                                                               */
#endif