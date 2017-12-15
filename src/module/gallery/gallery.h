#ifndef GALLERY_H
#define GALLERY_H
/*                                                                                               */
#include "gallery_global.h"
#include "/development/LemonaDE/src/core/ServiceModule/ModuleInterface.h"
#include <QStandardPaths>
#include "imagemodel.h"
#include "ProviderImage.h"
#include <QPixmapCache>
/*                                                                                               */
class Gallery: public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Gallery" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)
    Q_PROPERTY(QString currentImage READ getCurrentImage WRITE setCurrentImage NOTIFY currentImageChanged)

public:
    ~Gallery();

private:
    bool initialize();
    QString currentImage;
    QString getCurrentImage()const{return currentImage;}
    void setCurrentImage(const QString &image);

signals:
    void currentImageChanged();
};
/*                                                                                               */
#endif