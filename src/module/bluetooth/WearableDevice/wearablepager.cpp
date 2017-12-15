#include "wearablepager.h"
WearablePager::WearablePager(const QBluetoothDeviceInfo &info,QObject *parent):WearableDevice(info,"battery",parent)
{
}