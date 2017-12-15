#ifndef BODYPART_H
#define BODYPART_H
/*                                                                                               */
#include "Attack/attack.h"
//#include "Fighter/fighter.h"
/*                                                                                               */
class BodyPart
{
public:
    explicit BodyPart();
    virtual ~BodyPart(){}
    virtual void isHit(Attack *attack);
    int defense()const{return m_defense;}
protected:
    int m_defense;
    //Fighter *m_fighter;
};
/*                                                                                               */
#endif