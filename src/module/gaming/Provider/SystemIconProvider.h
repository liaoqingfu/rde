#ifndef SYSTEMICONPROVIDER_H
#define SYSTEMICONPROVIDER_H
#include <QQuickImageProvider>
#include <QIcon>
class SystemIconProvider : public QQuickImageProvider{
public:
    SystemIconProvider():QQuickImageProvider(QQuickImageProvider::Pixmap,QQmlImageProviderBase::ForceAsynchronousImageLoading){}
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    {
        Q_UNUSED(size);
        QStringRef ref=id.leftRef(id.lastIndexOf("/"));
        QPixmap pixmap("SystemIcon:/"+ref.toString()+".png","png");
        if(pixmap.isNull())
            return QIcon::fromTheme("unknown").pixmap(requestedSize);
        else
            return pixmap.scaled(requestedSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    }
};
#endif