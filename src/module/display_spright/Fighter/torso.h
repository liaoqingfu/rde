#ifndef TORSO_H
#define TORSO_H
/*                                                                                               */
#include "bodypart.h"
/*                                                                                               */
class Torso : public BodyPart
{
public:
    explicit Torso();

private:
    void isHit(Attack *attack);
};
/*                                                                                               */
#endif