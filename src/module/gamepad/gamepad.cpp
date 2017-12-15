#include "gamepad.h"
/*                                                                                               */
bool Gamepad::initialize()
{
    connect(QGamepadManager::instance(),SIGNAL(connectedGamepadsChanged()),this,SLOT(connectedGamepadsChanged()));
    connect(QGamepadManager::instance(),SIGNAL(gamepadConnected(int)),this,SLOT(gamepadConnected(int)));
    connect(QGamepadManager::instance(),SIGNAL(gamepadDisconnected(int)),this,SLOT(gamepadDisconnected(int)));
    connect(QGamepadManager::instance(),SIGNAL(configurationCanceled(int)),this,SLOT(configurationCanceled(int)));
    connect(QGamepadManager::instance(),SIGNAL(buttonConfigured(int,QGamepadManager::GamepadButton)),this,SLOT(buttonConfigured(int,QGamepadManager::GamepadButton)));

    //createGamepad();

    setEnabled(true);

    qmlRegisterType<GamepadModel>("org.rde.gamepad",1,0,"GamepadModel");
    context->parentContext()->setContextProperty("Gamepad",this);
    return true;
}
/*                                                                                               */
void Gamepad::connectedGamepadsChanged()
{
    qDebug() << "Connected gamepads changed!!";
}
/*                                                                                               */
void Gamepad::gamepadConnected(const int &id)
{
    qDebug() << "Gamepad " << id << "connected";}

/*                                                                                               */
void Gamepad::gamepadDisconnected(const int &id)
{
    qDebug() << "Gamepad " << id << "disconnected";
}
/*                                                                                               */
void Gamepad::configurationCanceled(const int &id)
{
    qDebug() << "Gamepad" << id << "configuration canceled";
}
/*                                                                                               */
void Gamepad::buttonConfigured(const int &id, QGamepadManager::GamepadButton button)
{
    qDebug() << "Gamepad" << id << " configured button" << button;
}
/*                                                                                               */
void Gamepad::setEnabled(const bool &enabled)
{
    m_enabled=enabled;
    if(enabled){
        createGamepad();
    }
    else{
        if(m_gamepad){
            m_gamepad->deleteLater();
            m_gamepad=NULL;
        }
    }
}
/*                                                                                               */
void Gamepad::createGamepad()
{
    const QList<int> pads=QGamepadManager::instance()->connectedGamepads();
    if(!pads.isEmpty()){
        m_gamepad=new QGamepad(QGamepadManager::instance()->connectedGamepads().at(0),this);
        connect(m_gamepad,SIGNAL(buttonUpChanged(bool)),this,SLOT(upChanged(bool)));
        connect(m_gamepad,SIGNAL(buttonDownChanged(bool)),this,SLOT(downChanged(bool)));
        connect(m_gamepad,SIGNAL(buttonLeftChanged(bool)),this,SLOT(leftChanged(bool)));
        connect(m_gamepad,SIGNAL(buttonRightChanged(bool)),this,SLOT(rightChanged(bool)));
        connect(m_gamepad,SIGNAL(buttonAChanged(bool)),this,SLOT(aChanged(bool)));
        connect(m_gamepad,SIGNAL(buttonBChanged(bool)),this,SLOT(bChanged(bool)));
        connect(m_gamepad,SIGNAL(buttonXChanged(bool)),this,SLOT(xChanged(bool)));
        connect(m_gamepad,SIGNAL(buttonYChanged(bool)),this,SLOT(yChanged(bool)));
        connect(m_gamepad,SIGNAL(buttonStartChanged(bool)),this,SLOT(startChanged(bool)));
        connect(m_gamepad,SIGNAL(buttonSelectChanged(bool)),this,SLOT(selectChanged(bool)));
        connect(m_gamepad,SIGNAL(buttonGuideChanged(bool)),this,SLOT(guideChanged(bool)));
        connect(m_gamepad,SIGNAL(buttonL1Changed(bool)),this,SLOT(l1Changed(bool)));
        //connect(m_gamepad,SIGNAL(buttonL2Changed(bool)),this,SLOT(l2Changed(bool)));
        connect(m_gamepad,SIGNAL(buttonL3Changed(bool)),this,SLOT(l3Changed(bool)));
        connect(m_gamepad,SIGNAL(buttonR1Changed(bool)),this,SLOT(r1Changed(bool)));
        //connect(m_gamepad,SIGNAL(buttonR2Changed(bool)),this,SLOT(r2Changed(bool)));
        connect(m_gamepad,SIGNAL(buttonR3Changed(bool)),this,SLOT(r3Changed(bool)));
    }
}
/*                                                                                               */

///*                                                                                               */
//GamepadService::GamepadService():Service("Gamepad")
//{
//    //m_gamePad=new QGamepad(0,this);
//    //connect(m_gamePad,SIGNAL(connectedChanged(bool)),this,SLOT(connectedGamepadsChanged(bool)));

//    Service::engine->rootContext()->setContextProperty("GamePad",m_gamePad);
//    qmlRegisterType<GamepadModel>("org.neon.gamepad",1,0,"GamepadModel");

/*                                                                                               */
//void GamepadService::startScan()
//{
//    m_watcher=new QFutureWatcher<QVector<QGamepad*> >(this);
//    connect(m_watcher,SIGNAL(finished()),this,SLOT(scanFinished()));
//    m_watcher->setFuture(QtConcurrent::run(this,&GamepadService::scan));
//}
/*                                                                                               */
//extern QVector<QGamepad*> GamepadService::scan()
//{
//    QVector<QGamepad*> vector;
//    foreach(int id,QGamepadManager::instance()->connectedGamepads()){
//        vector.append(new QGamepad(id));
//    }
//    return vector;
//}
/*                                                                                               */
//void GamepadService::scanFinished()
//{
//    GamepadModel::gamepads=m_watcher->result();
//    if(!GamepadModel::gamepads.isEmpty()){
//        m_activepad=GamepadModel::gamepads.at(0);
//        Service::engine->rootContext()->setContextProperty("Gamepad",m_activepad);
//    }
//}
/*                                                                                               */