#include "bluetooth.h"
/*                                                                                               */
bool Bluetooth::initialize()
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

        //if(m_localDevice->)
        //            if(active())
        //                //Scanner::instance()->scan();
        //            else
        //                qDebug() << "Not scanning, device is off";
    }


    //    context->setContextProperty("Bluetooth",this);
    //    m_adapter=Adapter::getInstance();
    //    connect(m_adapter,SIGNAL(deviceHasConnected()),this,SIGNAL(deviceConnected()));
    //    connect(m_adapter,SIGNAL(deviceHasDisconnected()),this,SIGNAL(deviceDisconnected()));
    //    qmlRegisterType<DeviceModel>("org.rde.bluetooth",1,0,"BluetoothDeviceModel");
    //    //m_deviceManager=DeviceManager::getInstance();

    return true;
}
/*                                                                                               */
void Bluetooth::error(QBluetoothLocalDevice::Error error)
{
    switch(error){
    case QBluetoothLocalDevice::NoError:
        qDebug() << "Bluetooth: No Error";
        break;
    case QBluetoothLocalDevice::PairingError:
        qDebug() << "Bluetooth: Pairing Error";
        break;
    case QBluetoothLocalDevice::UnknownError:
        qDebug() << "Bluetooth: Unknown Error";
        break;
    }
}
/*                                                                                               */
void Bluetooth::hostModeStateChanged(QBluetoothLocalDevice::HostMode mode)
{
    switch(mode){
    case QBluetoothLocalDevice::HostPoweredOff:
        //emit activeChanged();
        break;
    case QBluetoothLocalDevice::HostConnectable:
        qDebug() << "Bluetooth Host Mode: Host Connectable";
        break;
    case QBluetoothLocalDevice::HostDiscoverable:
        //emit activeChanged();
        break;
    case QBluetoothLocalDevice::HostDiscoverableLimitedInquiry:
        qDebug() << "Bluetooth Host Mode: Host Discoverable (Limited Inquiry)";
        break;
    }
}
/*                                                                                               */
void Bluetooth::deviceConnected(const QBluetoothAddress &address)
{
    //Q_UNUSED(address)
    qDebug() << "Bluetooth: Device Connected to " << address.toString();
    //emit deviceHasConnected();
}
/*                                                                                               */
void Bluetooth::deviceDisconnected(const QBluetoothAddress &address)
{
    //Q_UNUSED(address)
    qDebug() << "Bluetooth: Device disconnected from " << address.toString();
    //emit deviceHasDisconnected();
}
/*                                                                                               */
void Bluetooth::pairingDisplayConfirmation(const QBluetoothAddress &address, const QString &string)
{
    Q_UNUSED(address)
    qDebug() << "Bluetooth: Pairing Display Confirmation:" << string;
}
/*                                                                                               */
void Bluetooth::pairingDisplayPinCode(const QBluetoothAddress &address, const QString &string)
{
    Q_UNUSED(address)
    qDebug() << "Bluetooth: Pairing Display Pin Code:" << string;
}
/*                                                                                               */
void Bluetooth::pairingFinished(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing)
{
    Q_UNUSED(address)
    switch(pairing){
    case QBluetoothLocalDevice::Unpaired:
        qDebug() << "Bluetooth Pairing Finished: Unpaired";
        break;
    case QBluetoothLocalDevice::Paired:
        qDebug() << "Bluetooth Pairing Finished: Paired";
        break;
    case QBluetoothLocalDevice::AuthorizedPaired:
        qDebug() << "Bluetooth Pairing Finished: AuthorizedPaired";
        break;
    }
}
/*                                                                                               */