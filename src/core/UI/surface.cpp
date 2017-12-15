#include "surface.h"
/*                                                                                               */
Surface::Surface()
{
    component=new QQmlComponent(Service::engine,this);
    connect(component,SIGNAL(statusChanged(QQmlComponent::Status)),this,SLOT(statusChanged(QQmlComponent::Status)));
    m_animGroup=new QParallelAnimationGroup(this);
}
/*                                                                                               */
void Surface::setPath(const QString &path,QQmlContext *context)
{
    QResource res(path);
    QFileInfo info(path);

    if(res.isValid()){
        m_path=path;
        component->loadUrl(QUrl("qrc:"+res.fileName()),QQmlComponent::Asynchronous);
    }
    else if(info.isReadable()){
        m_path=path;
        component->loadUrl(QUrl(path),QQmlComponent::Asynchronous);
    }
}
/*                                                                                               */
void Surface::statusChanged(QQmlComponent::Status status)
{
    switch(status){
    case QQmlComponent::Null:
        break;
    case QQmlComponent::Loading:{
        break;
    }
    case QQmlComponent::Ready:{
        if(m_item){
            m_fadeOut=new QPropertyAnimation(m_item,"opacity",this);
            connect(m_fadeOut,SIGNAL(finished()),this,SLOT(fadeOutFinished()));
            m_fadeOut->setStartValue(1);
            m_fadeOut->setEndValue(0);
            m_fadeOut->setDuration(Duration);
            m_animGroup->addAnimation(m_fadeOut);
        }
        m_item=qobject_cast<QQuickItem*>(component->create(Service::engine->rootContext()));
        m_item->setParent(this);
        m_item->setParentItem(this);
        m_fadeIn=new QPropertyAnimation(m_item,"opacity",this);
        connect(m_fadeIn,SIGNAL(finished()),this,SLOT(fadeInFinished()));
        m_fadeIn->setStartValue(0);
        m_fadeIn->setEndValue(1);
        m_fadeIn->setDuration(Duration);
        m_animGroup->addAnimation(m_fadeIn);
        m_animGroup->start();
        emit pathChanged();
        break;
    }
    case QQmlComponent::Error:
        qWarning() << "Surface: Error: " << component->errorString();
        //component->deleteLater();
        break;
    }
}
/*                                                                                               */
void Surface::fadeInFinished()
{
    m_fadeIn->deleteLater();
}
/*                                                                                               */
void Surface::fadeOutFinished()
{
    m_fadeOut->targetObject()->deleteLater();
    m_fadeOut->deleteLater();
}
/* eof                                                                                           */