#include "cover.h"
/*                                                                                               */
Cover::Cover()
{
}
/*                                                                                               */
void Cover::setItems(QQuickItem *imageA, QQuickItem *imageB)
{
    m_imageA=imageA;
    m_imageB=imageB;
}
/*                                                                                               */
void Cover::updateCover(const QString &module, const QString &game)
{
    m_file=findCover(module,game);
    emit fileChanged();
}
/*                                                                                               */
QString Cover::findCover(const QString &module, const QString &game)
{
    QFileInfo info("/mame/ui/cover/"+module+"/"+game+".png");
    if(info.isReadable())
        return info.absoluteFilePath();
    else{
        info.setFile("/mame/ui/cover/"+module+"/"+game+".jpg");
        if(info.isReadable())
            return info.absoluteFilePath();
        else
            return "";
    }
}
/*                                                                                               */