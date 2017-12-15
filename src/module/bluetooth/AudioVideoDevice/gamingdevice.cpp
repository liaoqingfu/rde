#include "gamingdevice.h"
GamingDevice::GamingDevice(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"battery",parent)
{
}