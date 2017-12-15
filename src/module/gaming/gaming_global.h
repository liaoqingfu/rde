#ifndef GAMING_GLOBAL_H
#define GAMING_GLOBAL_H
#include <QtCore/qglobal.h>
#if defined(GAMING_LIBRARY)
#  define GAMINGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GAMINGSHARED_EXPORT Q_DECL_IMPORT
#endif
#endif