#ifndef GAMING_SUPERMODEL_GLOBAL_H
#define GAMING_SUPERMODEL_GLOBAL_H
#include <QtCore/qglobal.h>
#if defined(GAMING_SUPERMODEL_LIBRARY)
#  define GAMING_SUPERMODELSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GAMING_SUPERMODELSHARED_EXPORT Q_DECL_IMPORT
#endif
#endif