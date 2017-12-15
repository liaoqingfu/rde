#ifndef INPUTDEVICEMODEL_H
#define INPUTDEVICEMODEL_H
/*                                                                                               */
#include "audiodevicemodel.h"
/*                                                                                               */
class InputDeviceModel:public AudioDeviceModel
{
    Q_OBJECT
public:
    explicit InputDeviceModel();
};
/*                                                                                               */
#endif