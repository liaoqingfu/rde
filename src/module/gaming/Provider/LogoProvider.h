#ifndef LOGOPROVIDER_H
#define LOGOPROVIDER_H
#include <QQuickImageProvider>
#include <QIcon>
#include <QDebug>
class LogoProvider : public QQuickImageProvider{
public:
    LogoProvider():QQuickImageProvider(QQuickImageProvider::Pixmap,QQmlImageProviderBase::ForceAsynchronousImageLoading){}
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    {
        Q_UNUSED(size);


        qDebug() << "Retrieving game icon for " << id;
        QPixmap p("GameLogo:/"+id+".png","png");

        if(!p.isNull())
            return p.scaled(requestedSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        else{
            qDebug() << "Which is not valid!";
            return QIcon::fromTheme("input-gaming").pixmap(requestedSize);
        }


        //qDebug() << "isNull?" << p.isNull();

        //qDebug() << ""



        //        QPixmap pixmap("GameLogo:/"+id+".png","png");
        //        if(pixmap.isNull())
        //            return QIcon::fromTheme("unknown").pixmap(requestedSize);
        //        else
        //            return pixmap.scaled(requestedSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);

        //return QIcon::fromTheme("unknown").pixmap(requestedSize);

        //return QPixmap();

        qDebug() << "End...?";
    }
};
#endif