#include "handheldclamshellcomputer.h"
HandheldClamShellComputer::HandheldClamShellComputer(const QBluetoothDeviceInfo &info,QObject *parent):ComputerDevice(info,"battery",parent)
{
}