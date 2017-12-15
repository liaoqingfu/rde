#ifndef EVENT_H
#define EVENT_H
#include <QString>
class Event
{    
public:
    explicit Event(const int &newHour, const int &newMinute,const int &newSecond,const QString &newDescription);
    QString getDescription()const{return description;}
    int getHour()const{return hour;}
    int getMinute()const{return minute;}
    int getSecond()const{return second;}

private:    
    int hour;
    int minute;
    int second;
    QString description;
};
#endif