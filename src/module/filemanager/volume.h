#ifndef VOLUME_H
#define VOLUME_H
/*                                                                                               */
#include <QString>
/*                                                                                               */
class Volume
{
public:
    Volume(const QString &name,const QString &displayName,const QString &device,const QString &rootPath);
    QString name()const{return m_name;}
    QString displayName()const{return m_displayName;}
    QString device()const{return m_device;}
    QString rootPath()const{return m_rootPath;}

private:
    QString m_name;
    QString m_displayName;
    QString m_device;
    QString m_rootPath;
};
/*                                                                                               */
#endif