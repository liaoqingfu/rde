#include "clock.h"
/*                                                                                               */
bool Clock::initialize()
{
    context->setContextProperty("Clock",this);
    qmlRegisterType<EventModel>("org.rde.clock",1,0,"EventModel");
    locale=QLocale(QLocale::Dutch,QLocale::Belgium);
    m_initial=new QTimer(this);
    m_initial->setSingleShot(true);
    int interval=(60-QTime::currentTime().second())*1000;
    m_initial->setInterval(interval);
    connect(m_initial,SIGNAL(timeout()),this,SLOT(minuteStarted()));
    m_initial->start();
    updateTime();
    return true;
}
/*                                                                                               */
void Clock::minuteStarted()
{
    m_initial->deleteLater();
    updateTime();
    startTimer(60000,Qt::VeryCoarseTimer);
}
/*                                                                                               */
void Clock::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    updateTime();
}
/*                                                                                               */
void Clock::updateTime()
{
    time=QTime::currentTime();
    if(time.minute()==0){
        if(time.hour()==0){
            QDate currentDate=QDate::currentDate();
            emit announceTime(currentDate.toString("'today is' dddd dd MMMM yyyy"));
            emit dateChanged();
            //qDebug() << currentDate.toString("'today is' dddd dd MMMM yyyy");
        }
        else{
            QString str="the time is ";
            str.append(time.hour());
            str.append(" o clock");
            //+time.hour()+" o clock";
            emit announceTime(str);
        }
        // new hour
        //constructSpeech();
        emit hourChanged();
    }
    emit minuteChanged();
}
/*                                                                                               */
void Clock::constructSpeech()
{
    emit announceTime("new hour");
}
/*                                                                                               */