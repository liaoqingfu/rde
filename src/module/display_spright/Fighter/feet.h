#ifndef FEET_H
#define FEET_H
/*                                                                                               */
#include "bodypart.h"
#include "Outfit/footwear.h"
/*                                                                                               */
class Feet:public BodyPart
{
public:
    explicit Feet();
    ~Feet();
    FootWear *footWear()const{return m_footWear;}

private:
    FootWear *m_footWear=0;
};
/*                                                                                               */
#endif