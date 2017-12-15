#ifndef DIGITIZERTABLETPERIPHERAL_H
#define DIGITIZERTABLETPERIPHERAL_H
#include "peripheraldevice.h"
class DigitizerTabletPeripheral : public PeripheralDevice
{
    Q_OBJECT
public:
    explicit DigitizerTabletPeripheral(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif