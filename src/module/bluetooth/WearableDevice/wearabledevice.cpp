#include "wearabledevice.h"
WearableDevice::WearableDevice(const QBluetoothDeviceInfo &info,const QString iconName,QObject *parent):Device(info,iconName,parent)
{
}