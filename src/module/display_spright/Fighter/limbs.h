#ifndef LIMBS_H
#define LIMBS_H
/*                                                                                               */
#include "bodypart.h"
/*                                                                                               */
class Limbs:public BodyPart
{
public:
    //Limb(BodySide aside);
    Limbs();
    virtual ~Limbs(){}
    enum BodySide{Left,Right};
    BodySide side(){return m_side;}

protected:
    BodySide m_side;
};
/*                                                                                               */
#endif