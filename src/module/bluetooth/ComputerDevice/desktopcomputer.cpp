#include "desktopcomputer.h"
DesktopComputer::DesktopComputer(const QBluetoothDeviceInfo &info,QObject *parent):ComputerDevice(info,"computer",parent)
{
}