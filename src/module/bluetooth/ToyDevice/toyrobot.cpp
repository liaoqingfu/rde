#include "toyrobot.h"
ToyRobot::ToyRobot(const QBluetoothDeviceInfo &info,QObject *parent):ToyDevice(info,"presence_unknown",parent)
{
}