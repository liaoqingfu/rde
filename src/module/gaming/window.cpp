#include "window.h"
/*                                                                                               */
Window::Window()
{
    QSqlDatabase db=QSqlDatabase::database(ConnectionName);
    if(db.open()){
        foreach (Module *module,Module::modules){
        }
    }
}
/*                                                                                               */
//void Window::componentComplete()
//{
//    QQuickItem::componentComplete();
//    //qDebug() << "Window created!!";
//}
/*                                                                                               */
void Window::startGame(const QString &module, const QString &game)
{
    //m_module=module;
    //m_gameName=game;

    //    QResource res("/"+module+"/Launch.qml");
    //    if(res.isValid()){
    //        m_launchWindow=new LaunchWindow(module,this);
    //        connect(m_launchWindow,SIGNAL(launch()),this,SLOT(launch()));
    //    }
    //    else
    //launch();

    m_game=new Game(module,game,this);
    connect(m_game,SIGNAL(started()),this,SLOT(startedGame()));
}
/*                                                                                               */
void Window::startedGame()
{
    connect(m_game,SIGNAL(destroyed(QObject*)),this,SLOT(stoppedGame(QObject*)));
    window()->hide();
    emit gameStarted();


    //QString text=m_titleSpeech->setTitle(m_libraryModel->title().toString());
    //emit sayTitle(text);
}
/*                                                                                               */
void Window::stoppedGame(QObject *object)
{
    window()->showNormal();
    emit gameStopped();
}
/*                                                                                               */
void Window::refreshDatabase()
{
    //qDebug() << "Refreshing database!";

    //    foreach(Module *module,Module::modules){
    //        qDebug() << "Importing from " << module->program();
    //    }

    Module::modules.at(5)->startImporting();
}
/*                                                                                               */
Window::~Window()
{
    if(QSqlDatabase::database(ConnectionName).isOpen())
        QSqlDatabase::database(ConnectionName).close();
}
/*                                                                                               */