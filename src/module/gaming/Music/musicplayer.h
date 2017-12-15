#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
/*                                                                                               */
#include <QQuickItem>
#include <QMediaPlayer>
#include <QFileInfo>
#include <QDir>
/*                                                                                               */
class MusicPlayer : public QQuickItem
{
    Q_OBJECT
public:
    MusicPlayer();

public slots:
    void pause();
    void playMusic(QString module,QString game);

private:
    QMediaPlayer *m_player;

private slots:
    void error(QMediaPlayer::Error error);
    void stateChanged(QMediaPlayer::State state);
    void mediaStatusChanged(QMediaPlayer::MediaStatus status);
};
/*                                                                                               */
#endif