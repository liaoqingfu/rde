#ifndef COMPOSITOR_H
#define COMPOSITOR_H
/*                                                                                               */
#include "service.h"
#include <QProcess>
/*                                                                                               */
class Compositor : private QObject
{
    Q_OBJECT
    Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged)

public:
    static Compositor *instance();

    bool enabled(){return m_enabled;}
    void setEnabled(const bool &enabled);

private:
    static Compositor *m_instance;
    explicit Compositor();
    bool m_enabled;
    QProcess *m_process;

    void start();
    void stop();

private slots:
    void started();
    void finished(int,QProcess::ExitStatus);

signals:
    void enabledChanged();
};
/*                                                                                               */
#endif