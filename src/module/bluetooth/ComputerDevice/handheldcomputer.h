#ifndef HANDHELDCOMPUTER_H
#define HANDHELDCOMPUTER_H
#include "computerdevice.h"
class HandheldComputer : public ComputerDevice
{
    Q_OBJECT
public:
    explicit HandheldComputer(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif