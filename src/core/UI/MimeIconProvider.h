#ifndef MIMEICONPROVIDER_H
#define MIMEICONPROVIDER_H
#include <QQuickImageProvider>
#include <QIcon>
#include <QMimeDatabase>
#include <QMimeType>
#include <QFileInfo>
#include <QSettings>
class MimeIconProvider : public QQuickImageProvider
{
public:
    MimeIconProvider():QQuickImageProvider(QQuickImageProvider::Pixmap){}
    QPixmap requestPixmap(const QString &id,QSize *size,const QSize &requestedSize)
    {
        Q_UNUSED(size);
        QMimeDatabase db;
        QMimeType type=db.mimeTypeForFile(id);

        if(type.name()=="inode/directory"){
            QFileInfo dirFile(id+"/.directory");
            if(dirFile.isReadable()){
                QSettings s(dirFile.absoluteFilePath(),QSettings::NativeFormat);
                s.beginGroup("Desktop Entry");
                if(s.contains("Icon")){
                    QString iconName=s.value("Icon").toString();
                    if(QIcon::hasThemeIcon(iconName))
                        return QIcon::fromTheme(iconName).pixmap(requestedSize);
                }
                s.endGroup();
            }
            return QIcon::fromTheme(type.genericIconName()).pixmap(requestedSize);
        }
        else if(type.name().startsWith("image/"))
            return QPixmap(id).scaled(requestedSize);
        else if(QIcon::hasThemeIcon(type.iconName()))
            return QIcon::fromTheme(type.iconName()).pixmap(requestedSize);
        else if(QIcon::hasThemeIcon(type.genericIconName()))
            return QIcon::fromTheme(type.genericIconName()).pixmap(requestedSize);
        return QIcon::fromTheme("unknown").pixmap(requestedSize);
    }
};
#endif