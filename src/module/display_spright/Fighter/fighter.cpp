#include "fighter.h"
/*                                                                                               */
Fighter::Fighter(const QString &name)
{
    m_name=name;

    m_player=Player::players.at(0);



    m_basePath="/games/spright/"+name+"/";

    //parseFile();

    m_component=new QQmlComponent(context->engine(),this);
    connect(m_component,SIGNAL(statusChanged(QQmlComponent::Status)),this,SLOT(statusChanged(QQmlComponent::Status)));
    m_component->loadUrl(QUrl::fromLocalFile(m_basePath+name+".qml"),QQmlComponent::Asynchronous);
}
/*                                                                                               */
void Fighter::parseFile()
{
    m_parseWatcher=new QFutureWatcher<QString>(this);
    connect(m_parseWatcher,SIGNAL(finished()),this,SLOT(parseFinished()));
    m_parseWatcher->setFuture(QtConcurrent::run(this,&Fighter::parseThread));
}
/*                                                                                               */
extern QString Fighter::parseThread()
{
    QFile file(m_basePath+m_name+".txt");
    if(file.exists()){
        if(file.open(QIODevice::ReadOnly)){
            QString all=file.readAll();
            foreach(QString line,all.split("\n")){


                if(line.trimmed().startsWith("(")){


                    if(line.endsWith(")"));
                }
            }
        }
        else
            qDebug() << "Could not open " << m_name;
    }
    else
        qDebug() << "Could not load definition for " << m_name;
    return NULL;
}
/*                                                                                               */
void Fighter::parseFinished()
{
    QString str=m_parseWatcher->result();
    m_parseWatcher->deleteLater();
}
/*                                                                                               */
void Fighter::statusChanged(QQmlComponent::Status status)
{
    switch(status){
    case QQmlComponent::Null:break;
    case QQmlComponent::Loading:break;
    case QQmlComponent::Ready:ready();break;
    case QQmlComponent::Error:
        qDebug() << "QML error!!!!!!!!" << m_component->errorString();
        break;
    }
}
/*                                                                                               */
void Fighter::ready()
{
    //    m_item=qobject_cast<QQuickItem*>(m_component->create(context));
    m_item=qobject_cast<FighterItem*>(m_component->create(context));

    connect(m_player,SIGNAL(neutral()),m_item,SIGNAL(neutral()));
    connect(m_player,SIGNAL(crouch()),m_item,SIGNAL(crouch()));
    connect(m_player,SIGNAL(jump()),m_item,SIGNAL(jump()));
    connect(m_player,SIGNAL(walkLeft()),m_item,SIGNAL(walkLeft()));
    connect(m_player,SIGNAL(walkRight()),m_item,SIGNAL(walkRight()));
    connect(m_player,SIGNAL(punch()),m_item,SIGNAL(punch()));
    connect(m_player,SIGNAL(kick()),m_item,SIGNAL(kick()));
    connect(m_player,SIGNAL(taunt()),m_item,SIGNAL(taunt()));

    //    connect(m_player,SIGNAL(neutral()),this,SLOT(neutral()));
    //    connect(m_player,SIGNAL(crouch()),this,SLOT(crouch()));
    //    connect(m_player,SIGNAL(jump()),this,SLOT(jump()));
    //    connect(m_player,SIGNAL(walkLeft()),this,SLOT(walkLeft()));
    //    connect(m_player,SIGNAL(walkRight()),this,SLOT(walkRight()));
    //    connect(m_player,SIGNAL(punch()),this,SLOT(punch()));
    //    connect(m_player,SIGNAL(kick()),this,SLOT(kick()));
    //    connect(m_player,SIGNAL(taunt()),this,SLOT(taunt()));


    m_item->setX(Fighter::autoXPos);

    Fighter::autoXPos=Fighter::autoXPos+300;



    m_component->deleteLater();
    //m_item->setParentItem(this);

    m_item->setParentItem(m_arena);
    m_item->setParent(this);

    QDir speechDir("/games/spright/"+m_name+"/voice","*.wav");
    if(speechDir.isReadable()){
        m_voice=new QMediaPlayer(this,QMediaPlayer::LowLatency);
        foreach(QFileInfo info,speechDir.entryInfoList())
            m_speech.insert(info.baseName(),QUrl::fromLocalFile(info.absoluteFilePath()));

        //m_voice->setMedia(QUrl::fromLocalFile("/games/spright/ChunliSF2/voice/spinningbirdkick.wav"));
    }


    m_head=new Head();
    m_torso=new Torso();
    m_arms=new Arms();
    m_legs=new Legs();

    m_level=1;
    m_hp=100;
    m_sp=0;

    foreach(Fighter *fighter,fighters){
        fighter->noticeNewFighter(this);
    }

    if(!fighters.isEmpty())
        searchTarget();
    fighters.append(this);

    m_timer=startTimer(1000,Qt::CoarseTimer);
}
/*                                                                                               */
void Fighter::searchTarget()
{
    m_searchTargetWatcher=new QFutureWatcher<Fighter*>(this);
    connect(m_searchTargetWatcher,SIGNAL(finished()),this,SLOT(searchTargetFinished()));
    m_searchTargetWatcher->setFuture(QtConcurrent::run(this,&Fighter::searchTargetThread));
}
/*                                                                                               */
extern Fighter *Fighter::searchTargetThread()
{
    // this function is the enemy acquirement algorithm

    foreach(Fighter *fighter,fighters){
        if(fighter!=this)
            return fighter;

        //{
        //            if(fighter->team()==m_team){
        //                qDebug() << "Found ally " << fighter->name();
        //            }
        //            else

        //qDebug() << "Found enemy " << fighter->name();
    }
    return NULL;
}
/*                                                                                               */
void Fighter::searchTargetFinished()
{
    setTarget(m_searchTargetWatcher->result());
    m_searchTargetWatcher->deleteLater();
}
/*                                                                                               */
void Fighter::setTarget(Fighter *target)
{
    if(target){
        m_target=target;
        qDebug() << m_name << "is engaging " << m_target->name();
        if(xPos() > m_target->xPos()){
            qDebug() << m_name << "should move " << xPos()-m_target->xPos() << " to the left";
        }
        else
            qDebug() << m_name << "should move " << m_target->xPos()-xPos() << " to the right";
    }
    else
        qDebug() << m_name << ": Cannot set undefined target";
}
/*                                                                                               */
void Fighter::say(const QString &speech)
{
    if(m_voice && m_speech.contains(speech)){
        m_voice->setMedia(m_speech.value(speech));
        m_voice->play();
    }
    else
        qDebug() << "NO VOICE FOR " << m_name;
}
/*                                                                                               */
void Fighter::noticeNewFighter(Fighter *fighter)
{
    if(fighter!=this){
        if(!m_target)
            setTarget(fighter);
    }
}
/*                                                                                               */
void Fighter::addItem(ConsumableItem *item)
{
    m_inventory.append(item);
}
/*                                                                                               */
void Fighter::dropItem(ConsumableItem *item)
{
    m_inventory.remove(m_inventory.indexOf(item));
}
/*                                                                                               */
void Fighter::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
    //qDebug() << m_name << "Update";
}



