#include "adapter.h"
/*                                                                                               */
Adapter::Adapter():QObject()
{
    m_localDevice=new QBluetoothLocalDevice(this);
    if(m_localDevice->isValid()){
        connect(m_localDevice,SIGNAL(error(QBluetoothLocalDevice::Error)),this,SLOT(error(QBluetoothLocalDevice::Error)));
        connect(m_localDevice,SIGNAL(hostModeStateChanged(QBluetoothLocalDevice::HostMode)),this,SLOT(hostModeStateChanged(QBluetoothLocalDevice::HostMode)));
        connect(m_localDevice,SIGNAL(deviceConnected(QBluetoothAddress)),this,SLOT(deviceConnected(QBluetoothAddress)));
        connect(m_localDevice,SIGNAL(deviceDisconnected(QBluetoothAddress)),this,SLOT(deviceDisconnected(QBluetoothAddress)));
        connect(m_localDevice,SIGNAL(pairingDisplayConfirmation(QBluetoothAddress,QString)),this,SLOT(pairingDisplayConfirmation(QBluetoothAddress,QString)));
        connect(m_localDevice,SIGNAL(pairingDisplayPinCode(QBluetoothAddress,QString)),this,SLOT(pairingDisplayPinCode(QBluetoothAddress,QString)));
        connect(m_localDevice,SIGNAL(pairingFinished(QBluetoothAddress,QBluetoothLocalDevice::Pairing)),this,SLOT(pairingFinished(QBluetoothAddress,QBluetoothLocalDevice::Pairing)));
    }
    else
        qWarning() << "Local bluetooth adapter is not valid!";
    //qDebug() << "Connected devices: " << m_localDevice->connectedDevices();
}
/*                                                                                               */

/* static                                                                                        */
Adapter *Adapter::instance;
Adapter *Adapter::getInstance(){if(!instance)instance=new Adapter();return instance;}
/*  [EOF]                                                                                        */