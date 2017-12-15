#include "player.h"
/*                                                                                               */
Player::Player(QObject *parent):QObject(parent)
{
    m_name="Player 1";
    QGamepadManager *m_manager=QGamepadManager::instance();
    QList<int> list=m_manager->connectedGamepads();
    if(!list.isEmpty()){
        m_gamePad=new QGamepad(list.at(0),this);
        connect(m_gamePad,SIGNAL(buttonUpChanged(bool)),this,SLOT(buttonUpChanged(bool)));
        connect(m_gamePad,SIGNAL(buttonDownChanged(bool)),this,SLOT(buttonDownChanged(bool)));
        connect(m_gamePad,SIGNAL(buttonLeftChanged(bool)),this,SLOT(buttonLeftChanged(bool)));
        connect(m_gamePad,SIGNAL(buttonRightChanged(bool)),this,SLOT(buttonRightChanged(bool)));
        connect(m_gamePad,SIGNAL(buttonAChanged(bool)),this,SLOT(buttonAChanged(bool)));
        connect(m_gamePad,SIGNAL(buttonBChanged(bool)),this,SLOT(buttonBChanged(bool)));
        connect(m_gamePad,SIGNAL(buttonXChanged(bool)),this,SLOT(buttonXChanged(bool)));
        connect(m_gamePad,SIGNAL(buttonYChanged(bool)),this,SLOT(buttonYChanged(bool)));
        connect(m_gamePad,SIGNAL(buttonSelectChanged(bool)),this,SLOT(buttonSelectChanged(bool)));
        connect(m_gamePad,SIGNAL(buttonStartChanged(bool)),this,SLOT(buttonStartChanged(bool)));
        connect(m_gamePad,SIGNAL(buttonL1Changed(bool)),this,SLOT(buttonL1Changed(bool)));
        connect(m_gamePad,SIGNAL(buttonR1Changed(bool)),this,SLOT(buttonR1Changed(bool)));
        connect(m_gamePad,SIGNAL(buttonCenterChanged(bool)),this,SLOT(buttonCenterChanged(bool)));
        connect(m_gamePad,SIGNAL(buttonGuideChanged(bool)),this,SLOT(buttonGuideChanged(bool)));
    }
    players.append(this);
}
/*                                                                                               */
void Player::buttonAChanged(const bool &pressed)
{
    if(pressed)
        emit kick();
}
/*                                                                                               */
void Player::buttonBChanged(const bool &pressed)
{
    if(pressed){
        qDebug() << "Button B";

    }
    else{

    }
}
/*                                                                                               */
void Player::buttonXChanged(const bool &pressed)
{
    if(pressed){
        qDebug() << "Button X";
    }
    else{

    }
}
/*                                                                                               */
void Player::buttonYChanged(const bool &pressed)
{
    if(pressed)
        emit punch();
    //    else{
    //        qDebug() << "Button Y";

    //    }
}
/*                                                                                               */
void Player::buttonUpChanged(const bool &pressed)
{
    if(pressed)
        emit jump();
    else
        emit neutral();
}
/*                                                                                               */
void Player::buttonDownChanged(const bool &pressed)
{
    if(pressed)
        emit crouch();
    else
        emit neutral();
}
/*                                                                                               */
void Player::buttonLeftChanged(const bool &pressed)
{
    if(pressed)
        emit walkLeft();
    else
        emit neutral();
}
/*                                                                                               */
void Player::buttonRightChanged(const bool &pressed)
{
    if(pressed)
        emit walkRight();
    else
        emit neutral();
}
/*                                                                                               */
void Player::buttonSelectChanged(const bool &pressed)
{
    if(pressed)
        emit taunt();
}
/*                                                                                               */
void Player::buttonStartChanged(const bool &pressed)
{
    if(pressed){
        qDebug() << m_name << "pauses!";
    }
}
/*                                                                                               */
void Player::buttonGuideChanged(const bool &pressed)
{
    if(pressed){

    }
    else{

    }
}
/*                                                                                               */
void Player::buttonCenterChanged(const bool &pressed)
{
    if(pressed){

    }
    else{

    }
}
/*                                                                                               */
void Player::buttonL1Changed(const bool &pressed)
{
    if(pressed){
        //Fighter::
        qDebug() << "Switch to previous fighter in team...";

    }
    else{

    }
}
/*                                                                                               */
void Player::buttonR1Changed(const bool &pressed)
{
    if(pressed){
        qDebug() << "Switch to next fighter in team...";
    }
    else{

    }
}
/*                                                                                               */
QVector<Player*> Player::players;