#include "windowitem.h"
/*                                                                                               */
WindowItem::WindowItem()
{
    m_titleSpeech=TitleSpeech::instance();

    m_libraryModel=new LibraryModel(this);
    connect(m_libraryModel,SIGNAL(titleChanged()),this,SLOT(interpretTitle()));
    Module::context->setContextProperty("LibraryModel",m_libraryModel);

    //qmlRegisterType<ModuleModel>(URI,1,0,"ModuleModel");
}
/*                                                                                               */
void WindowItem::componentComplete()
{
    QQuickItem::componentComplete();
    QDir moduleDir(QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation).at(0)+"/module/gaming");
    if(moduleDir.isReadable()){
        m_moduleDirWatcher=new QFileSystemWatcher(this);
        connect(m_moduleDirWatcher,SIGNAL(directoryChanged(QString)),this,SLOT(updateModuleDir(QString)));
        m_moduleDirWatcher->addPath(moduleDir.absolutePath());
        updateModuleDir(moduleDir.absolutePath());
    }
    else
        qDebug() << "Could not find game module path " << moduleDir.absolutePath();
}
/*                                                                                               */
void WindowItem::updateModuleDir(QString dir)
{
    m_modulesWatcher=new QFutureWatcher<QStringList>(this);
    connect(m_modulesWatcher,SIGNAL(finished()),this,SLOT(modulesReady()));
    m_modulesWatcher->setFuture(QtConcurrent::run(this,&WindowItem::findModules,dir));
}
/*                                                                                               */
extern QStringList WindowItem::findModules(QString dir)
{
    QDir d(dir);
    if(d.isReadable())
        return d.entryList(QStringList("*.so"),QDir::Files);
}
/*                                                                                               */
void WindowItem::modulesReady()
{
    m_moduleFiles=m_modulesWatcher->result();
    m_modulesWatcher->deleteLater();

    if(!m_moduleFiles.isEmpty()){
        foreach(QString info,m_moduleFiles)
            Module::modules.append(new Module(m_moduleDirWatcher->directories().at(0)+"/"+info,this));
        m_databaseWatcher=new QFutureWatcher<bool>(this);
        connect(m_databaseWatcher,SIGNAL(finished()),this,SLOT(databaseReady()));
        m_databaseWatcher->setFuture(QtConcurrent::run(this,&WindowItem::initializeDatabase));
    }
    else
        qDebug() << "No game modules found";
}
/*                                                                                               */
extern bool WindowItem::initializeDatabase()
{
    QDir dir(QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation).at(0)+"/"+Directory);
    if(dir.mkpath(dir.absolutePath())){
        QSqlDatabase db=QSqlDatabase::addDatabase(Driver,ConnectionName);
        db.setDatabaseName(dir.absolutePath()+"/"+DatabaseFile);
        db.setConnectOptions(ConnectionOptions);
        return db.isValid();
    }
    return false;
}
/*                                                                                               */
void WindowItem::databaseReady()
{
    if(m_databaseWatcher->result()){
        QSqlDatabase db=QSqlDatabase::database(ConnectionName);
        if(db.open()){
            QStringList tables=db.tables();
            QVector<Module*> vector;
            foreach(Module *module,Module::modules){
                if(!tables.contains(module->iid()))
                    vector.append(module);
            }
            if(vector.isEmpty()){
                m_libraryModel->initialize();
                emit ready();
            }
            else{
                emit importing();
                m_importer=new Importer(vector,this);
                connect(m_importer,SIGNAL(destroyed(QObject*)),this,SLOT(importerDestroyed(QObject*)));
            }
        }
    }
}
/*                                                                                               */
void WindowItem::importerDestroyed(QObject *object)
{
    Q_UNUSED(object)
    m_libraryModel->initialize();
    emit ready();
    m_importer=NULL;
}
/*                                                                                               */
void WindowItem::launch()
{
    m_game=new Game(m_module,m_gameName,this);
    connect(m_game,SIGNAL(started()),this,SLOT(startedGame()));
}
/*                                                                                               */
void WindowItem::startGame(const QString &module, const QString &game)
{
    m_module=module;
    m_gameName=game;

    QResource res("/"+module+"/Launch.qml");
    if(res.isValid()){
        m_launchWindow=new LaunchWindow(module,this);
        connect(m_launchWindow,SIGNAL(launch()),this,SLOT(launch()));
    }
    else
        launch();
}
/*                                                                                               */
void WindowItem::startedGame()
{
    connect(m_game,SIGNAL(destroyed(QObject*)),this,SLOT(stoppedGame(QObject*)));
    window()->hide();
    emit gameStarted();

    QString text=m_titleSpeech->setTitle(m_libraryModel->title().toString());
    emit sayTitle(text);
}
/*                                                                                               */
void WindowItem::stoppedGame(QObject *object)
{
    window()->show();
    m_game=NULL;
    emit gameStopped();
}
/*                                                                                               */
void WindowItem::interpretTitle()
{
}
/*                                                                                               */
WindowItem::~WindowItem()
{
    if(m_libraryModel)
        m_libraryModel->deleteLater();
    QSqlDatabase::database(ConnectionName).close(); // necessary?
    QSqlDatabase::removeDatabase(ConnectionName);
}
/*                                                                                               */