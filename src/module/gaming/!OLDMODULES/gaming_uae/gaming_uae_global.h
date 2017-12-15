#ifndef GAMING_UAE_GLOBAL_H
#define GAMING_UAE_GLOBAL_H
#include <QtCore/qglobal.h>
#if defined(GAMING_UAE_LIBRARY)
#  define GAMING_UAESHARED_EXPORT Q_DECL_EXPORT
#else
#  define GAMING_UAESHARED_EXPORT Q_DECL_IMPORT
#endif
#endif