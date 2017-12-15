#include "webbrowser.h"
/*                                                                                               */
bool WebBrowser::initialize()
{
    context->setContextProperty("WebBrowser",this);
    //qmlRegisterType<TabModel>("WebBrowser",1,0,"TabModel");
    qmlRegisterType<BookmarkModel>(URI,1,0,"BookmarkModel");
    return true;
}
/*                                                                                               */