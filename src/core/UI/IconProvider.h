#ifndef ICONPROVIDER
#define ICONPROVIDER
#include <QQuickImageProvider>
#include <QIcon>
class IconProvider : public QQuickImageProvider
{
public:
    IconProvider():QQuickImageProvider(QQuickImageProvider::Pixmap){}
    QPixmap requestPixmap(const QString &id,QSize *size,const QSize &requestedSize)
    {
        Q_UNUSED(size);
        if(!id.isEmpty() && QIcon::hasThemeIcon(id))
            return QIcon::fromTheme(id).pixmap(requestedSize);
        return QIcon::fromTheme("unknown").pixmap(requestedSize);
    }
};
#endif