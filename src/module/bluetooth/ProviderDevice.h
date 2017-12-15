#ifndef PROVIDERDEVICE
#define PROVIDERDEVICE
#include <QQuickImageProvider>
#include <QIcon>
class ProviderDevice : public QQuickImageProvider
{
public:
    ProviderDevice():QQuickImageProvider(QQuickImageProvider::Pixmap){}
    QPixmap requestPixmap(const QString &file,QSize *size,const QSize &requestedSize)
    {
//        if(file.startsWith("eth"))
//            return QIcon::fromTheme("network-wired").pixmap(requestedSize);
//        else if(file.startsWith("wlan"))
//            return QIcon::fromTheme("network-wireless").pixmap(requestedSize);
   }
};
#endif