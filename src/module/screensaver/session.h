#ifndef SESSION_H
#define SESSION_H
/*                                                                                               */
#include <QProcess>
#include <QDebug>
/*                                                                                               */
class Session : public QObject
{
    Q_OBJECT
public:
    explicit Session(const QString &file,QObject *parent = 0);

private:
    QProcess *process;


private slots:
    void readOutput();
    void error(QProcess::ProcessError error);
    void started();
    void finished(const int &exitCode,QProcess::ExitStatus status);
};
/*                                                                                               */
#endif