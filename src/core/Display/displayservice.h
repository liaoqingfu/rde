#ifndef DISPLAYSERVICE_H
#define DISPLAYSERVICE_H
/*                                                                                               */
#include "service.h"
//#include "desktop.h"
#include <QStandardPaths>
#include <QDir>
#include <QFileSystemWatcher>
#include <QSettings>
/*                                                                                               */
class DisplayService : public Service
{
    Q_OBJECT
public:
    static DisplayService *instance();

public slots:
    void suspend();
    void resume();

private:
    DisplayService();
    static DisplayService *m_instance;
    //Desktop *m_desktop;
    QString m_path;
    QFileSystemWatcher *m_watcher;

private slots:
    void directoryChanged(QString path);
};
/*                                                                                               */
#endif