#ifndef MEDIAPLAYER_H
/*                                                                                               */
#define MEDIAPLAYER_H
#define URI "org.rde.mediaplayer"
/*                                                                                               */
#include "mediaplayer_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
#include "Core/playlistmodel.h"
#include "Library/librarymodel.h"
#include "Playlists/playlistsmodel.h"
#include "Streams/streamsmodel.h"
#include "Disc/cdtrackmodel.h"

//#include <QAudioDeviceInfo>
/*                                                                                               */
//#include "probe.h"
/*                                                                                               */
class MediaPlayer: public QObject,ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "MediaPlayer" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)
    //Q_PROPERTY(int index READ index WRITE setIndex NOTIFY indexChanged)


    //Q_PROPERTY(QVariant title READ title NOTIFY titleChanged)
    //Q_PROPERTY(QVariant artist READ artist NOTIFY artistChanged)
    //Q_PROPERTY(QVariant album READ album NOTIFY albumChanged)
    //Q_PROPERTY(QVariant genre READ genre NOTIFY genreChanged)
    //Q_PROPERTY(QVariant year READ album NOTIFY yearChanged)

    //Q_PROPERTY(QVariant title READ title)
    Q_PROPERTY(QString title READ title)


    Q_PROPERTY(QString artist READ artist)
    Q_PROPERTY(QVariant album READ album)
    Q_PROPERTY(QVariant genre READ genre)
    Q_PROPERTY(QVariant year READ album)

    Q_PROPERTY(bool allowPlay READ allowPlay NOTIFY allowPlayChanged)
    Q_PROPERTY(bool allowStop READ allowStop NOTIFY allowStopChanged)
    Q_PROPERTY(bool allowNext READ allowNext NOTIFY allowNextChanged)
    Q_PROPERTY(bool allowPrevious READ allowPrevious NOTIFY allowPreviousChanged)
    Q_PROPERTY(bool allowSeeking READ allowSeeking NOTIFY allowSeekingChanged)
    Q_PROPERTY(bool allowRepeat READ allowRepeat NOTIFY allowRepeatChanged)
    Q_PROPERTY(bool allowShuffle READ allowShuffle NOTIFY allowShuffleChanged)
    Q_PROPERTY(bool allowMute READ allowMute NOTIFY allowMuteChanged)
    Q_PROPERTY(bool allowSpeed READ allowSpeed NOTIFY allowSpeedChanged)



    //Q_PROPERTY(bool audioAvailable READ audioAvailable NOTIFY audioAvailableChanged)

    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(int duration READ duration NOTIFY durationChanged)
    Q_PROPERTY(int position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(qreal speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(int windowIndex READ windowIndex WRITE setWindowIndex NOTIFY windowIndexChanged)

public:
    int windowIndex()const{return m_windowIndex;}
    void setWindowIndex(const int &index){m_windowIndex=index;}
    bool allowStop()const{return m_allowStop;}
    bool allowPlay()const{return m_allowPlay;}
    bool allowPrevious()const{return m_allowPrevious;}
    bool allowNext()const{return m_allowNext;}
    bool allowSeeking()const{return m_allowSeeking;}
    bool allowRepeat()const{return m_allowRepeat;}
    bool allowShuffle()const{return m_allowShuffle;}
    bool allowMute()const{return m_allowMute;}
    bool allowSpeed()const{return m_allowSpeed;}

public slots:
    void openFile(const QString &file);
    void openPlaylist(const QString &playlist);
    void openStream(const QString &stream);
    void play(){m_player->play();}
    void stop(){m_player->stop();}
    void pause();
    void next();
    void previous();
    void seekBackward();
    void seekForward();
    void stopSeeking();
    void setPosition(const qint64 position){m_player->setPosition(position);}
    void shuffle();
    void repeat();
    void mute();
    void closeWindow();

private:
    int m_index;
    void setIndex(int index){m_index=index;}
    int index(){return m_index;}
    Type type(){return Dock;}
    bool initialize();
    Player *m_player;

    //Probe *m_probe;

    //QAudioProbe *audioProbe;
    //QVariant title()const;


    QString title()const;
    //QVariant artist()const;
    QString artist()const;

    QVariant album()const{return m_player->metaData(QMediaMetaData::AlbumTitle);}
    QVariant genre()const{return m_player->metaData(QMediaMetaData::Genre);}
    QVariant year()const{return m_player->metaData(QMediaMetaData::Year);}
    qint64 duration()const{return m_player->duration();}
    qint64 position()const{return m_player->position();}
    //void setPosition(const int &hour,const int &min,const int &sec);
    //void setPosition(const qint64 &position);

    qreal speed()const{return m_player->playbackRate();}
    void setSpeed(const qreal &value);//{player->setPlaybackRate(value);}

    int volume()const{return m_player->volume();}
    void setVolume(const int &value){m_player->setVolume(value);}

    bool m_allowStop;
    bool m_allowPlay;
    bool m_allowPrevious;
    bool m_allowNext;
    bool m_allowSeeking;
    bool m_allowRepeat;
    bool m_allowShuffle;
    bool m_allowMute;
    bool m_allowSpeed;

    int m_windowIndex;



    QString m_currentPlaylist;

private slots:
    void bufferStatusChanged(const int &percentFilled);

    void metaDataAvailable(const bool &available);
    void seekableChanged(const bool &seekable);
    //void durationChanged(const qint64 &duration);
    //void positionChanged(const qint64 &position);
    void volumeChanged(const int &volume);
    //void mediaChanged(const QMediaContent &content);
    void mutedChanged(const bool &muted);
    void playbackRateChanged(const qreal &rate);


signals:
    void allowPlayChanged();
    void allowStopChanged();
    void allowNextChanged();
    void allowPreviousChanged();
    void allowSeekingChanged();
    void allowRepeatChanged();
    void allowShuffleChanged();
    void allowMuteChanged();
    void allowSpeedChanged();

    void metaChanged();
    //void titleChanged();
    //void artistChanged();
    //void albumChanged();
    //void yearChanged();
    //void genreChanged();
    //void durationChanged();
    //void positionChanged();

    void speedChanged();
    void volumeChanged();
    void announce(QVariant text);
    void durationChanged(const qint64 &duration);
    void positionChanged(const qint64 &position);
    void windowIndexChanged();
    //void setDuration(QVariant min,QVariant sec,QVariant msec);
    void resourceNotFound(QVariant file);
    //void bufferStatusChanged(const int &percentFilled);

    void noMedia();
    void loadingMedia();
    void loadedMedia();
    void stalledMedia();

    void indexChanged();

    void audioAvailableChanged();
};
/*                                                                                               */
#endif
