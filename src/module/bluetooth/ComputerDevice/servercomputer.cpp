#include "servercomputer.h"
ServerComputer::ServerComputer(const QBluetoothDeviceInfo &info,QObject *parent):ComputerDevice(info,"battery",parent)
{
}