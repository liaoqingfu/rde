#include "wearablecomputer.h"
WearableComputer::WearableComputer(const QBluetoothDeviceInfo &info,QObject *parent):ComputerDevice(info,"battery",parent)
{
}