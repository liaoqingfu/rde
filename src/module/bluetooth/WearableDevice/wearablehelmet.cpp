#include "wearablehelmet.h"
WearableHelmet::WearableHelmet(const QBluetoothDeviceInfo &info,QObject *parent):WearableDevice(info,"battery",parent)
{
}