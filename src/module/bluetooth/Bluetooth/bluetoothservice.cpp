#include "bluetoothservice.h"
/*                                                                                               */
BluetoothService::BluetoothService():Service("Bluetooth")
{
    qmlRegisterType<BluetoothDeviceModel>("org.rde.bluetooth",1,0,"BluetoothDeviceModel");
    qmlRegisterType<BluetoothServiceModel>("org.rde.bluetooth",1,0,"BluetoothServiceModel");

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
        if(active())
            Scanner::instance()->scan();
        else
            qDebug() << "Not scanning, device is off";
    }
    Service::engine->rootContext()->setContextProperty("Bluetooth",this);
}
/*                                                                                               */
bool BluetoothService::configure(QSettings &settings)
{
    Q_UNUSED(settings)
    qDebug() << "Configuring bluetooth service";
    return true;
}
/*                                                                                               */
void BluetoothService::error(QBluetoothLocalDevice::Error error)
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
void BluetoothService::hostModeStateChanged(QBluetoothLocalDevice::HostMode mode)
{
    switch(mode){
    case QBluetoothLocalDevice::HostPoweredOff:
        emit activeChanged();
        break;
    case QBluetoothLocalDevice::HostConnectable:
        qDebug() << "Bluetooth Host Mode: Host Connectable";
        break;
    case QBluetoothLocalDevice::HostDiscoverable:
        emit activeChanged();
        break;
    case QBluetoothLocalDevice::HostDiscoverableLimitedInquiry:
        qDebug() << "Bluetooth Host Mode: Host Discoverable (Limited Inquiry)";
        break;
    }
}
/*                                                                                               */
void BluetoothService::deviceConnected(const QBluetoothAddress &address)
{
    //Q_UNUSED(address)
    qDebug() << "Bluetooth: Device Connected to " << address.toString();
    //emit deviceHasConnected();
}
/*                                                                                               */
void BluetoothService::deviceDisconnected(const QBluetoothAddress &address)
{
    //Q_UNUSED(address)
    qDebug() << "Bluetooth: Device disconnected from " << address.toString();
    //emit deviceHasDisconnected();
}
/*                                                                                               */
void BluetoothService::pairingDisplayConfirmation(const QBluetoothAddress &address, const QString &string)
{
    Q_UNUSED(address)
    qDebug() << "Bluetooth: Pairing Display Confirmation:" << string;
}
/*                                                                                               */
void BluetoothService::pairingDisplayPinCode(const QBluetoothAddress &address, const QString &string)
{
    Q_UNUSED(address)
    qDebug() << "Bluetooth: Pairing Display Pin Code:" << string;
}
/*                                                                                               */
void BluetoothService::pairingFinished(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing)
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
bool BluetoothService::active()const
{
    if(m_localDevice->hostMode()==QBluetoothLocalDevice::HostPoweredOff)
        return false;
    return true;
}
/*                                                                                               */
void BluetoothService::setActive(const bool &active)
{
    if(active)
        m_localDevice->powerOn();
    else
        m_localDevice->setHostMode(QBluetoothLocalDevice::HostPoweredOff);
}
/*                                                                                               */
void BluetoothService::scan()
{
    Scanner::instance()->scan();
}
/*                                                                                               */
BluetoothService* BluetoothService::m_instance;
BluetoothService* BluetoothService::instance(){if(!m_instance)m_instance=new BluetoothService;return m_instance;}