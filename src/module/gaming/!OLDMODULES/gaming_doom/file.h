#ifndef FILE_H
#define FILE_H
/*                                                                                               */
#include <QVector>
#include <QFileInfo>
/*                                                                                               */
class File
{
public:
    File(const QString &path);
    virtual ~File();
    QString path()const{return m_path;}
    QString name()const{QFileInfo info(m_path);return info.baseName();}

protected:
    QString m_path;
};
/*                                                                                               */
#endif