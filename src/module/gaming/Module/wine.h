#ifndef WINE_H
#define WINE_H
/*                                                                                               */
#define MimeTypeType "application/octet-stream"
#define MimeTypeName "application/x-ms-dos-executable"
/*                                                                                               */
#include "module.h"
#include <QMimeDatabase>
#include <QMimeType>
/*                                                                                               */
class WINE : public Module
{
    Q_OBJECT
public:
    static WINE *instance();
    QStringList importData();
    QStringList arguments(const QString &game);
    QProcessEnvironment processEnvironment()const;

private:
    WINE();
    static WINE *m_instance;
    enum ExitCodes{NoExe=2,FailedToLaunch=5,IsNotValid=87,IsWeird=66,BadExeFormat=193};

    void crashed(QByteArray text);
    void crashExit(const int &code);
    void failedToStart();
    void normalExit(const int &code);
    void readError(QString text);
    void readOutput(QString text);
};
/*                                                                                               */
#endif