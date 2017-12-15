#ifndef DESKTOPFILE_H
#define DESKTOPFILE_H
/*                                                                                               */
#include <QSettings>
#include <QProcess>
/*                                                                                               */
class DesktopFile
{
public:
    explicit DesktopFile(QSettings &settings);
    QString filePath()const{return m_filePath;}
    QString icon()const{return m_icon;}
    QString name()const{return m_name;}
    QString workingDir()const{return m_workingDir;}
    bool click();

private:
    QString m_filePath;
    QString m_exec;
    QString m_icon;
    QString m_name;
    QString m_workingDir;
};
/*                                                                                               */
#endif