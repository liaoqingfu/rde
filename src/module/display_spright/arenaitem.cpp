#include "arenaitem.h"
/*                                                                                               */
ArenaItem::ArenaItem()
{
    Fighter::m_arena=this;
}
/*                                                                                               */
void ArenaItem::componentComplete()
{
    QQuickItem::componentComplete();

    // nothing to do? ...
}
/*                                                                                               */
void ArenaItem::addFighter(QString name)
{
    Fighter *f=new Fighter(name);
}
/*                                                                                               */
ArenaItem::~ArenaItem()
{
    foreach(Fighter *fighter,Fighter::fighters)
        fighter->deleteLater();
    Fighter::fighters.clear();
}
/*                                                                                               */