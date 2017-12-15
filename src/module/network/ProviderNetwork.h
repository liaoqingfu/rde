#ifndef PROVIDERNETWORK
#define PROVIDERNETWORK
#include <QQuickImageProvider>
#include <QIcon>
class ProviderNetwork : public QQuickImageProvider
{
public:
    ProviderNetwork():QQuickImageProvider(QQuickImageProvider::Pixmap){}
    QPixmap requestPixmap(const QString &file,QSize *size,const QSize &requestedSize)
    {
        Q_UNUSED(size);
        if(file.startsWith("eth"))
            return QIcon::fromTheme("network-wired").pixmap(requestedSize);
        else if(file.startsWith("wlan"))
            return QIcon::fromTheme("network-wireless").pixmap(requestedSize);
   }
};
#endif