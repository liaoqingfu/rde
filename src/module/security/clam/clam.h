#ifndef CLAM_H
#define CLAM_H
/*                                                                                               */
#define Program "clamscan"
/*                                                                                               */
#include <QProcess>
#include <QStandardPaths>
#include <QFileSystemWatcher>
#include <QDebug>
/*                                                                                               */
class Clam : public QObject
{
    Q_OBJECT

public:
    static Clam *instance();
    bool isReady(){return m_ready;}

public slots:
    void scan(const QString &dir);

private:
    Clam();
    static Clam *m_instance;
    QProcess *m_process;
    QFileSystemWatcher *m_watcher;
    bool m_ready=false;

private slots:
    void fileChanged(QString file);
    void readError();
    void readOutput();
    void started();
    void finished(const int &exitCode,QProcess::ExitStatus status);
};
/*                                                                                               */
#endif