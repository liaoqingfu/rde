#ifndef CARDREADERPERIPHERAL_H
#define CARDREADERPERIPHERAL_H
#include "peripheraldevice.h"
class CardReaderPeripheral : public PeripheralDevice
{
    Q_OBJECT
public:
    explicit CardReaderPeripheral(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif