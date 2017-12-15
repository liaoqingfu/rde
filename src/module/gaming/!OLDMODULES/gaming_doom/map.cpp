#include "map.h"
/*                                                                                               */
Map::Map(const QString &file):File(file)
{
    maps.append(this);
}
/*                                                                                               */
QVector<Map*> Map::maps;