#include "wearablejacket.h"
WearableJacket::WearableJacket(const QBluetoothDeviceInfo &info,QObject *parent):WearableDevice(info,"battery",parent)
{
}