#ifndef DISPLAY_XSS_GLOBAL_H
#define DISPLAY_XSS_GLOBAL_H
#include <QtCore/qglobal.h>
#if defined(XSS_LIBRARY)
#  define DISPLAY_XSSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DISPLAY_XSSSHARED_EXPORT Q_DECL_IMPORT
#endif
#endif