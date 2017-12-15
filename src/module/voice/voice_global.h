#ifndef VOICE_GLOBAL_H
#define VOICE_GLOBAL_H
#include <QtCore/qglobal.h>
#if defined(VOICE_LIBRARY)
#  define VOICESHARED_EXPORT Q_DECL_EXPORT
#else
#  define VOICESHARED_EXPORT Q_DECL_IMPORT
#endif
#endif