#ifndef LOGOPROVIDER_H
#define LOGOPROVIDER_H
#include <QQuickImageProvider>
#include <QIcon>
class LogoProvider : public QQuickImageProvider{
public:
    LogoProvider():QQuickImageProvider(QQuickImageProvider::Pixmap,QQmlImageProviderBase::ForceAsynchronousImageLoading){}
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    {
        Q_UNUSED(size);
        QPixmap pixmap("GameLogo:/"+id+".png","png");
        if(pixmap.isNull())
            return QIcon::fromTheme("unknown").pixmap(requestedSize);
        else
            return pixmap.scaled(requestedSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    }
};
#endif