/*                                                                                               */
void Fighter::neutral()
{
    qDebug() << m_name << "idle";
}
/*                                                                                               */
void Fighter::crouch()
{
    qDebug() << m_name << "crouches!";
}
/*                                                                                               */
void Fighter::jump()
{
    qDebug() << m_name << "jumps!";
}
/*                                                                                               */
void Fighter::walkLeft()
{
    qDebug() << m_name << "left!";
}
/*                                                                                               */
void Fighter::walkRight()
{
    qDebug() << m_name << "right!";
}
/*                                                                                               */
void Fighter::punch()
{
    qDebug() << m_name << "punches!";
}
/*                                                                                               */
void Fighter::kick()
{
    qDebug() << m_name << "kicks!";

}
/*                                                                                               */
void Fighter::taunt()
{
    qDebug() << m_name << "taunts!";
    this->say("yata");
}
/*                                                                                               */
Fighter::~Fighter()
{
    delete m_head;
    delete m_torso;
    delete m_arms;
    delete m_legs;
}
/*                                                                                               */
void Fighter::parseTextFile(const QString &file)
{
    qDebug() << "Parsing fighter " << file;
    QFile f("/games/paintown/data/players/"+file+"/"+file+".txt");
    //if(f.isReadable()){
    //QFile file(info.absoluteFilePath());
    if(f.open(QIODevice::ReadOnly)){


        QStringList lines=QString(f.readAll()).split("\n");

        foreach(QString line,lines)
            qDebug() << "LINE:" << line;

        //QByteArray txt=f.readAll();
        //qDebug() << txt;
    }

    //}
}
/*                                                                                               */
QVector<Fighter*> Fighter::fighters;
QQmlContext *Fighter::context;
QQuickItem *Fighter::m_arena;
int Fighter::autoXPos=0;

