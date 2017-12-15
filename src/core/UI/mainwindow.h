#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*                                                                                               */
#include "basewindow.h"
#include "Module/ModuleInterface.h"
/*                                                                                               */
class MainWindow : public BaseWindow
{
    Q_OBJECT
public:
    static MainWindow *instance();

private:
    static MainWindow *m_instance;
    MainWindow();

public slots:
    //void setItem(const QString &res,QObject *object=0);
    void setItem(const QString &res,QQmlContext *context=Service::engine->rootContext());

private:
    QQmlComponent *m_component;
    QQuickItem *m_item=0;
    QQmlContext *m_context;
    QString m_resource=0;
    void ready();

private slots:
    void statusChanged(QQmlComponent::Status status);
    void closing(QQuickCloseEvent *event);
};
/*                                                                                               */
#endif