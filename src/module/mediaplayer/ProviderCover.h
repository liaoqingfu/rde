#ifndef PROVIDERCOVER_H
#define PROVIDERCOVER_H

#include <QQuickImageProvider>

class ProviderCover : public QQuickImageProvider
{
public:
    ProviderCover():QQuickImageProvider(QQuickImageProvider::Pixmap){}
    QPixmap requestPixmap(const QString &file,QSize *size,const QSize &requestedSize)
    {
        QPixmap pixmap;
        if(!pixmap.load(file.left(file.lastIndexOf("/"))+"/cover.jpg")){
            pixmap.load("/SQEW/media/icons/Media.png");
        }
        //return pixmap.scaled(requestedSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        return pixmap;
    }
};
#endif