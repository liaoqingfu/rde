#include "unit.h"
/*                                                                                               */
Unit::Unit()
{
}
/*                                                                                               */
void Unit::addMember(Fighter *fighter)
{
    m_members.append(fighter);
}
/*                                                                                               */
void Unit::removeMember(Fighter *fighter)
{
    m_members.removeAll(fighter);
}
/*                                                                                               */