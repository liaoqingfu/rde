#include "volume.h"
/*                                                                                               */
Volume::Volume(const QString &name,const QString &displayName,const QString &device,const QString &rootPath)
{
    m_name=name;
    m_displayName=displayName;
    m_device=device;
    m_rootPath=rootPath;
}
/*                                                                                               */