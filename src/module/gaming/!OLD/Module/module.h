#ifndef MODULE_H
#define MODULE_H
#define TableString "(id PRIMARY KEY,title,year,developer,category)"
/*                                                                                               */
#include "GamingInterface.h"
#include "program.h"
#include <QPluginLoader>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
//#include <QFutureWatcher>
//#include <QtConcurrentRun>
#include <QStandardPaths>
/*                                                                                               */
class Module : public QObject
{
    Q_OBJECT
public:
    static QVector<Module*> modules;
    static QQmlContext *context;
    static Module *byIID(const QString &IID);
    explicit Module(const QString &filePath,QObject *parent = 0);
    GamingInterface *interface(){return m_interface;}
    ~Module();

    void importData();
    void deleteData();
    void initializeProgram();
    QString program()const{return m_interface->program();}
    QString workingDir()const{return m_interface->workingDir();}
    QStringList arguments(){return m_interface->arguments();}
    QProcessEnvironment processEnvironment()const{return m_interface->processEnvironment();}
    QIODevice::OpenMode openMode(){return m_interface->openMode();}

    QString iid()const{return m_iid;}
    QString filePath()const{return m_loader->fileName();}
    QString description()const{return m_description;}
    QString version()const{return m_version;}
    QString icon()const{return m_icon;}

    void readOutput(const QString &text){m_interface->readOutput(text);}
    void readError(const QString &text){m_interface->readError(text);}
    bool setGame(const QString &game){return m_interface->setGame(game);}
    bool load();

    void programNotRunning(){m_interface->notRunning();}
    void programRunning(){m_interface->running();}
    void programStarting(){m_interface->starting();}
    void programNormalExit(const int &code){m_interface->m_args.clear();m_interface->normalExit(code);}
    void programCrashed(const QByteArray &text){m_interface->m_args.clear();m_interface->crashed(text);}
    void programCrashExit(const int &code){m_interface->m_args.clear();m_interface->crashExit(code);}
    void programReadError(){m_interface->readError();}
    void programWriteError(){m_interface->writeError();}
    void programTimedOut(){m_interface->m_args.clear();m_interface->timedOut();}
    void programUnknownError(){m_interface->m_args.clear();m_interface->unknownError();}
    void programFailedToStart(){m_interface->m_args.clear();m_interface->failedToStart();}

    bool tableExists();
    int rowCount();

private:
    GamingInterface *m_interface;
    QPluginLoader *m_loader;
    QQmlComponent *component;
    QObject *m_instance;
    QString m_iid;
    QString m_title;
    QString m_description;
    QString m_version;
    QString m_icon;
    Program *m_program;


private slots:
    void programUpdated();
    void programRemoved();

//signals:
    //void importBusy();
    //void importReady();
};
/*                                                                                               */
#endif