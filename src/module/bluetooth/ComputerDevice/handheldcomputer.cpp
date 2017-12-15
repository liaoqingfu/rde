#include "handheldcomputer.h"
HandheldComputer::HandheldComputer(const QBluetoothDeviceInfo &info,QObject *parent):ComputerDevice(info,"pda",parent)
{
}