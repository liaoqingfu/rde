#ifndef MAP_H
#define MAP_H
/*                                                                                               */
#include "file.h"
/*                                                                                               */
class Map:public File
{
public:
    Map(const QString &file);
    static QVector<Map*> maps;
};
/*                                                                                               */
#endif