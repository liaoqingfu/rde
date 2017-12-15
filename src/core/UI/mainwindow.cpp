#include "mainwindow.h"
/*                                                                                               */
MainWindow::MainWindow():BaseWindow("/rde/MainWindow.qml")
{
    Service::engine->rootContext()->setContextProperty("MainWindow",this);
    connect(this,SIGNAL(closing(QQuickCloseEvent*)),this,SLOT(closing(QQuickCloseEvent*)));
    setFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    //setFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::BypassWindowManagerHint);
}
/*                                                                                               */
void MainWindow::setItem(const QString &resource,QQmlContext *context)
{
    m_context=context;
    if(resource==m_resource)
        close();
    else{
        QResource res(resource);
        if(res.isValid()){
            m_resource=resource;
            m_component=new QQmlComponent(Service::engine,this);
            connect(m_component,SIGNAL(statusChanged(QQmlComponent::Status)),this,SLOT(statusChanged(QQmlComponent::Status)));
            m_component->loadUrl(QUrl("qrc:"+res.fileName()),QQmlComponent::Asynchronous);
        }
        else qWarning() << "Could not open resource " << resource;
    }
}
/*                                                                                               */
void MainWindow::statusChanged(QQmlComponent::Status status)
{
    switch(status){
    case QQmlComponent::Null:break;
    case QQmlComponent::Loading:break;
    case QQmlComponent::Ready:{
        if(m_item)
            m_item->deleteLater();
        m_item=qobject_cast<QQuickItem*>(m_component->create(m_context));
        m_item->setParent(this);
        m_item->setParentItem(contentItem());
        showMaximized();
        m_component->deleteLater();
        break;
    }
    case QQmlComponent::Error:
        qWarning() << m_component->errorString();
        m_component->deleteLater();
        break;
    }
}
/*                                                                                               */
void MainWindow::closing(QQuickCloseEvent *event)
{

//    //foreach(QObject *object, m_item->childItems()){
//        foreach(QObject *object, m_item->children()){
//        //qDebug() << "CLOSE!!";
//        //qDebug() << object;
//        object->deleteLater();


//    }


    m_item->deleteLater();
    m_item=0;
    m_context=0;
    m_resource.clear();
}
/*                                                                                               */
void MainWindow::ready()
{
}
/*                                                                                               */
MainWindow* MainWindow::m_instance;
MainWindow* MainWindow::instance(){if(!m_instance)m_instance=new MainWindow;return m_instance;}