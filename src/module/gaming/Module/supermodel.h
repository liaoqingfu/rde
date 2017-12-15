#ifndef SUPERMODEL_H
#define SUPERMODEL_H
/*                                                                                               */
#include "module.h"
/*                                                                                               */
class Supermodel : public Module
{
    Q_OBJECT

public:
    static Supermodel *instance();
    QStringList importData();
    QStringList arguments(const QString &game);

private:
    static Supermodel *m_instance;
    explicit Supermodel();
};
/*                                                                                               */
#endif