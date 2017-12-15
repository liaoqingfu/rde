#include "display_spright.h"
/*                                                                                               */
bool display_spright::initialize()
{
    m_manager=FighterManager::instance();

    //m_archive=new Archive();
    //Player *player=new Player(this);
    //    Fighter::context=context;
    //    m_context->setContextProperty("Spright",this);
    //    qmlRegisterType<ArenaItem>("org.neon.spright",1,0,"ArenaItem");

    //    //qmlRegisterType<FighterModel>("org.neon.spright",1,0,"SpriteModel");

    //    qmlRegisterType<CharacterModel>("org.neon.spright",1,0,"CharacterModel");



    //    qmlRegisterType<FighterItem>("org.neon.spright",1,0,"FighterItem");

    //    m_window=new QQuickWindow();
    //    m_window->setGeometry(QGuiApplication::primaryScreen()->geometry());
    //    m_window->setTitle("Neon-Desktop-Spright");
    //    m_window->setColor(Qt::black);

    //    connect(m_window,SIGNAL(closing(QQuickCloseEvent*)),this,SLOT(closeEvent(QQuickCloseEvent*)));

    //    //m_window->setFlags(Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint|Qt::WindowStaysOnBottomHint|Qt::WindowDoesNotAcceptFocus|Qt::WindowTransparentForInput);//Qt::BypassWindowManagerHint
    //    QResource resource("/Spright/Arena.qml");
    //    if(resource.isValid()){
    //        m_component=new QQmlComponent(m_context->engine(),this);
    //        connect(m_component,SIGNAL(statusChanged(QQmlComponent::Status)),this,SLOT(statusChanged(QQmlComponent::Status)));
    //        m_component->loadUrl(QUrl("qrc:"+resource.fileName()),QQmlComponent::Asynchronous);
    //        return true;
    //    }
    //return false;
    return true;
}
/*                                                                                               */
void display_spright::suspend()
{
    //killTimer(m_timerId);
}
/*                                                                                               */
void display_spright::resume()
{
    //m_timerId=startTimer(5000);
}
/*                                                                                               */
//void display_spright::statusChanged(QQmlComponent::Status status)
//{
//    switch(status){
//    case QQmlComponent::Null:break;
//    case QQmlComponent::Loading:break;
//    case QQmlComponent::Ready:
//        m_item=qobject_cast<QQuickItem*>(m_component->create(m_context));
//        m_item->setParentItem(m_window->contentItem());
//        m_item->setParent(this);
//        m_window->showNormal();
//        break;
//    case QQmlComponent::Error:
//        break;
//    }
//}
/*                                                                                               */
//void display_spright::closeEvent(QQuickCloseEvent *event)
//{
//    deleteLater();
//}
/*                                                                                               */
//display_spright::~display_spright()
//{
//    m_window->close();
//    m_window->deleteLater();
//    m_window=NULL;
//}
/*                                                                                               */