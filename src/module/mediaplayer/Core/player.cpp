#include "player.h"
/*                                                                                               */
Player::Player():QMediaPlayer(NULL,QMediaPlayer::StreamPlayback)
{
    //connect(this,SIGNAL(audioAvailableChanged(bool)),this,SLOT(audioAvailableChanged(bool)));
    connect(this,SIGNAL(currentMediaChanged(QMediaContent)),this,SLOT(currentMediaChanged(QMediaContent)));
    connect(this,SIGNAL(error(QMediaPlayer::Error)),this,SLOT(error(QMediaPlayer::Error)));
    connect(this,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),this,SLOT(mediaStatusChanged(QMediaPlayer::MediaStatus)));
    connect(this,SIGNAL(networkConfigurationChanged(QNetworkConfiguration)),this,SLOT(networkConfigurationChanged(QNetworkConfiguration)));
    connect(this,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(stateChanged(QMediaPlayer::State)));
    connect(this,SIGNAL(videoAvailableChanged(bool)),this,SLOT(videoAvailableChanged(bool)));
    m_playlistFile=QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation).at(0)+"/playlist.m3u";
    m_playlist=new QMediaPlaylist(this);
    setPlaylist(m_playlist);
    connect(m_playlist,SIGNAL(loaded()),this,SLOT(play()));
    m_playlist->load(QUrl::fromLocalFile(m_playlistFile));

    //QAudioOutputSelectorControl *ctl=qobject_cast<QAudioOutputSelectorControl *>(service()->requestControl(QAudioOutputSelectorControl_iid));
    //qDebug() << ctl;

    //QMediaGaplessPlaybackControl *control=service()->requestControl<QMediaGaplessPlaybackControl*>();
    //qDebug() << control;

}
/*                                                                                               */
//void Player::audioAvailableChanged(const bool &available)
//{
//    //    if(available);
//    //    else{};
//}
/*                                                                                               */
void Player::currentMediaChanged(const QMediaContent &content)
{
    //    if(!content.isNull()){
    //        QString str=content.canonicalUrl().toString();
    //        if(str.startsWith("file:")){
    //            qDebug() << "LOCAL FILE!";
    ////            m_allowSpeed=true;
    ////            m_allowSeeking=true;
    ////            m_allowRepeat=true; // if playlist
    ////            m_allowShuffle=true; // if playlist
    //        }
    //        else if(str.startsWith("http:")){
    //            qDebug() << "STREAM!";
    ////            m_allowSpeed=false;
    ////            m_allowSeeking=false;
    ////            m_allowPrevious=false;
    ////            m_allowNext=false;
    ////            m_allowRepeat=false;
    ////            m_allowShuffle=false;
    ////            emit allowPreviousChanged();
    ////            emit allowNextChanged();
    //            //        }
    //            //        emit allowSpeedChanged();
    //            //        emit allowSeekingChanged();
    //            //        emit allowRepeatChanged();
    //            //        emit allowShuffleChanged();
    //        }
    //    }
}
/*                                                                                               */
void Player::error(QMediaPlayer::Error error)
{
    switch(error){
    case QMediaPlayer::NoError:
        //qDebug() << "Media Player: No error";
        break;
    case QMediaPlayer::ResourceError:
        playlist()->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
        if(errorString()==ResourceNotFound)
            emit resourceNotFound(currentMedia().canonicalUrl().toLocalFile());
        break;
    case QMediaPlayer::FormatError:
        playlist()->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
        emit formatError();
        break;
    case QMediaPlayer::AccessDeniedError:
        playlist()->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
        emit accessDeniedError();
        break;
    case QMediaPlayer::NetworkError:
        playlist()->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
        emit networkError();
        break;
    case QMediaPlayer::ServiceMissingError:
        playlist()->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
        emit serviceMissingError();
        break;
    }
}
/*                                                                                               */
void Player::mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    switch(status){
    case QMediaPlayer::UnknownMediaStatus:
        qDebug() << "MediaPlayer: Unknown Media Status";
        break;
    case QMediaPlayer::NoMedia:

        emit noMedia();

        //qDebug() << "MediaPlayer: No Media Status";
        //m_allowPlay=false;
        //m_allowStop=false;
        //emit allowPlayChanged();
        //emit allowStopChanged();
        break;
    case QMediaPlayer::LoadingMedia:
        emit loadingMedia();
        break;
    case QMediaPlayer::LoadedMedia:
        emit loadedMedia();
        // it is tempting to put play() here, but stopping the player will enter this state also, causing the music to restart when pressing stop
        //play();
        break;
    case QMediaPlayer::StalledMedia:
        emit stalledMedia();
        break;
    case QMediaPlayer::BufferingMedia:
        emit bufferingMedia();
        break;
    case QMediaPlayer::BufferedMedia:
        emit bufferedMedia();
        break;
    case QMediaPlayer::EndOfMedia:
        emit endOfMedia();
        //qDebug() << "MediaPlayer: End of Media Status";
        break;
    case QMediaPlayer::InvalidMedia:
        //qDebug() << "MediaPlayer: Invalid Media Status";
        break;
    }
}
/*                                                                                               */
void Player::stateChanged(QMediaPlayer::State state)
{
    switch(state){
    case QMediaPlayer::PlayingState:
        //qDebug() << "MediaPlayer: Playing";
        //m_allowSeeking=true;
        //m_allowStop=true;
        //emit allowSeekingChanged();
        //emit allowStopChanged();

        // change button icon to pause?
        break;
    case QMediaPlayer::PausedState:
        //qDebug() << "MediaPlayer: Paused";
        break;
    case QMediaPlayer::StoppedState:
        //qDebug() << "MediaPlayer: Stopped";
        //m_allowSeeking=false;
        //m_allowStop=false;
        //m_allowPlay=true;
        //emit allowSeekingChanged();
        //emit allowStopChanged();
        //emit allowPlayChanged();
        break;
    }
}
/*                                                                                               */
void Player::networkConfigurationChanged(const QNetworkConfiguration &config)
{
}
/*                                                                                               */
void Player::videoAvailableChanged(const bool &available)
{
}
/*                                                                                               */
void Player::savePlaylist()
{
    if(m_playlist->save(QUrl::fromLocalFile(m_playlistFile),"m3u"));
    //qDebug() << "Playlist failed to save";
}
/*                                                                                               */
Player::~Player()
{
    qDebug() << "KILLING PLAYER!!";
}
/*                                                                                               */
Player *Player::m_instance;
Player *Player::instance(){if(!m_instance)m_instance=new Player();return m_instance;}