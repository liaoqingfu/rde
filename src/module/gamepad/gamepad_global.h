#ifndef CLOCK_GLOBAL_H
#define CLOCK_GLOBAL_H
#include <QtCore/qglobal.h>
#if defined(CLOCK_LIBRARY)
#  define CLOCKSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CLOCKSHARED_EXPORT Q_DECL_IMPORT
#endif
#endif