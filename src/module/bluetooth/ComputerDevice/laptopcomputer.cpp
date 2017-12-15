#include "laptopcomputer.h"
LaptopComputer::LaptopComputer(const QBluetoothDeviceInfo &info,QObject *parent):ComputerDevice(info,"computer-laptop",parent)
{
}