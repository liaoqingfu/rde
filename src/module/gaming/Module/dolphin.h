#ifndef DOLPHIN_H
#define DOLPHIN_H
/*                                                                                               */
#include "module.h"
/*                                                                                               */
class Dolphin : public Module
{
    Q_OBJECT
public:
    explicit Dolphin(QObject *parent = nullptr);
};
/*                                                                                               */
#endif