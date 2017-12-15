#include "mediaplayer.h"
/*                                                                                               */
bool MediaPlayer::initialize()
{
    //    foreach (const QAudioDeviceInfo &deviceInfo, QAudioDeviceInfo::availableDevices(QAudio::AudioOutput)){
    //        qDebug() << "Device name: " << deviceInfo.deviceName();
    //        QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    //        qDebug() << info.deviceName();
    //        qDebug() << info.supportedCodecs();
    //    }

    m_player=Player::instance();
    m_player->setParent(this);

    //connect(m_player,SIGNAL(bufferStatusChanged(int)),this,SLOT(bufferStatusChanged(int)));
    //connect(m_player,SIGNAL(bufferStatusChanged(int)),this,SIGNAL(bufferStatusChanged(int)));
    connect(m_player,SIGNAL(durationChanged(qint64)),this,SIGNAL(durationChanged(qint64)));
    connect(m_player,SIGNAL(metaDataAvailableChanged(bool)),this,SLOT(metaDataAvailable(bool)));
    connect(m_player,SIGNAL(mutedChanged(bool)),this,SLOT(mutedChanged(bool)));
    connect(m_player,SIGNAL(playbackRateChanged(qreal)),this,SLOT(playbackRateChanged(qreal)));
    connect(m_player,SIGNAL(positionChanged(qint64)),this,SIGNAL(positionChanged(qint64)));
    connect(m_player,SIGNAL(seekableChanged(bool)),this,SLOT(seekableChanged(bool)));
    connect(m_player,SIGNAL(volumeChanged(int)),this,SLOT(volumeChanged(int)));
    connect(m_player,SIGNAL(noMedia()),this,SIGNAL(noMedia()));
    connect(m_player,SIGNAL(loadingMedia()),this,SIGNAL(loadingMedia()));
    connect(m_player,SIGNAL(loadedMedia()),this,SIGNAL(loadedMedia()));
    connect(m_player,SIGNAL(stalledMedia()),this,SIGNAL(stalledMedia()));

    m_player->setPlaybackRate(settings->value("rate",m_player->playbackRate()).toReal());
    m_player->playlist()->setPlaybackMode(QMediaPlaylist::PlaybackMode(settings->value("mode",m_player->playlist()->playbackMode()).toInt()));

    //qDebug() << "Crossfading enabled?" << canCrossFade();

    //    m_probe=new Probe(this);
    //    m_probe->setSource(m_player);

    //emit speedChanged();

    //    m_allowStop=false;
    //    m_allowPlay=false;
    //    m_allowNext=false;
    //    m_allowPrevious=false;
    //    m_allowSeeking=false;
    //    m_allowRepeat=false;
    //    m_allowShuffle=false;
    //    m_allowSpeed=false;
    //    m_allowMute=true;




    //    //setMode(settings.value("index",0).toInt());
    //    m_player->setPlaybackRate(settings.value("speed",1).toReal());

    //    //m_currentPlaylist=settings.value("CurrentPlaylist").toString();

    //    //setPlaylist(settings.value("CurrentPlaylist").toString());
    //    //m_playlist->setCurrentIndex(settings.value("PlaylistIndex",0).toInt());

    //    //    m_playlist->load(QUrl::fromLocalFile(m_currentPlaylist));


    qmlRegisterType<PlaylistModel>(URI,1,0,"PlaylistModel");
    qmlRegisterType<LibraryModel>(URI,1,0,"LibraryModel");
    qmlRegisterType<PlaylistsModel>(URI,1,0,"PlaylistsModel");
    qmlRegisterType<StreamsModel>(URI,1,0,"StreamsModel");
    qmlRegisterType<Importer>(URI,1,0,"Importer");
    qmlRegisterType<CDTrackModel>(URI,1,0,"CDTrackModel");
    context->parentContext()->setContextProperty("MediaPlayer",this);


    return true;
}
/*                                                                                               */
void MediaPlayer::openFile(const QString &file)
{
    //qDebug() << "Mediaplayer opens file " << file;


    //m_playlist->addMedia(QMediaContent(QUrl::fromLocalFile(file)));
    m_player->playlist()->addMedia(QMediaContent(QUrl::fromLocalFile(file)));


}
/*                                                                                               */
void MediaPlayer::openPlaylist(const QString &playlist)
{
    m_player->playlist()->clear();
    m_player->playlist()->load(QUrl::fromLocalFile(playlist));
}
/*                                                                                               */
void MediaPlayer::openStream(const QString &stream)
{
    //qDebug() << "Mediaplayer opens stream " << stream;
    m_player->playlist()->clear();
    m_player->playlist()->load(QUrl::fromLocalFile(stream));
}
/*                                                                                               */
//void MediaPlayer::setMedia(const QString &file)
//{

