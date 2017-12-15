#ifndef PROGRAM_H
#define PROGRAM_H
/*                                                                                               */
#include <QFile>
#include <QFileInfo>
#include <QFileSystemWatcher>
#include <QFutureWatcher>
#include <QStandardPaths>
#include <QCryptographicHash>
#include <QtConcurrentRun>
#include <QSettings>
/*                                                                                               */
class Program : public QObject
{
    Q_OBJECT
public:
    explicit Program(const QString name,QObject *parent = 0);
    bool initialize();
    bool isValid()const;
    int getMajorVersion()const{return m_versionMajor;}
    float getMinorVersion()const{return m_versionMinor;}

    //QString path()const{return m_path;}
    QString path()const{return fileWatcher->files().at(0);}


    QByteArray getMd5();
    QString programName()const{return m_programName;}

private:
    QString findPath()const{return QStandardPaths::findExecutable(m_programName);}

    QString m_programName;
    QString m_path;
    QString m_versionArg;
    QByteArray m_md5;
    int m_versionMajor;
    double m_versionMinor;

    QFileSystemWatcher *fileWatcher;
    QFutureWatcher<QByteArray> *md5Watcher;
    //QFutureWatcher<QByteArray> *versionWatcher;

private slots:
    void fileChanged(const QString &file);
    void md5Ready();
    //void versionReady();

signals:
    void updated();
    void removed();
};
/*                                                                                               */
#endif