#ifndef MONITOR_H
#define MONITOR_H
/*                                                                                               */
#include <QFile>
#include <QTimer>
/*                                                                                               */
class Monitor : public QObject
{
    Q_OBJECT
public:
    explicit Monitor(const qint64 id,QObject *parent = 0);
    ~Monitor();

private:
    QFile *file;
    QString path;
    int processID;
    QTimer *timer;

private slots:
    void update();
};
/*                                                                                               */
#endif