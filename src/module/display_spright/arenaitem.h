#ifndef ARENAITEM_H
#define ARENAITEM_H
/*                                                                                               */
#include "Fighter/fighter.h"
/*                                                                                               */
class ArenaItem : public QQuickItem
{
    Q_OBJECT
public:
    ArenaItem();
    ~ArenaItem();

public slots:
    void addFighter(QString name);

private:
    QQmlComponent *m_component;
    void componentComplete();
};
/*                                                                                               */
#endif