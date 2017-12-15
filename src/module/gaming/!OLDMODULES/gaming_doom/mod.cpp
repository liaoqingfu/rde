#include "mod.h"
/*                                                                                               */
Mod::Mod(const QString &file):File(file)
{
    mods.append(this);
}
/*                                                                                               */
QVector<Mod*> Mod::mods;