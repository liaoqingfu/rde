#ifndef GAMING_RETRO_GLOBAL_H
#define GAMING_RETRO_GLOBAL_H
#include <QtCore/qglobal.h>
#if defined(GAMING_RETRO_LIBRARY)
#  define GAMING_RETROSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GAMING_RETROSHARED_EXPORT Q_DECL_IMPORT
#endif
#endif