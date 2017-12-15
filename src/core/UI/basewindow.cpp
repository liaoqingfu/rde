#include "basewindow.h"
/*                                                                                               */
BaseWindow::BaseWindow(QString url,QWindow *parent):QQuickWindow(parent)
{
    setColor(Qt::transparent);
    setFlags(Qt::FramelessWindowHint);
    QResource res(url);
    if(res.isValid()){
        m_component=new QQmlComponent(Service::engine,this);
        connect(m_component,SIGNAL(statusChanged(QQmlComponent::Status)),this,SLOT(statusChanged(QQmlComponent::Status)));
        connect(m_component,SIGNAL(progressChanged(qreal)),this,SLOT(progressChanged(qreal)));
        m_component->loadUrl(QUrl("qrc:"+res.fileName()),QQmlComponent::Asynchronous);
    }
    else
        qDebug() << "is not valid";
}
/*                                                                                               */
void BaseWindow::statusChanged(QQmlComponent::Status status)
{
    switch(status){
    case QQmlComponent::Null:
        break;
    case QQmlComponent::Loading:
        break;
    case QQmlComponent::Ready:{
        m_item=qobject_cast<QQuickItem*>(m_component->create(Service::engine->rootContext()));
        m_item->setParent(this);
        m_item->setParentItem(contentItem());
        m_component->deleteLater();
        ready();
        //showNormal();
        break;
    }
    case QQmlComponent::Error:
        qWarning() << m_component->errorString();
        m_component->deleteLater();
        break;
    }
}
/*                                                                                               */
void BaseWindow::progressChanged(qreal progress)
{
    //qDebug() << "Progress:" << progress;
}
/*                                                                                               */