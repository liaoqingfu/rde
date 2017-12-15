#ifndef WIREDMODEMORVOICEGATEWAYPHONE_H
#define WIREDMODEMORVOICEGATEWAYPHONE_H
#include "phonedevice.h"
class WiredModemOrVoiceGatewayPhone : public PhoneDevice
{
    Q_OBJECT
public:
    explicit WiredModemOrVoiceGatewayPhone(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif