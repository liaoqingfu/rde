#ifndef CLOCK_H
/*                                                                                               */
#define CLOCK_H
/*                                                                                               */
#include "clock_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
#include <QTime>
#include <QTimer>
#include <QDate>
#include "eventmodel.h"
/*                                                                                               */
class Clock: public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Clock" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)
    Q_PROPERTY(QVariant date READ date NOTIFY dateChanged)
    Q_PROPERTY(int hours READ getHour NOTIFY hourChanged)
    Q_PROPERTY(int minutes READ getMinute NOTIFY minuteChanged)

public:
    //QVariant date()const{return locale.toString(QDate::currentDate(),"dddd d MMMM yyyy");}
    QVariant date()const{return locale.toString(QDate::currentDate(),"ddd d MMM yy");}

private:
    Type type(){return Dock;}
    bool initialize();
    QLocale locale;
    QTimer *m_initial;
    QTime time;
    void timerEvent(QTimerEvent *event);
    int getHour()const{return time.hour();}
    int getMinute()const{return time.minute();}
    void updateTime();
    void constructSpeech();

private slots:
    void minuteStarted();

signals:
    void dateChanged();
    void hourChanged();
    void minuteChanged();
    void announceTime(QVariant speech);
};
/*                                                                                               */
#endif