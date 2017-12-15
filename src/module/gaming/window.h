#ifndef WINDOW_H
#define WINDOW_H
#define ConnectionName "Games"
/*                                                                                               */
#include "game.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QQuickItem>
#include <QQuickWindow>
/*                                                                                               */
class Window:public QQuickItem
{
    Q_OBJECT
public:
    Window();
    ~Window();

public slots:
    void startGame(const QString &module,const QString &game);
    void refreshDatabase();

private:
    Game *m_game;
    //void componentComplete();

private slots:
    void startedGame();
    void stoppedGame(QObject *object);

signals:
    void gameStarted();
    void gameStopped();
};
/*                                                                                               */
#endif