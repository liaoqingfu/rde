#include "gallery.h"
/*                                                                                               */
bool Gallery::initialize()
{
    context->engine()->addImageProvider("Gallery",new ProviderImage);
    qmlRegisterType<ImageModel>("Gallery",1,0,"ImageModel");
    QPixmapCache::setCacheLimit(20480);
    return true;
}
/*                                                                                               */
void Gallery::setCurrentImage(const QString &image)
{
    currentImage=image;
    emit currentImageChanged();
}
/*                                                                                               */
Gallery::~Gallery()
{
    context->engine()->removeImageProvider("Gallery");
}
/*                                                                                               */