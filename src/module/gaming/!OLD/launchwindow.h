#ifndef LAUNCHWINDOW_H
#define LAUNCHWINDOW_H
/*                                                                                               */
#include <QQuickItem>
#include <QDebug>
#include <QQmlComponent>
#include "Module/module.h"
#include "launchwindowitem.h"
/*                                                                                               */
class LaunchWindow : public QQuickItem
{
    Q_OBJECT
public:
    LaunchWindow(const QString &IID,QQuickItem *parent);

private:
    QQmlComponent *m_component;
    LaunchWindowItem *m_item;
    void keyPressEvent(QKeyEvent *event);

private slots:
    void statusChanged(QQmlComponent::Status status);

signals:
    void launch();
};
/*                                                                                               */
#endif