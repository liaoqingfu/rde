#ifndef MODULESERVICE_H
#define MODULESERVICE_H
/*                                                                                               */
#include "modulemodel.h"
#include "service.h"
#include <QDir>
#include <QStandardPaths>
#include <QFileSystemWatcher>
//#include "moduledockitem.h"
//#include "modulemodel.h"
//#include <QFileInfo>
/*                                                                                               */
class ModuleService : public Service
{
    Q_OBJECT
public:
    static ModuleService *instance();
    bool configure(QSettings &settings);

private:
    static ModuleService* m_instance;
    ModuleService();
    QString m_path;
    QFileSystemWatcher *m_watcher;
    void scanModules();
    QMap<QString,Module*> m_map;

private slots:
    void directoryChanged(const QString &dir);
};
/*                                                                                               */
#endif