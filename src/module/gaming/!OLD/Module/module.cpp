#include "module.h"
/*                                                                                               */
Module::Module(const QString &filePath,QObject *parent):QObject(parent)
{
    m_loader=new QPluginLoader(filePath,this);
    QJsonObject meta=m_loader->metaData();
    if(meta.contains("IID")){
        m_iid=meta.value("IID").toString();
        QJsonObject obv=meta.value("MetaData").toObject();
        if(obv.contains("Description"))
            m_description=obv.value("Description").toString();
        if(obv.contains("Version"))
            m_version=obv.value("Version").toString();
        if(obv.contains("Icon"))
            m_icon=obv.value("Icon").toString();
        if(obv.contains("Program")){
            m_program=new Program(obv.value("Program").toString(),this);
            connect(m_program,SIGNAL(updated()),this,SLOT(programUpdated()));
            connect(m_program,SIGNAL(removed()),this,SLOT(programRemoved()));
        }
        else
            m_program=NULL;
    }
    load();
}
/*                                                                                               */
bool Module::load()
{
    if(m_loader->load()){
        m_instance=m_loader->instance();
        if(m_instance && m_instance->inherits("GamingInterface")){
            m_interface=qobject_cast<GamingInterface*>(m_instance);
            if(m_interface){
                iidMap.insert(m_iid,this);
                m_instance->setParent(this);
                context->parentContext()->setContextProperty(m_iid,this);
                return m_interface->initialize();
            }else qWarning() << "Gaming: Could not create interface for " << m_iid;
        }else qWarning() << "Gaming: Could not create instance for " << m_iid;
    }else qWarning() << "Gaming: Failed to load " << m_iid << ":" << m_loader->errorString();

    //clean up instance and interface if necessary
    return false;
}
/*                                                                                               */
void Module::initializeProgram()
{
    if(m_program){
        if(m_program->initialize()){
            //qDebug() << m_iid << ": Program " << m_program->programName() << " init ok";
        }
        else
            qDebug() << m_iid << " failed to initialize program " << m_program->programName();
    }
}
/*                                                                                               */
void Module::deleteData()
{
    QSqlDatabase db=QSqlDatabase::database("Games");
    db.exec("DROP TABLE "+m_iid);
    qDebug() << db.lastError().text();
}
/*                                                                                               */
bool Module::tableExists()
{
    QSqlDatabase db=QSqlDatabase::database("Games");
    return db.tables().contains(m_iid);
    //qDebug() << "Checking if table exists for " << m_iid;
}
/*                                                                                               */
int Module::rowCount()
{
    int count=0;
    QSqlDatabase db=QSqlDatabase::database("Games");
    QSqlQuery q=db.exec("SELECT COUNT(*) FROM "+m_iid);
    if(q.first())
        count=q.value(0).toInt();
    return count;
}
/*                                                                                               */
void Module::programUpdated()
{
    qDebug() << "Module " << m_iid << " detects that program " << m_program->programName() << " has been updated";
}
/*                                                                                               */
void Module::programRemoved()
{
    qDebug() << "Module " << m_iid << " detects that program " << m_program->programName() << " was removed";
}
/*                                                                                               */
Module::~Module()
{
    if(m_loader->unload())
        Module::modules.remove(Module::modules.indexOf(this));
    m_interface=NULL;
    m_instance=NULL;
}
/* static                                                                                        */
QQmlContext *Module::context;
QVector<Module*> Module::modules;
QMap<QString,Module*> Module::iidMap;
Module *Module::byIID(const QString &IID){return iidMap.value(IID);}
/* eof                                                                                           */