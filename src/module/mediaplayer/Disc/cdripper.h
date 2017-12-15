#ifndef CDRIPPER_H
#define CDRIPPER_H
/*                                                                                               */
#include <QProcess>
#include <QDebug>
/*                                                                                               */
class CDRipper : public QObject
{
    Q_OBJECT

public:
    explicit CDRipper(QObject *parent = 0);

private:
    QProcess *m_process;
    QString tempPath;

private slots:
    void readOutput();
    void finished(int exitCode,QProcess::ExitStatus status);
    void error(QProcess::ProcessError error);
};
/*                                                                                               */
#endif