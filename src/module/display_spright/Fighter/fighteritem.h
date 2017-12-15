#ifndef FIGHTERITEM_H
#define FIGHTERITEM_H
/*                                                                                               */
#include <QQuickItem>
/*                                                                                               */
class FighterItem : public QQuickItem
{
    Q_OBJECT
public:
    FighterItem();

signals:
    void neutral();
    void kick();
    void punch();
    void jump();
    void crouch();
    void taunt();
    void walkLeft();
    void walkRight();
};
/*                                                                                               */
#endif