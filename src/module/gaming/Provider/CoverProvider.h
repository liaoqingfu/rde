#ifndef COVERPROVIDER_H
#define COVERPROVIDER_H
#include <QQuickImageProvider>
#include <QIcon>
#include <QFileInfo>
class CoverProvider : public QQuickImageProvider{
public:
    CoverProvider():QQuickImageProvider(QQuickImageProvider::Pixmap,QQmlImageProviderBase::ForceAsynchronousImageLoading){}
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    {
        Q_UNUSED(size);
        QFileInfo info("GameCover:/"+id+".jpg");
        if(info.isReadable()){
            QPixmap pixmap(info.absoluteFilePath(),"jpg");
            return pixmap.scaled(requestedSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        }
        else{
            info.setFile("GameCover:/"+id+".png");
            if(info.isReadable()){
                QPixmap pixmap(info.absoluteFilePath(),"png");
                return pixmap.scaled(requestedSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
            }
        }
        //return QPixmap();
        return QIcon::fromTheme("unknown").pixmap(requestedSize);
    }
};
#endif