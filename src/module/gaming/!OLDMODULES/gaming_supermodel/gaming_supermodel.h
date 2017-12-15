#ifndef GAMING_SUPERMODEL_H
/*                                                                                               */
#define GAMING_SUPERMODEL_H
#define Program "supermodel"
/*                                                                                               */
#include "gaming_supermodel_global.h"
#include "/development/Neon-DE/src/module/gaming/Module/GamingInterface.h"
/*                                                                                               */
class gaming_supermodel:public QObject,public GamingInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "supermodel" FILE "metadata.json")
    Q_INTERFACES(GamingInterface)

public:
    QString program()const{return Program;}
    QStringList getData();
    bool setGame(const QString &game);
};
/*                                                                                               */
#endif