#include <QDBusConnection>
//#include <QProcessEnvironment>
#include "application.h"
int main(int argc, char *argv[])
{
    //    QProcessEnvironment env=QProcessEnvironment::systemEnvironment();
    //    if(env.value("XDG_CURRENT_DESKTOP")==ApplicationName){
    QDBusConnection bus=QDBusConnection::sessionBus();
    if(bus.registerService(OrganizationDomain)){
        Application application(argc,argv);
        return application.exec();
    }
    return 1;
}
//return 2;
//}