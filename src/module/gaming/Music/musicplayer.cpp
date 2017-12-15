#include "musicplayer.h"
/*                                                                                               */
MusicPlayer::MusicPlayer()
{
    m_player=new QMediaPlayer(this,QMediaPlayer::LowLatency);
    m_player->setVolume(50);
    connect(m_player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),this,SLOT(mediaStatusChanged(QMediaPlayer::MediaStatus)));
    connect(m_player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(stateChanged(QMediaPlayer::State)));
    connect(m_player,SIGNAL(error(QMediaPlayer::Error)),this,SLOT(error(QMediaPlayer::Error)));
}
/*                                                                                               */
void MusicPlayer::playMusic(QString module,QString game)
{
    //    QDir dir("/gamemeta/music/"+module);

    //    foreach (QFileInfo fileInfo, dir.entryInfoList(stringList.mid(level, 1))) {
    //            if (fileInfo.isDir() && fileInfo.isReadable())
    //                traverse(pattern, fileInfo.filePath(), level+1);
    //            else if (stringList.size() == (level + 1))
    //                qDebug() << fileInfo.filePath();
    //        }


    QStringList exts;

    exts << "vgm";
    exts << "vgz";
    exts << "spc";
    exts << "flac";



    //    QFileInfo info("/gamemeta/music/"+module+"/"+game+".vgm");
    //    if(info.isReadable()){}
    //    else{
    //        info.setFile("/gamemeta/music/"+module+"/"+game+".spc");
    //        if(info.isReadable()){}
    //        else{
    //            info.setFile("/gamemeta/music/"+module+"/"+game+".vgz");
    //        }
    //    }


    //    QStringList f;
    //    f << game;



    //    //dir.setFilter(QDir::Files);

    //    //setf
    //    //dir.setNameFilters(QStringList(game));


    //    qDebug() << "Looking in" << dir.absolutePath();
    //    foreach (QString s, dir.entryList()) {
    //        qDebug() << "Found " << s;
    //    }

    //QFileInfo info("GameMusic:/"+module+"/"+game);


    //qDebug() << "GameMusic" << info.absoluteFilePath();

    //QFileInfo

    //QPixmap pixmap("GameLogo:/"+id+".png","png");

    //QDir dir("/gamemeta/music/");



    //    QString file="/gamemeta/music/"+module+"/"+game+".spc";


    //    QFileInfo info(file);
    //    if(info.exists())
    //        m_player->setMedia(QMediaContent(QUrl::fromLocalFile(file)));
    //    else
    //        m_player->stop();
}
/*                                                                                               */
void MusicPlayer::stateChanged(QMediaPlayer::State state)
{
    switch(state){
    case QMediaPlayer::PausedState:break;
    case QMediaPlayer::PlayingState:
        qDebug() << "Music player is playing " << m_player->currentMedia().canonicalUrl().toLocalFile();
        break;
    case QMediaPlayer::StoppedState:break;
    }
}
/*                                                                                               */
void MusicPlayer::mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    switch(status){
    case QMediaPlayer::UnknownMediaStatus:break;
    case QMediaPlayer::NoMedia:break;
    case QMediaPlayer::LoadingMedia:break;
    case QMediaPlayer::LoadedMedia:
        m_player->play();
        break;
    case QMediaPlayer::StalledMedia:break;
    case QMediaPlayer::BufferingMedia:break;
    case QMediaPlayer::BufferedMedia:break;
    case QMediaPlayer::EndOfMedia:break;
    case QMediaPlayer::InvalidMedia:break;
    }
}
/*                                                                                               */
void MusicPlayer::error(QMediaPlayer::Error error)
{
    switch(error){
    case QMediaPlayer::NoError:
        qDebug() << "Game Music: No Error";
        break;
    case QMediaPlayer::ResourceError:
        qDebug() << "Game Music: Resource Error";
        //m_player->playlist()->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

        break;
    case QMediaPlayer::FormatError:{
        qDebug() << "Game Music: Format Error";
        //m_player->playlist()->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
        break;

        //        if(m_process->isOpen())
        //            m_process->close();


        //        QStringList args;
        //        args << "vgmplay" << "-bitb" << m_player->currentMedia().canonicalUrl().toString().mid(7);
        //        m_process->setArguments(args);
        //        m_process->setWorkingDirectory("/mame");
        //        if(m_process->open());
        //break;
    }
    case QMediaPlayer::NetworkError:
        qDebug() << "Game Music: Network Error";
        break;
    case QMediaPlayer::AccessDeniedError:
        qDebug() << "Game Music: Access Denied";
        break;
    case QMediaPlayer::ServiceMissingError:
        qDebug() << "Game Music: Service Missing";
        break;
    }
}
/*                                                                                               */
void MusicPlayer::pause()
{
    switch(QMediaPlayer::PlayingState){
    case QMediaPlayer::StoppedState:break;
    case QMediaPlayer::PlayingState:m_player->pause();break;
    case QMediaPlayer::PausedState:m_player->play();break;
    }
}
/*                                                                                               */