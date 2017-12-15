#include "game.h"
/*                                                                                               */
Game::Game(QString module,QString game,QObject *parent):QProcess(parent)
{
    m_module=Module::byIID(module);
    if(m_module){
        connect(this,SIGNAL(stateChanged(QProcess::ProcessState)),this,SLOT(stateChanged(QProcess::ProcessState)));

        setProcessEnvironment(m_module->processEnvironment());

        setProgram(m_module->program());
        setArguments(m_module->arguments(game));
        setWorkingDirectory(m_module->workingDir());

        if(open(m_module->openMode())){
            connect(this,SIGNAL(errorOccurred(QProcess::ProcessError)),this,SLOT(errorOccurred(QProcess::ProcessError)));
            //connect(this,SIGNAL(started()),m_module,SLOT(started()));
            connect(this,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finished(int,QProcess::ExitStatus)));
            connect(this,SIGNAL(readyReadStandardError()),this,SLOT(readError()));
            connect(this,SIGNAL(readyReadStandardOutput()),this,SLOT(readOutput()));



        }
        else
            qWarning() << "Failed to open " << m_module->program();
    }
}
/*                                                                                               */
void Game::stateChanged(QProcess::ProcessState state)
{
    switch(state){
    case QProcess::NotRunning:m_module->notRunning();break;
    case QProcess::Starting:m_module->starting();break;
    case QProcess::Running:{


        m_processWindow=processWindow(processId());
        m_module->running();
        break;
    }
    }
}
/*                                                                                               */
void Game::errorOccurred(QProcess::ProcessError error)
{
    switch(error){
    case QProcess::FailedToStart:m_module->failedToStart();break;
    case QProcess::Crashed:m_module->crashed(readAllStandardError());break;
    case QProcess::Timedout:m_module->timedOut();break;
    case QProcess::WriteError:/*m_module->writeError()*/;break;
    case QProcess::ReadError:/*m_module->readError()*/;break;
    case QProcess::UnknownError:m_module->unknownError();break;
    }
}
/*                                                                                               */
void Game::finished(const int &code,QProcess::ExitStatus status)
{
    switch(status){
    case QProcess::NormalExit:m_module->normalExit(code);break;
    case QProcess::CrashExit:m_module->crashExit(code);break;
    }
    deleteLater();
}
/*                                                                                               */
void Game::readOutput()
{
    while(canReadLine()){
        QString line=readLine().constData();
        line=line.trimmed();
        if(!line.isEmpty())
            m_module->readOutput(line);
    }
}
/*                                                                                               */
void Game::readError()
{
    m_module->readError(readAllStandardError());
}
/*                                                                                               */
void Game::addToHistory()
{
    m_historyWatcher=new QFutureWatcher<bool>(this);
    connect(m_historyWatcher,SIGNAL(finished()),this,SLOT(historyFinished()));
    m_historyWatcher->setFuture(QtConcurrent::run(this,&Game::addToHistoryThread));
}
/*                                                                                               */
extern bool Game::addToHistoryThread()
{
    //    QFile file("/system/config/neon/neon/gamehistory.log");
    //    if(file.open(QIODevice::Append)){
    //        QString str=m_module->iid()+" "+m_game;
    //        file.write(str.toLocal8Bit()+"\n");
    //        file.close();
    //        return true;
    //    }
    return false;
}
/*                                                                                               */
void Game::historyFinished()
{
    if(m_historyWatcher->result()){
        qDebug() << "Adding to history finished!!";
    }
}
/*                                                                                               */
QWindow *Game::processWindow(const qint64 &processId)
{
    return QWindow::fromWinId(00000);
}
/*                                                                                               */