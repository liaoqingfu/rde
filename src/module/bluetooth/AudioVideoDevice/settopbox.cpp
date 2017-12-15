#include "settopbox.h"
SetTopBox::SetTopBox(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"battery",parent)
{
}