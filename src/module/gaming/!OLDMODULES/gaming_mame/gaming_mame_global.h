#ifndef GAMING_MAME_GLOBAL_H
#define GAMING_MAME_GLOBAL_H
#include <QtCore/qglobal.h>
#if defined(GAMING_MAME_LIBRARY)
#  define GAMING_MAMESHARED_EXPORT Q_DECL_EXPORT
#else
#  define GAMING_MAMESHARED_EXPORT Q_DECL_IMPORT
#endif
#endif