#ifndef SURFACE_H
#define SURFACE_H
#define Duration 200
/*                                                                                               */
#include "service.h"
#include <QQuickItem>
#include <QQmlComponent>
#include <QResource>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QFileInfo>
/*                                                                                               */
class Surface : public QQuickItem
{
    Q_OBJECT

public:
    Surface();

public slots:

    void setPath(const QString &path,QQmlContext *context=0);

private:
    QQmlComponent *component;
    QQuickItem *m_item=NULL;
    QString m_path;
    QString path()const{return m_path;}

    QParallelAnimationGroup *m_animGroup;
    QPropertyAnimation *m_fadeIn;
    QPropertyAnimation *m_fadeOut=NULL;

private slots:
    void statusChanged(QQmlComponent::Status status);
    void fadeInFinished();
    void fadeOutFinished();

signals:
    void pathChanged();
};
/*                                                                                               */
#endif