//    qDebug() << "Setting media to " << file;

//    m_playlist->addMedia(QMediaContent(QUrl::fromLocalFile(file)));


//    //    switch(m_mode){
//    //    case Library:
//    //        qDebug() << "Opening a library track!";
//    //        m_playlist->addMedia(QMediaContent(QUrl::fromLocalFile(file)));

//    //        //Playlist::insta
//    //        break;
//    //    case Playlist:
//    //        m_playlist->clear();
//    //        m_playlist->load(QUrl::fromLocalFile(file));
//    //        break;
//    //    case Stream:{
//    //        m_playlist->clear();
//    //        m_playlist->load(QUrl::fromLocalFile(file));
//    //        //        QSettings settings(file,QSettings::NativeFormat);
//    //        //        settings.beginGroup("playlist");
//    //        //        qDebug() << "LOADING STREAM" << settings.value("File1").toString();

//    //        //        m_player->setMedia(QUrl(settings.value("File1").toString()));

//    //        //        settings.endGroup();
//    //        break;
//    //    }
//    //        //m_player->setMedia(QUrl::fromLocalFile(file));
//    //        //qDebug() << "Opening a stream!";
//    //        //m_playlist->load(QUrl::fromLocalFile(file));

//    //    case Disc:
//    //        qDebug() << "Opening a disc!";
//    //        break;
//    //    }


//    //    //qDebug() << "Media Player receives media " << file;

//    //    //    QMimeDatabase db;
//    //    //    QMimeType type=db .mimeTypeForFile(file);
//    //    //    if(type.isValid()){
//    //    //        if(type.name().endsWith("mpegurl") or type.name().endsWith("x-scpls")){
//    //    //            m_currentPlaylist=file;
//    //    //            m_playlist->clear();

//    //    //        }
//    //    //        else{
//    //    //            qDebug() << "File is not a playlist";
//    //    //            qDebug() << "Name:" << type.name();
//    //    //            qDebug() << "Ancestors:" << type.allAncestors();
//    //    //            qDebug() << "Icon name:" << type.iconName();
//    //    //            qDebug() << "Generic Icon Name:" << type.genericIconName();

//    //    //            m_player->setMedia(QMediaContent(QUrl::fromLocalFile(file)));
//    //    //            m_player->play(); // is there a better way?
//    //    //        }
//    //    //    }

//    //    //switch(m_player->hasSupport(db.mimeTypeForFile(url).name())){
//    //    //    switch(m_player->hasSupport("audio/flac")){
//    //    //    case QMultimedia::NotSupported:
//    //    //        qDebug() << "Not supported!";
//    //    //        break;
//    //    //    case QMultimedia::MaybeSupported:
//    //    //        qDebug() << "Maybe supported!";
//    //    //        break;
//    //    //    case QMultimedia::ProbablySupported:
//    //    //        qDebug() << "Probably supported!";
//    //    //        break;
//    //    //    case QMultimedia::PreferredService:
//    //    //        qDebug() << "Preferred service";
//    //    //        break;
//    //    //    }


