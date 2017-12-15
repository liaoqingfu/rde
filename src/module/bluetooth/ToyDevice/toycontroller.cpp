#include "toycontroller.h"
ToyController::ToyController(const QBluetoothDeviceInfo &info,QObject *parent):ToyDevice(info,"presence_unknown",parent)
{
}