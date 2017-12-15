#ifndef WINDOW_H
#define WINDOW_H
/*                                                                                               */
#include <QQuickItem>
#include "clam/clam.h"
/*                                                                                               */
class Window : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(bool clamReady READ clamReady NOTIFY clamReadyChanged)

public:
    Window();
    bool clamReady();

public slots:

signals:
    void clamReadyChanged(bool ready);
};
/*                                                                                               */
#endif