#ifndef AUDIOSERVICE_H
#define AUDIOSERVICE_H
/*                                                                                               */
#include "service.h"
#include "inputdevicemodel.h"
#include "outputdevicemodel.h"
/*                                                                                               */
class AudioService : public Service
{
    Q_OBJECT
public:
    static AudioService *instance();
    bool configure(QSettings &settings);

private:
    AudioService();
    static AudioService *m_instance;
};
/*                                                                                               */
#endif