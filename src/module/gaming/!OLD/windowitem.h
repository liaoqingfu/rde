#ifndef WINDOWITEM_H
#define WINDOWITEM_H
/*                                                                                               */
#define Directory "database"
#define DatabaseFile "games.db"
#define Driver "QSQLITE"
#define URI "org.neon.gaming"
#define ConnectionOptions "QSQLITE_ENABLE_SHARED_CACHE"
/*                                                                                               */
#include "Library/librarymodel.h"
#include "importer.h"
#include "game.h"
#include "titlespeech.h"
#include "launchwindow.h"
//#include <QQuickItem>
#include <QQuickWindow>
#include <QFileSystemWatcher>
#include <QResource>
/*                                                                                               */
class WindowItem : public QQuickItem
{
    Q_OBJECT
public:
    WindowItem();
    ~WindowItem();

public slots:
    void startGame(const QString &module,const QString &game);

private:
    QString m_module;
    QString m_gameName;



    LibraryModel *m_libraryModel;
    QStringList m_moduleFiles;
    QStringList findModules(QString dir);
    bool initializeDatabase();
    QFileSystemWatcher *m_moduleDirWatcher;
    QFutureWatcher<QStringList> *m_modulesWatcher;
    QFutureWatcher<bool> *m_databaseWatcher;
    QString m_databasePath;
    Game *m_game;
    void componentComplete();
    TitleSpeech *m_titleSpeech;
    Importer *m_importer;
    LaunchWindow *m_launchWindow;

private slots:
    void updateModuleDir(QString dir);
    void modulesReady();
    void databaseReady();
    void importerDestroyed(QObject *object);
    void interpretTitle();
    void launch();
    void startedGame();
    void stoppedGame(QObject *object);

signals:
    void ready();
    void importing();
    void sayTitle(QVariant title);
    void gameStarted();
    void gameStopped();
    void openLaunchWindow();
};
/*                                                                                               */
#endif