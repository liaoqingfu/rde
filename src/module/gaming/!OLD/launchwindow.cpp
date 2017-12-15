#include "launchwindow.h"
/*                                                                                               */
LaunchWindow::LaunchWindow(const QString &IID,QQuickItem *parent):QQuickItem(parent)
{
    setWidth(1024);
    setHeight(768);
    setVisible(false);
    m_component=new QQmlComponent(Module::context->engine(),this);
    connect(m_component,SIGNAL(statusChanged(QQmlComponent::Status)),this,SLOT(statusChanged(QQmlComponent::Status)));
    m_component->loadUrl(QUrl("qrc:/"+IID+"/Launch.qml"),QQmlComponent::Asynchronous);
}
/*                                                                                               */
void LaunchWindow::statusChanged(QQmlComponent::Status status)
{
    switch(status){
    case QQmlComponent::Null:break;
    case QQmlComponent::Loading:break;
    case QQmlComponent::Ready:{
        m_item=qobject_cast<LaunchWindowItem*>(m_component->create(Module::context));
        m_item->setParent(this);
        m_item->setParentItem(this);
        m_item->forceActiveFocus();
        m_component->deleteLater();
        setVisible(true);
        break;
    }
    case QQmlComponent::Error:
        qWarning() << m_component->errorString();
        m_component->deleteLater();
        break;
    }
}
/*                                                                                               */
void LaunchWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape){
        parentItem()->forceActiveFocus();
        deleteLater();
    }
    else if(event->key()==Qt::Key_Return){
        emit launch();
    }
}
/*                                                                                               */