#include "wearableglasses.h"
WearableGlasses::WearableGlasses(const QBluetoothDeviceInfo &info,QObject *parent):WearableDevice(info,"battery",parent)
{
}