#include "module.h"
/*                                                                                               */
Module::Module(const QString &path,QObject *parent):QObject(parent)
{
    m_loader=new QPluginLoader(path,this);
    QJsonObject meta=m_loader->metaData();
    if(meta.contains("IID"))
        m_iid=meta.value("IID").toString();
    else
        m_iid="?";
    QJsonObject obj=meta.value("MetaData").toObject();
    if(obj.contains("Description"))
        m_description=obj.value("Description").toString();
    else
        m_description="?";
    if(obj.contains("Version"))
        m_version=obj.value("Version").toString();
    else
        m_version="?";
    if(obj.contains("Icon"))
        m_icon=obj.value("Icon").toString();
    else
        m_icon="?";
}
/*                                                                                               */
bool Module::load()
{
    if(m_loader->load()){
        m_instance=m_loader->instance();
        if(m_instance){
            m_interface=qobject_cast<ModuleInterface*>(m_instance);
            if(m_interface){
                m_interface->context=new QQmlContext(Service::engine->rootContext(),this);
                m_interface->settings=new QSettings(qApp->applicationName(),m_iid,m_instance);

                //QSettings settings(){return QSettings(qApp->applicationName(),"tempy");}

                m_instance->setParent(this);
                if(createUserInterface()){
                    m_interface->initialize();
                }
            } else qWarning() << "Could not initialize interface for " << m_iid;
        } else qWarning() << "Could not create instance for " << m_iid;
    } else qWarning() << "Failed to load " << m_iid << ":" << m_loader->errorString();
    return false;
}
/*                                                                                               */
void Module::dockItemStatusChanged(QQmlComponent::Status status)
{
    switch(status){
    case QQmlComponent::Null:break;
    case QQmlComponent::Loading:break;
    case QQmlComponent::Ready:
        m_moduleDockItem=qobject_cast<ModuleDockItem*>(m_component->create(m_interface->context));
        m_moduleDockItem->setParent(m_instance);
        break;
    case QQmlComponent::Error:
        qWarning() << m_iid << " widget has error " << m_component->errors();
        break;
    }
}
/*                                                                                               */
bool Module::unload()
{
    if(m_loader->unload()){
        return true;
    }
    return false;
}
/*                                                                                               */
bool Module::createUserInterface()
{
    switch(m_interface->type()){
    case ModuleInterface::Display:
        qDebug() << "Creating display for " << m_iid;
        return true;
    case ModuleInterface::Dock:{
        QResource resource("/"+m_iid+"/Dock.qml");
        if(resource.isValid()){
            m_component=new QQmlComponent(Service::engine,this);
            connect(m_component,SIGNAL(statusChanged(QQmlComponent::Status)),this,SLOT(dockItemStatusChanged(QQmlComponent::Status)));
            m_component->loadUrl(QUrl("qrc:"+resource.fileName()),QQmlComponent::Asynchronous);
            return true;
        }
        qDebug() << "Creating dock for " << m_iid;
        return true;
        break;
    }
    case ModuleInterface::Icon:TrayModel::addIcon(this);break;
    case ModuleInterface::Configure:
        qDebug() << "Creating configure for " << m_iid;
        return true;
        break;
    }
}
/*                                                                                               */
QVector<Module*> Module::vector;