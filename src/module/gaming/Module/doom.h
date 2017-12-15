#ifndef DOOM_H
#define DOOM_H
/*                                                                                               */
#include "module.h"
/*                                                                                               */
class Doom : public Module
{
    Q_OBJECT

public:
    static Doom *instance();
    QStringList importData();
    QStringList arguments(const QString &game);

private:
    static Doom *m_instance;
    explicit Doom();
};
/*                                                                                               */
#endif