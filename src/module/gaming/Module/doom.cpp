#include "doom.h"
/*                                                                                               */
Doom::Doom():Module("doom")
{
}
/*                                                                                               */
QStringList Doom::importData()
{
    QStringList l;

    return l;
}
/*                                                                                               */
QStringList Doom::arguments(const QString &game)
{
    QStringList l;

    return l;
}
/*                                                                                               */
Doom *Doom::m_instance;
Doom *Doom::instance(){if(!m_instance)m_instance=new Doom();return m_instance;}