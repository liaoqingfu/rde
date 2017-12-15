#ifndef HANDHELDCLAMSHELLCOMPUTER_H
#define HANDHELDCLAMSHELLCOMPUTER_H
#include "computerdevice.h"
class HandheldClamShellComputer : public ComputerDevice
{
    Q_OBJECT
public:
    explicit HandheldClamShellComputer(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif