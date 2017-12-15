#include "gaming.h"
/*                                                                                               */
bool Gaming::initialize()
{
    settings->beginGroup("Paths");
    QDir::setSearchPaths("GameCover",settings->value("CoverPath").toStringList());
    QDir::setSearchPaths("GameLogo",settings->value("LogoPath").toStringList());
    QDir::setSearchPaths("SystemIcon",settings->value("SystemIconPath").toStringList());
    QDir::setSearchPaths("GameMusic",settings->value("MusicPath").toStringList());
    settings->endGroup();

    context->engine()->addImageProvider("GameCover",new CoverProvider());
    context->engine()->addImageProvider("GameLogo",new LogoProvider());
    context->engine()->addImageProvider("SystemIcon",new SystemIconProvider());

    qmlRegisterType<Window>(URI,1,0,"GameWindow");
    qmlRegisterType<LibraryModel>(URI,1,0,"LibraryModel");
    qmlRegisterType<MusicPlayer>(URI,1,0,"MusicPlayer");
    qmlRegisterType<ReviewItem>(URI,1,0,"ReviewItem");

    ModuleManager::instance()->setParent(this);
    createDatabase();
    return true;
}
/*                                                                                               */
void Gaming::createDatabase()
{
    m_watcher=new QFutureWatcher<bool>(this);
    connect(m_watcher,SIGNAL(finished()),this,SLOT(databaseCreated()));
    m_watcher->setFuture(QtConcurrent::run(this,&Gaming::createDatabaseThread));
}
/*                                                                                               */
extern bool Gaming::createDatabaseThread()
{
    QDir dir(QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation).at(0));
    if(dir.mkpath(dir.absolutePath())){
        QSqlDatabase db=QSqlDatabase::addDatabase(Driver,ConnectionName);
        db.setDatabaseName(dir.absolutePath()+"/"+DatabaseFile);
        db.setConnectOptions(ConnectionOptions);
        if(db.isValid()){
            if(db.open()){
                QSqlQuery q(db);
                if(q.prepare("CREATE TABLE IF NOT EXISTS games(module,name,title,developer,year,category,PRIMARY KEY(module,name))")){
                    if(q.exec()){
                        db.close();
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
/*                                                                                               */
void Gaming::databaseCreated()
{
    if(m_watcher->result()){
        m_fileWatcher=new QFileSystemWatcher(QStringList(QSqlDatabase::database(ConnectionName).databaseName()));
        connect(m_fileWatcher,SIGNAL(fileChanged(QString)),this,SLOT(databaseChanged(QString)));
        countRows();
    }
    m_watcher->deleteLater();
}
/*                                                                                               */
void Gaming::databaseChanged(const QString &file)
{
    QFileInfo info(file);
    if(!info.exists()){
        m_fileWatcher->deleteLater();
        createDatabase();
    }
}
/*                                                                                               */
void Gaming::countRows()
{
    m_rowCountWatcher=new QFutureWatcher<int>(this);
    connect(m_rowCountWatcher,SIGNAL(finished()),this,SLOT(rowCountReady()));
    m_rowCountWatcher->setFuture(QtConcurrent::run(this,&Gaming::rowCountThread));
}
/*                                                                                               */
extern int Gaming::rowCountThread()
{
    QSqlDatabase db=QSqlDatabase::database(ConnectionName);
    if(db.open()){
        QSqlQuery q(db);
        if(q.prepare("SELECT COUNT(*) FROM games")){
            if(q.exec()){
                if(q.first()){
                    int rows=q.value(0).toInt();
                    q.finish();
                    db.close();
                    return rows;
                }
            }
        }
    }
}
/*                                                                                               */
void Gaming::rowCountReady()
{
    int rows=m_rowCountWatcher->result();
    if(rows==0){
        Module::modules.at(1)->startImporting();


        //qDebug() << "Database is empty, needs data";

        //        foreach(Module *module,Module::modules){
        //            qDebug() << "Import data from " << module->program();
        //        }
    }
}
/*                                                                                               */
Gaming::~Gaming()
{
    QSqlDatabase::removeDatabase(ConnectionName);
}
/*                                                                                               */



//    qmlRegisterType<WindowItem>(URI,1,0,"WindowItem");
//    qmlRegisterType<ListModel>(URI,1,0,"GameListModel");
//    qmlRegisterType<YearModel>(URI,1,0,"YearModel");
//    qmlRegisterType<HistoryReader>(URI,1,0,"HistoryReader");
//    qmlRegisterType<ReviewItem>(URI,1,0,"ReviewItem");
//    qmlRegisterType<Rating>(URI,1,0,"Rating");
//    qmlRegisterType<LaunchWindowItem>(URI,1,0,"LaunchWindowItem");