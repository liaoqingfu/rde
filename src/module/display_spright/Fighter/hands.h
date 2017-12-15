#ifndef HANDS_H
#define HANDS_H
/*                                                                                               */
#include "bodypart.h"
#include "Attack/punch.h"
#include "Outfit/handwear.h"
/*                                                                                               */
class Hands:public BodyPart
{
public:
    Hands();
    ~Hands();
    HandWear *handWear()const{return m_handWear;}

private:
    HandWear *m_handWear=0;
};
/*                                                                                               */
#endif