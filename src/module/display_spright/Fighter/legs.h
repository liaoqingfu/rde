#ifndef LEGS_H
#define LEGS_H
/*                                                                                               */
#include "limbs.h"
#include "feet.h"
/*                                                                                               */
class Legs:public Limbs
{
public:
    explicit Legs();
    ~Legs();

private:
    void isHit(Attack *attack);
    Feet *m_feet;
};
/*                                                                                               */
#endif