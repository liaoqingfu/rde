#ifndef GAMING_H
#define GAMING_H
/*                                                                                               */
#define URI "org.rde.gaming"
#define DatabaseFile "games.db"
#define Driver "QSQLITE"
#define ConnectionOptions "QSQLITE_ENABLE_SHARED_CACHE"
/*                                                                                               */
#include "gaming_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
#include "Provider/CoverProvider.h"
#include "Provider/LogoProvider.h"
#include "Provider/SystemIconProvider.h"
#include "Module/modulemanager.h"
#include "Info/reviewitem.h"
#include "window.h"
#include "librarymodel.h"
#include "Music/musicplayer.h"
#include <QFutureWatcher>
#include <QFileSystemWatcher>
#include <QtConcurrentRun>
/*                                                                                               */
class Gaming: public QObject,ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Gaming" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)

private:
    ~Gaming();
    Type type(){return Icon;}
    bool initialize();
    QFutureWatcher<bool> *m_watcher;
    QFutureWatcher<int>  *m_rowCountWatcher;
    QFileSystemWatcher *m_fileWatcher;

    void createDatabase();
    bool createDatabaseThread();

    void countRows();
    int rowCountThread();

private slots:
    void databaseCreated();
    void databaseChanged(const QString &file);
    void rowCountReady();
};
/*                                                                                               */
#endif