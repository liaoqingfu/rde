#ifndef FIGHTER_H
#define FIGHTER_H
/*                                                                                               */
#include "head.h"
#include "torso.h"
#include "arms.h"
#include "legs.h"
#include "Item/consumableitem.h"
#include "animation.h"
#include "player.h"
#include "fighteritem.h"

#include <QQuickItem>
#include <QQmlComponent>
#include <QQmlContext>
#include <QMediaPlayer>
#include <QDebug>
#include <QDir>
#include <QtConcurrentRun>
#include <QFutureWatcher>

#include <QFile>
/*                                                                                               */
class Fighter : public QObject
{
    Q_OBJECT
public:
    enum Facing{Left,Right};
    Facing facing(){return m_facing;}
    static QQmlContext *context;
    explicit Fighter(const QString &name);
    ~Fighter();
    QString name()const{return m_name;}
    Fighter *target()const{return m_target;}
    void setTarget(Fighter *target);
    int level()const{return m_level;}
    int hp()const{return m_hp;}
    int sp()const{return m_sp;}
    int weight()const{return m_weight;}

    enum Gender{Male,Female};
    Gender m_gender;
    static QVector<Fighter*> fighters;

    int team()const{return m_team;}
    void setTeam(const int &team){m_team=team;}

    void searchTarget();
    void noticeNewFighter(Fighter *fighter);

    static QQuickItem *m_arena;

    int xPos()const{return m_item->x();}
    int yPos()const{return m_item->y();}

    void addItem(ConsumableItem *item);
    void dropItem(ConsumableItem *item);

    static void parseTextFile(const QString &file);

private:
    Player *m_player=NULL;
    QString m_basePath=NULL;
    QQmlComponent *m_component=NULL;
    FighterItem *m_item=NULL;
    //QQuickItem *m_item=NULL;
    QMediaPlayer *m_voice=NULL;
    QString m_name=NULL;
    Head *m_head=NULL;
    Torso *m_torso=NULL;
    Arms *m_arms=NULL;
    Legs *m_legs=NULL;
    Fighter *m_target=NULL;

    int m_level=NULL;
    int m_hp=NULL;
    int m_sp=NULL;
    int m_weight=NULL;
    int m_strengt=NULL;
    int m_endurance=NULL;

    QMap<QString,QUrl> m_speech;
    void ready();
    void say(const QString &speech);
    int m_team=0;

    void parseFile();

    QFutureWatcher<QString> *m_parseWatcher;
    QString parseThread();

    QFutureWatcher<Fighter*> *m_searchTargetWatcher;
    Fighter *searchTargetThread();

    static int autoXPos;

    QVector<ConsumableItem*> m_inventory;

    Facing m_facing=Right;

    QMap<QString,Animation*> m_animations;

    void timerEvent(QTimerEvent *event);
    int m_timer;

private slots:
    void statusChanged(QQmlComponent::Status status);
    void parseFinished();
    void searchTargetFinished();


    void neutral();
    void walkLeft();
    void walkRight();
    void crouch();
    void jump();
    void punch();
    void kick();
    void taunt();
};
/*                                                                                               */
#endif