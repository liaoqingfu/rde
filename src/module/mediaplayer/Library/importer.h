#ifndef IMPORTER_H
#define IMPORTER_H
/*                                                                                               */
#include <QtConcurrentRun>
#include <QFutureWatcher>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QQuickItem>
#include <QStandardPaths>
#include <QDirIterator>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
/*                                                                                               */
class Importer : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(int total READ total NOTIFY totalChanged)
    Q_PROPERTY(int trackIndex READ trackIndex NOTIFY trackIndexChanged)
    //Q_PROPERTY(QString file READ file NOTIFY fileChanged) // crashes because mediaplayer doesn't exist yet

public:
    explicit Importer();

public slots:
    void start();

private:
    QStringList m_list;
    QString m_path;
    QList<QString> m_keys;
    QStringList thread();
    QFutureWatcher<QStringList> *m_watcher;
    int total()const{return m_list.size();}
    QMediaPlayer *mediaPlayer;
    QStringList columns;
    int m_trackIndex;
    int trackIndex()const{return m_trackIndex;}
    QString file()const{return mediaPlayer->currentMedia().canonicalUrl().toString();}

private slots:
    void finished();

    void metaDataAvailableChanged(const bool &available);
    void error(QMediaPlayer::Error error);

signals:
    void started();
    void totalChanged();
    void trackIndexChanged();
    void fileChanged();
};
/*                                                                                               */
#endif