#include "monitor.h"
/*                                                                                               */
Monitor::Monitor(const qint64 id,QObject *parent):QObject(parent)
{
    path="/proc/"+QString::number(id)+"/stat";
    file=new QFile(path);
    if(file->open(QIODevice::ReadOnly)){
        timer=new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(update()));
        timer->setInterval(1000);
        timer->start();
    }
}
/*                                                                                               */
void Monitor::update()
{
    file->seek(0);
    QByteArray stats=file->readAll();
    //qDebug() << "Stats:" << stats;
}
/*                                                                                               */
Monitor::~Monitor()
{
    timer->stop();
    file->close();
    file->deleteLater();
    //qDebug() << "Killing monitor!";
}
/*                                                                                               */