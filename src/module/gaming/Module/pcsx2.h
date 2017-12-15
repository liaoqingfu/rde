#ifndef PCSX2_H
#define PCSX2_H
/*                                                                                               */
#include "module.h"
/*                                                                                               */
class PCSX2 : public Module
{
    Q_OBJECT

public:
    static PCSX2 *instance();
    QStringList importData();
    QStringList arguments(const QString &game);

    QProcessEnvironment processEnvironment()const;

private:
    static PCSX2 *m_instance;
    PCSX2();

    void readError(QString text);
    void readOutput(QString text);
    void failedToStart();
    void normalExit(const int &code);
    void crashed(QByteArray text);
    void crashExit(const int &code);
    void running();
    void notRunning();
};
/*                                                                                               */
#endif