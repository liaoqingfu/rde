#include "bluetooth.h"
/*                                                                                               */
bool Bluetooth::initialize()
{
    context->setContextProperty("Bluetooth",this);
    m_adapter=Adapter::getInstance();
    connect(m_adapter,SIGNAL(deviceHasConnected()),this,SIGNAL(deviceConnected()));
    connect(m_adapter,SIGNAL(deviceHasDisconnected()),this,SIGNAL(deviceDisconnected()));
    qmlRegisterType<DeviceModel>("org.rde.bluetooth",1,0,"BluetoothDeviceModel");
    //m_deviceManager=DeviceManager::getInstance();

    return true;
}
/*                                                                                               */