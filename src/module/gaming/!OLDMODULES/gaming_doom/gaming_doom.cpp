#include "gaming_doom.h"
/*                                                                                               */
bool gaming_doom::initialize()
{
    qmlRegisterType<MapModel>("org.neon.doom",1,0,"MapModel");
    qmlRegisterType<ModModel>("org.neon.doom",1,0,"ModModel");

    //context->setContextProperty("Doom",this);
    //qDebug() << this->context;

    return true;
}
/*                                                                                               */
extern QStringList gaming_doom::getData()
{
    QStringList l;
    l << "(\"doom\",\"Doom\",\"id Software\",\"1993\",\"fps\")";
    return l;
}
/*                                                                                               */
bool gaming_doom::setGame(const QString &game)
{
    return true;
}
/*                                                                                               */
void gaming_doom::readError(const QString &error)
{
    qWarning() << error;
}
/*                                                                                               */
void gaming_doom::readOutput(const QString &output)
{
//    qDebug() << "DOOM OUT::" << output;
    if(output.contains("was killed by a ") or output.contains("killed himself")){
        qDebug() << "PLAYER DIEEIEIEEIEIEIEIEIEIEIEIEIEIEIEIEIE";
            //emit playerDied();
        }
}
/*                                                                                               */
void gaming_doom::normalExit(const int &code)
{
    switch(ExitCodes(code)){
    case Normal:
        //qDebug() << "Doom exited with code " << code;
        return;
    case NoIWAD:
        qDebug() << "Doom could not find the IWAD";
        break;
    }
}
/*                                                                                               */
void gaming_doom::crashExit(const int &code)
{
    qDebug() << "Doom crashed with code" << code;

}
/*                                                                                               */
void gaming_doom::crashed(const QByteArray &text)
{
}
/*                                                                                               */
void gaming_doom::setMap(const QString &map)
{
    qDebug() << "Setting map to " << map;
}
/*                                                                                               */
void gaming_doom::setMod(const QString &mod)
{
    qDebug() << "Setting mod to " << mod;
}
/*                                                                                               */