#ifndef HEAD_H
#define HEAD_H
/*                                                                                               */
#include "bodypart.h"
#include "Outfit/headwear.h"
#include <QDebug>
/*                                                                                               */
class Head:public BodyPart
{
public:
    explicit Head();
    ~Head();
    HeadWear *headWear()const{return m_headWear;}

private:
    void isHit(Attack *attack);
    HeadWear *m_headWear=NULL;
};
/*                                                                                               */
#endif