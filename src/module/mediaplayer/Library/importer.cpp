#include "importer.h"
/*                                                                                               */
Importer::Importer():QQuickItem()
{
    m_trackIndex=0;
    start();
}
/*                                                                                               */
void Importer::start()
{
    m_trackIndex=0;
    QSqlDatabase db=QSqlDatabase::database("Music");
    if(db.open()){
        db.exec("CREATE TABLE IF NOT EXISTS Music(File primary key,Title,Artist,Album,Genre,Year,Type,BPM)");
        if(db.transaction()){
            m_path=QStandardPaths::standardLocations(QStandardPaths::MusicLocation).at(0);
            QDir dir(m_path);
            if(dir.isReadable()){
                m_watcher=new QFutureWatcher<QStringList>(this);
                connect(m_watcher,SIGNAL(started()),this,SIGNAL(started()));
                connect(m_watcher,SIGNAL(finished()),this,SLOT(finished()));
                m_watcher->setFuture(QtConcurrent::run(this,&Importer::thread));
            }
        }
    }
}
/*                                                                                               */
extern QStringList Importer::thread()
{
    QDir dir(m_path,"*.flac *.mp3 *.wav *.ogg *.xm *.mod *.s3m *.spc *.nsf *.gbs *.sid *.vgm *.mid");
    QStringList l;
    QDirIterator iterator(dir,QDirIterator::Subdirectories);
    while(iterator.hasNext()){
        l << iterator.next();
    }
    l.sort();
    return l;
}
/*                                                                                               */
void Importer::finished()
{
    m_list=m_watcher->result();
    emit totalChanged();

    mediaPlayer=new QMediaPlayer(this);
    connect(mediaPlayer,SIGNAL(error(QMediaPlayer::Error)),this,SLOT(error(QMediaPlayer::Error)));
    connect(mediaPlayer,SIGNAL(metaDataAvailableChanged(bool)),this,SLOT(metaDataAvailableChanged(bool)));
    mediaPlayer->setMedia(QMediaContent(QUrl::fromLocalFile(m_list.at(0))));
}
/*                                                                                               */
void Importer::metaDataAvailableChanged(const bool &available)
{
    if(available){
        QVariant title=mediaPlayer->metaData(QMediaMetaData::Title);
        QVariant artist=mediaPlayer->metaData(QMediaMetaData::ContributingArtist);
        QVariant album=mediaPlayer->metaData(QMediaMetaData::AlbumTitle);
        QVariant genre=mediaPlayer->metaData(QMediaMetaData::Genre);
        QVariant year=mediaPlayer->metaData(QMediaMetaData::Year);
        QSqlDatabase db=QSqlDatabase::database("Music");
        db.exec("INSERT INTO Music VALUES(\""+m_list.at(m_trackIndex)+"\",\""+title.toString()+"\",\""+artist.toString()+"\",\""+album.toString()+"\",\""+genre.toString()+"\",\""+year.toString()+"\",NULL,NULL)");
        m_trackIndex++;
        emit trackIndexChanged();
        if(m_trackIndex < m_list.size())
            mediaPlayer->setMedia(QMediaContent(QUrl::fromLocalFile(m_list.at(m_trackIndex))));
        else{
            if(db.commit())
                deleteLater();
        }
    }
}
/*                                                                                               */
void Importer::error(QMediaPlayer::Error error)
{
    switch(error){
    case QMediaPlayer::NoError:qWarning() << "No Error";break;
    case QMediaPlayer::ResourceError:qWarning() << "Resource Error";m_trackIndex++;mediaPlayer->setMedia(QMediaContent(QUrl::fromLocalFile(m_list.at(m_trackIndex))));break;
    case QMediaPlayer::FormatError:qWarning() << "Format Error";break;
    case QMediaPlayer::AccessDeniedError:qWarning() << "Access Denied";break;
    case QMediaPlayer::NetworkError:qWarning() << "Network Error";break;
    case QMediaPlayer::ServiceMissingError:qWarning() << "Service Missing";break;
    }
}
/*                                                                                               */