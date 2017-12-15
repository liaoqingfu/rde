#ifndef PLAYER_H
#define PLAYER_H
#define ResourceNotFound "Resource not found."
/*                                                                                               */
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QStandardPaths>
#include <QAudioOutputSelectorControl>
#include <QMediaGaplessPlaybackControl>
#include <QMediaService>
/*                                                                                               */
class Player : public QMediaPlayer
{
    Q_OBJECT
public:
    static Player *instance();
    ~Player();
    void savePlaylist();

private:
    Player();
    QMediaPlaylist *m_playlist;
    static Player *m_instance;
    QString m_playlistFile;

private slots:
    //void audioAvailableChanged(const bool &available);
    void currentMediaChanged(const QMediaContent &content);
    void error(QMediaPlayer::Error error);
    void mediaStatusChanged(QMediaPlayer::MediaStatus status);
    void networkConfigurationChanged(const QNetworkConfiguration &config);
    void stateChanged(QMediaPlayer::State statei);
    void videoAvailableChanged(const bool &available);

signals:
    void bufferingMedia();
    void bufferedMedia();
    void loadingMedia();
    void loadedMedia();
    void stalledMedia();
    void noMedia();
    void endOfMedia();

    void resourceNotFound(QVariant file);
    void formatError();
    void accessDeniedError();
    void networkError();
    void serviceMissingError();
};
/*                                                                                               */
#endif