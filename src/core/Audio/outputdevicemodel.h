#ifndef OUTPUTDEVICEMODEL_H
#define OUTPUTDEVICEMODEL_H
/*                                                                                               */
#include "audiodevicemodel.h"
/*                                                                                               */
class OutputDeviceModel : public AudioDeviceModel
{
    Q_OBJECT
public:
    explicit OutputDeviceModel();
};
/*                                                                                               */
#endif