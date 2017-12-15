#ifndef DISPLAY_SLIDESHOW_H
#define DISPLAY_SLIDESHOW_H
/*                                                                                               */
#include "display_slideshow_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
#include <QQmlComponent>
#include <QQuickItem>
#include <QResource>
#include <QQuickWindow>
#include <QGuiApplication>
#include <QScreen>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
/*                                                                                               */
class display_slideshow: public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Slideshow" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)

public:
    void suspend();
    void resume();
    void timerEvent(QTimerEvent *event);
    ~display_slideshow();

public slots:
    void setImages(QQuickItem *imageA,QQuickItem *imageB);

private:
    Type type(){return Display;}
    bool initialize();
    bool alt=false;
    QQuickItem *m_imageA;
    QQuickItem *m_imageB;
    QQmlComponent *m_component;
    QQuickItem *m_item;
    QQuickWindow *m_window;
    QStringList m_list;
    QString m_path;
    QString m_currentImage;
    int m_interval;
    void showA();
    void showB();
    QParallelAnimationGroup *m_group;
    QPropertyAnimation *m_fadeA;
    QPropertyAnimation *m_fadeB;
    int m_timerId;
    void scan();
    void nextImage();

private slots:
    void statusChanged(QQmlComponent::Status status);

signals:
    void setA(QVariant source);
    void setB(QVariant source);
};
/*                                                                                               */
#endif