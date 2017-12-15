#include "toydoll.h"
ToyDoll::ToyDoll(const QBluetoothDeviceInfo &info,QObject *parent):ToyDevice(info,"presence_unknown",parent)
{
}