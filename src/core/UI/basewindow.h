#ifndef BASEWINDOW_H
#define BASEWINDOW_H
/*                                                                                               */
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickWindow>
#include <QQuickItem>
#include <QResource>
#include <QDebug>
#include "service.h"
/*                                                                                               */
class BaseWindow:public QQuickWindow
{
    Q_OBJECT
public:
    BaseWindow(QString url,QWindow *parent=0);
    //virtual ~BaseWindow();

private:
    QQmlComponent *m_component;

protected:
    virtual void ready()=0;
    QQuickItem *m_item;

public slots:
    void statusChanged(QQmlComponent::Status status);
    void progressChanged(qreal progress);
};
/*                                                                                               */
#endif
