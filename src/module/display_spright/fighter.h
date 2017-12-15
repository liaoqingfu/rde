#ifndef FIGHTER_H
#define FIGHTER_H
/*                                                                                               */
#include <QVector>
/*                                                                                               */
class Fighter
{
public:
    explicit Fighter();
    static QVector<Fighter*> fighters;
};
/*                                                                                               */
#endif