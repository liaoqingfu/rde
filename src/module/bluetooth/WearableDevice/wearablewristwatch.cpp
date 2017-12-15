#include "wearablewristwatch.h"
WearableWristWatch::WearableWristWatch(const QBluetoothDeviceInfo &info,QObject *parent):WearableDevice(info,"battery",parent)
{
}