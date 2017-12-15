#ifndef PROVIDERIMAGE
#define PROVIDERIMAGE

#include <QQuickImageProvider>
#include <QIcon>

class ProviderImage : public QQuickImageProvider
{
public:
    ProviderImage():QQuickImageProvider(QQuickImageProvider::Pixmap){}
    QPixmap requestPixmap(const QString &file,QSize *size,const QSize &requestedSize)
    {
        QPixmap pixmap(requestedSize);
        if(pixmap.load(file))
            return pixmap;
        else{
            return QIcon::fromTheme("configure").pixmap(requestedSize);

            //"ImageProvider failed to load " << file;
        }
        return QPixmap();
    }
};
#endif