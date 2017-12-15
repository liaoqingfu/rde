#ifndef PPSSPP_H
#define PPSSPP_H
/*                                                                                               */
#include "module.h"
#include <QDebug>
/*                                                                                               */
class PPSSPP : public Module
{
    Q_OBJECT
public:
    static PPSSPP *instance();
    QStringList importData();
    QStringList arguments(const QString &game);

private:
    static PPSSPP *m_instance;
    PPSSPP();
};
/*                                                                                               */
#endif