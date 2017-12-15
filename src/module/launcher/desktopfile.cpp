#include "desktopfile.h"
/*                                                                                               */
DesktopFile::DesktopFile(QSettings &settings)
{
    m_filePath=settings.fileName();
    m_exec=settings.value("Exec").toString();
    m_icon=settings.value("Icon").toString();
    m_name=settings.value("Name").toString();
}
/*                                                                                               */
bool DesktopFile::click()
{
    QProcess process;
    return process.startDetached(m_exec);
}
/*                                                                                               */