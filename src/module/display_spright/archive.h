#ifndef ARCHIVE_H
#define ARCHIVE_H
#define CHUNK 16384
/*                                                                                               */
#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
#  include <fcntl.h>
#  include <io.h>
#  define SET_BINARY_MODE(file) setmode(fileno(file), O_BINARY)
#else
#  define SET_BINARY_MODE(file)
#endif
/*                                                                                               */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "zlib.h"
#include <QString>
#include <QDebug>
/*                                                                                               */
class Archive
{
public:
    explicit Archive();
    void compress(QString source,QString destination,int level);
    void decompress(QString source,QString dest);

private:
    int def(FILE *source, FILE *dest, int level);
    int inf(FILE *source, FILE *dest);
    void zerr(int ret);
    int ret;
};
/*                                                                                               */
#endif