#ifndef LAUNCHER_GLOBAL_H
#define LAUNCHER_GLOBAL_H
#include <QtCore/qglobal.h>
#if defined(LAUNCHER_LIBRARY)
#  define LAUNCHERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LAUNCHERSHARED_EXPORT Q_DECL_IMPORT
#endif
#endif