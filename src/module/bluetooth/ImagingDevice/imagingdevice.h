#ifndef IMAGINGDEVICE_H
#define IMAGINGDEVICE_H
#include "device.h"
class ImagingDevice : public Device
{
    Q_OBJECT
public:
    explicit ImagingDevice(const QBluetoothDeviceInfo &info,const QString iconName,QObject *parent=0);
};
#endif