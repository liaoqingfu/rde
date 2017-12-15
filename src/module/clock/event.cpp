#include "event.h"

Event::Event(const int &newHour, const int &newMinute, const int &newSecond, const QString &newDescription)
{
    hour=newHour;
    minute=newMinute;
    second=newSecond;
    description=newDescription;
}