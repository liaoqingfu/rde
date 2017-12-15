#include "display_slideshow.h"
/*                                                                                               */
bool display_slideshow::initialize()
{
    m_context->setContextProperty("Slideshow",this);
    QSettings settings;
    settings.beginGroup("Display");
    m_path=settings.value("SlideshowPath").toString();
    m_interval=settings.value("SlideshowInterval",10000).toInt();
    settings.endGroup();
    m_window=new QQuickWindow();
    m_window->setGeometry(QGuiApplication::primaryScreen()->geometry());
    m_window->setTitle("RDE-Slideshow");
    m_window->setColor(Qt::black);
    m_window->setFlags(Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint|Qt::WindowStaysOnBottomHint|Qt::WindowDoesNotAcceptFocus|Qt::WindowTransparentForInput);//Qt::BypassWindowManagerHint
    QResource resource("/Slideshow/Display.qml");
    if(resource.isValid()){
        m_component=new QQmlComponent(m_context->engine(),this);
        connect(m_component,SIGNAL(statusChanged(QQmlComponent::Status)),this,SLOT(statusChanged(QQmlComponent::Status)));
        m_component->loadUrl(QUrl("qrc:"+resource.fileName()),QQmlComponent::Asynchronous);
        return true;
    }
    return false;
}
/*                                                                                               */
void display_slideshow::suspend()
{
    killTimer(m_timerId);
}
/*                                                                                               */
void display_slideshow::resume()
{
    m_timerId=startTimer(5000);
}
/*                                                                                               */
void display_slideshow::statusChanged(QQmlComponent::Status status)
{
    switch(status){
    case QQmlComponent::Null:break;
    case QQmlComponent::Loading:break;
    case QQmlComponent::Ready:
        m_item=qobject_cast<QQuickItem*>(m_component->create(m_context));
        m_item->setParentItem(m_window->contentItem());
        m_item->setParent(this);
        m_window->showNormal();
        nextImage();
        break;
    case QQmlComponent::Error:break;
    }
}
/*                                                                                               */
void display_slideshow::scan()
{
    QDir dir(m_path,"*.jpg *.png",QDir::Name);
    if(dir.isReadable()){
        QDirIterator iterator(dir,QDirIterator::Subdirectories);
        while(iterator.hasNext())
            m_list.append(iterator.next());
    }
    else
        qDebug() << "Slideshow dir " << m_path << " is not readable";
}
/*                                                                                               */
void display_slideshow::showA()
{
    emit setA(m_currentImage);
    m_fadeA->setEndValue(1);
    m_fadeB->setEndValue(0);
    m_group->start();
    alt=true;
}
/*                                                                                               */
void display_slideshow::showB()
{
    emit setB(m_currentImage);
    m_fadeA->setEndValue(0);
    m_fadeB->setEndValue(1);
    m_group->start();
    alt=false;
}
/*                                                                                               */
void display_slideshow::setImages(QQuickItem *imageA, QQuickItem *imageB)
{
    m_imageA=imageA;
    m_imageB=imageB;

    m_group=new QParallelAnimationGroup(this);
    m_fadeA=new QPropertyAnimation(m_imageA,"opacity",m_group);
    m_fadeA->setDuration(2000);
    m_group->addAnimation(m_fadeA);

    m_fadeB=new QPropertyAnimation(m_imageB,"opacity",m_group);
    m_fadeB->setDuration(2000);
    m_group->addAnimation(m_fadeB);
    scan();
    resume();
}
/*                                                                                               */
void display_slideshow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
    nextImage();
}
/*                                                                                               */
void display_slideshow::nextImage()
{
    int rand=qrand()%m_list.size();
    m_currentImage=m_list.at(rand);
    if(alt)
        showB();
    else
        showA();
}
/*                                                                                               */
display_slideshow::~display_slideshow()
{
    m_window->close();
    m_window->deleteLater();
    m_window=NULL;
}
/*                                                                                               */