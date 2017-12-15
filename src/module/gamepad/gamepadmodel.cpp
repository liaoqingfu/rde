#include "gamepadmodel.h"
/*                                                                                               */
GamepadModel::GamepadModel():Model()
{
    startScan();
}
/*                                                                                               */
QHash<int, QByteArray> GamepadModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="DeviceID";
    hash[1]="Name";
    hash[2]="IsConnected";
    return hash;
}
/*                                                                                               */
QVariant GamepadModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case DeviceID:return m_gamepads.at(index.row())->deviceId();
        case Name:return m_gamepads.at(index.row())->name();
        case IsConnected:return m_gamepads.at(index.row())->isConnected();
        }
    }
    return QVariant();
}
/*                                                                                               */
void GamepadModel::startScan()
{
    m_watcher=new QFutureWatcher<QVector<QGamepad*> >(this);
    connect(m_watcher,SIGNAL(finished()),this,SLOT(scanFinished()));
    m_watcher->setFuture(QtConcurrent::run(this,&GamepadModel::scan));
}
/*                                                                                               */
extern QVector<QGamepad*> GamepadModel::scan()
{
    QVector<QGamepad*> vector;
    foreach(int id,QGamepadManager::instance()->connectedGamepads()){
        vector.append(new QGamepad(id));
    }
    return vector;
}
/*                                                                                               */
void GamepadModel::scanFinished()
{
    qDebug() << "Finished scanning gamepad";
//    GamepadModel::gamepads=m_watcher->result();
//    if(!GamepadModel::gamepads.isEmpty()){
//        m_activepad=GamepadModel::gamepads.at(0);
//        Service::engine->rootContext()->setContextProperty("Gamepad",m_activepad);
//    }


    beginResetModel();
    m_gamepads=m_watcher->result();
    endResetModel();

    qDebug() << "Found " << m_gamepads.size() << " pads";
}
/*                                                                                               */
void GamepadModel::setCurrentIndex(const int &index)
{
    Q_UNUSED(index)
    //qDebug() << "Selected gamepad " << gamepads.at(index)->deviceId();
}
/*                                                                                               */
//QVector<QGamepad*> GamepadModel::gamepads;