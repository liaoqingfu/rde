#include "handsfreedevice.h"
HandsFreeDevice::HandsFreeDevice(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"battery",parent)
{
}