#include "audioservice.h"
/*                                                                                               */
AudioService::AudioService():Service("Audio")
{
    qmlRegisterType<InputDeviceModel>("org.rde.audio",1,0,"InputDeviceModel");
    qmlRegisterType<OutputDeviceModel>("org.rde.audio",1,0,"OutputDeviceModel");
}
/*                                                                                               */
bool AudioService::configure(QSettings &settings)
{
    Q_UNUSED(settings)
    return true;
}
/*                                                                                               */
AudioService* AudioService::m_instance;
AudioService* AudioService::instance(){if(!m_instance)m_instance=new AudioService;return m_instance;}