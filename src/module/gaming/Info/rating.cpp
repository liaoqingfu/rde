#include "rating.h"
/*                                                                                               */
Rating::Rating()
{
    QSettings dat("/mame/ui/dat/rating.dat");
    dat.beginGroup("Rating");


    foreach(QString key,dat.allKeys()){
        map.insert(key,dat.value(key).toInt());
    }

    dat.endGroup();
}
/*                                                                                               */
void Rating::updateRating(const QString &module, const QString &game)
{
    //qDebug() << "Retrieving rating for " << game << " on " << module;
}
/*                                                                                               */