#ifndef ARMS_H
#define ARMS_H
/*                                                                                               */
#include "limbs.h"
#include "hands.h"
/*                                                                                               */
class Arms:public Limbs
{
public:
    explicit Arms();
    ~Arms();

private:
    void isHit(Attack *attack);
    Hands *m_hands;
};
/*                                                                                               */
#endif