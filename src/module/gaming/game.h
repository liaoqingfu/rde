#ifndef GAME_H
#define GAME_H
/*                                                                                               */
#include "Module/module.h"
#include <QProcess>
#include <QSettings>
#include <QtConcurrentRun>
#include <QFutureWatcher>
#include <QFile>
#include <QWindow>
/*                                                                                               */
class Game : public QProcess
{
    Q_OBJECT
public:
    explicit Game(QString module,QString game,QObject *parent=0);

    QString game(){return m_game;}
    Module *module(){return m_module;}

private:
    Module *m_module;
    QString m_game;

    void addToHistory();
    QFutureWatcher<bool> *m_historyWatcher;
    bool addToHistoryThread();
    QWindow *m_processWindow;
    QWindow *processWindow(const qint64 &processId);

private slots:
    void argFinished();
    void finished(const int &code,QProcess::ExitStatus status);
    void historyFinished();
    void stateChanged(QProcess::ProcessState state);
    void errorOccurred(QProcess::ProcessError error);
    void readError();
    void readOutput();
};
/*                                                                                               */
#endif