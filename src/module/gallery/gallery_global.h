#ifndef GALLERY_GLOBAL_H
#define GALLERY_GLOBAL_H
#include <QtCore/qglobal.h>
#if defined(GALLERY_LIBRARY)
#  define GALLERYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GALLERYSHARED_EXPORT Q_DECL_IMPORT
#endif
#endif