//}
/*                                                                                               */
void MediaPlayer::metaDataAvailable(const bool &available)
{
    if(available){

        //qDebug() << "Meta available!!";

        //        foreach(QString data,m_player->availableMetaData()){
        //            qDebug() << data << ":" <<m_player->metaData(data).toString();
        //        }
        emit metaChanged();


        //        }

        //qDebug() << m_player->metaData(QMediaMetaData::Title);

        //        emit titleChanged();
        //        emit artistChanged();
        //        emit albumChanged();
        //        emit genreChanged();
        //        emit yearChanged();

        QStringList lines;
        lines << "You are listening to "+title()+" by "+artist();
        lines << "This is "+artist()+" with "+title();
        lines << artist()+", "+title();
        QString line=lines.at(qrand()%lines.size());
        emit announce(line);
    }
}
/*                                                                                               */
void MediaPlayer::bufferStatusChanged(const int &percentFilled)
{
    //qDebug() << "Buffering: " << percentFilled;
}
/*                                                                                               */
//void MediaPlayer::durationChanged(const qint64 &duration)
//{
//    //QTime t(0,0,0);
//    //QTime n=t.addMstopEnabledSecs(duration);
//    //emit setDuration(n.hour(),n.minute(),n.second());

//    emit durationChanged();
//}

/*                                                                                               */
void MediaPlayer::mute()
{
    if(m_player->isMuted())
        m_player->setMuted(false);
    else
        m_player->setMuted(true);
}
/*                                                                                               */
void MediaPlayer::mutedChanged(const bool &muted)
{
    //qDebug() << "Player muted?" << muted;
}
/*                                                                                               */
void MediaPlayer::playbackRateChanged(const qreal &rate)
{
    emit speedChanged();
}
/*                                                                                               */
//void MediaPlayer::positionChanged(const qint64 &position)
//{

//    //QTime t(0,0,0);
//    //QTime n=t.addMSecs(position);
//    //emit setPosition(n.hour(),n.minute(),n.second());
//    emit positionChanged();
//}
/*                                                                                               */
void MediaPlayer::seekableChanged(const bool &seekable)
{
    emit allowSeekingChanged();
}
/*                                                                                               */
void MediaPlayer::volumeChanged(const int &volume)
{
}
/*                                                                                               */
void MediaPlayer::seekBackward()
{
    qint64 position=m_player->position();
    m_player->setPlaybackRate(-1);
    m_player->setPosition(position);
}
/*                                                                                               */
void MediaPlayer::seekForward()
{
    qint64 position=m_player->position();
    m_player->setPlaybackRate(2);
    m_player->setPosition(position);
}
/*                                                                                               */
void MediaPlayer::stopSeeking()
{
    qint64 position=m_player->position();
    m_player->setPlaybackRate(1);
    m_player->setPosition(position);
}
/*                                                                                               */
QString MediaPlayer::title()const
//QVariant MediaPlayer::title()const
{
    if(m_player->currentMedia().isNull())return "title";else return m_player->metaData(QMediaMetaData::Title).toString();
}
/*                                                                                               */
QString MediaPlayer::artist()const

//QVariant MediaPlayer::artist()const
{
    if(m_player->currentMedia().isNull())return "artist";else return m_player->metaData(QMediaMetaData::ContributingArtist).toString();
}
/*                                                                                               */
void MediaPlayer::setSpeed(const qreal &value)
{
    qint64 pos=m_player->position();
    m_player->setPlaybackRate(value);
    m_player->setPosition(pos);
}
/*                                                                                               */
void MediaPlayer::next()
{
    m_player->playlist()->next();
}
/*                                                                                               */
void MediaPlayer::pause()
{
    switch(m_player->state()){
    case QMediaPlayer::PausedState:m_player->play();break;
    case QMediaPlayer::PlayingState:m_player->pause();break;
    case QMediaPlayer::StoppedState:break;
    }
}
/*                                                                                               */
void MediaPlayer::previous()
{
    m_player->playlist()->previous();
}
/*                                                                                               */
void MediaPlayer::shuffle()
{
    m_player->playlist()->setPlaybackMode(QMediaPlaylist::Random);
}
/*                                                                                               */
void MediaPlayer::repeat()
{
    m_player->playlist()->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
}
/*                                                                                               */
void MediaPlayer::closeWindow()
{
}
/*                                                                                               */