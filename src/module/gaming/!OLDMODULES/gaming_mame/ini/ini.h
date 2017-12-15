#ifndef INI_H
#define INI_H
#include <QFile>
#include <QFileSystemWatcher>
#include <QFutureWatcher>
#include <QMap>
//#include <QtConcurrentRun>
class Ini : public QObject
{
    Q_OBJECT
public:
    explicit Ini(const QString &newFile,QObject *parent = 0);
    QString getFile()const{return file;}
protected:
    QString file;
    QMap<QString,QVariant> settings;
private:
    QMap<QString,QVariant> thread(const QString &file);
    QFileSystemWatcher *fileWatcher;
    QFutureWatcher<QMap<QString,QVariant> > *watcher;
    virtual void readSettingsReady()=0;

private slots:
    void fileChanged(const QString &file);
    void finished();
};
#endif
