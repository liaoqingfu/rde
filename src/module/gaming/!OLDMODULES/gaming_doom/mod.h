#ifndef MOD_H
#define MOD_H
/*                                                                                               */
#include "file.h"
/*                                                                                               */
class Mod:public File
{
public:
    Mod(const QString &file);
    static QVector<Mod*> mods;
};
/*                                                                                               */
#endif