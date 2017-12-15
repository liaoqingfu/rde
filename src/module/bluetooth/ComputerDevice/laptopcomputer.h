#ifndef LAPTOPCOMPUTER_H
#define LAPTOPCOMPUTER_H
#include "computerdevice.h"
class LaptopComputer : public ComputerDevice
{
    Q_OBJECT
public:
    explicit LaptopComputer(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif