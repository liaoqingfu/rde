#ifndef GAMING_PS2_GLOBAL_H
#define GAMING_PS2_GLOBAL_H
#include <QtCore/qglobal.h>
#if defined(GAMING_PS2_LIBRARY)
#  define GAMING_PS2SHARED_EXPORT Q_DECL_EXPORT
#else
#  define GAMING_PS2SHARED_EXPORT Q_DECL_IMPORT
#endif
#endif