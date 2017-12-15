#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H
/*                                                                                               */
#include "citra.h"
#include "dolphin.h"
#include "doom.h"
#include "mame.h"
#include "pcsx2.h"
#include "ppsspp.h"
#include "retro.h"
#include "supermodel.h"
#include "wine.h"

#include <QDebug>
#include <QStandardPaths>
/*                                                                                               */
class ModuleManager : public QObject
{
    Q_OBJECT
public:
    static ModuleManager *instance();

private:
    ModuleManager();
    static ModuleManager *m_instance;
};
/*                                                                                               */
#endif