#include "webpage.h"

WebPage::WebPage(const QString &url,QObject *parent):QObject(parent)
{
    this->url=url;
}