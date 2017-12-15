#ifndef UNIT_H
#define UNIT_H
/*                                                                                               */
#include "fighter.h"
/*                                                                                               */
class Unit
{
public:
    Unit();
    QVector<Fighter*> members(){return m_members;}
    Fighter *leader(){return m_leader;}

private:
    QVector<Fighter*> m_members;
    Fighter *m_leader;
};
/*                                                                                               */
#endif