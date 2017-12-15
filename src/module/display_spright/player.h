#ifndef PLAYER_H
#define PLAYER_H
/*                                                                                               */
#include <QGamepad>
#include <QGamepadManager>
#include <QDebug>
/*                                                                                               */
class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);
    static QVector<Player*> players;

private:
    QGamepad *m_gamePad;
    QString m_name;

private slots:
    void buttonAChanged(const bool &pressed);
    void buttonBChanged(const bool &pressed);
    void buttonXChanged(const bool &pressed);
    void buttonYChanged(const bool &pressed);
    void buttonUpChanged(const bool &pressed);
    void buttonDownChanged(const bool &pressed);
    void buttonLeftChanged(const bool &pressed);
    void buttonRightChanged(const bool &pressed);
    void buttonSelectChanged(const bool &pressed);
    void buttonStartChanged(const bool &pressed);
    void buttonL1Changed(const bool &pressed);
    void buttonR1Changed(const bool &pressed);
    void buttonCenterChanged(const bool &pressed);
    void buttonGuideChanged(const bool &pressed);

signals:
    void neutral();
    void walkUp();
    void walkDown();
    void walkLeft();
    void walkRight();
    void jump();
    void crouch();
    void punch();
    void kick();
    void taunt();
};
/*                                                                                               */
#endif