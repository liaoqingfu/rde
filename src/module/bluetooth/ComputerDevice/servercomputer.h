#ifndef SERVERCOMPUTER_H
#define SERVERCOMPUTER_H
#include "computerdevice.h"
class ServerComputer : public ComputerDevice
{
    Q_OBJECT
public:
    explicit ServerComputer(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif