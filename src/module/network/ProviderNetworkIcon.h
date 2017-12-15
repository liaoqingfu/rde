#ifndef PROVIDERNETWORKICON
#define PROVIDERNETWORKICON

#include <QQuickImageProvider>
#include <QIcon>

class ProviderNetworkIcon : public QQuickImageProvider
{
public:
    ProviderNetworkIcon():QQuickImageProvider(QQuickImageProvider::Pixmap,QQmlImageProviderBase::ForceAsynchronousImageLoading){}
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    {
        Q_UNUSED(size);
        if(id=="WLAN")
            return QIcon::fromTheme("network-wireless").pixmap(requestedSize);
        else if(id=="Ethernet")
            return QIcon::fromTheme("network-wired").pixmap(requestedSize);
    }
private:
    QString path;
};
#endif