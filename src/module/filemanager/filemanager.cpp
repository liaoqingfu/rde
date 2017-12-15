#include "filemanager.h"
/*                                                                                               */
bool FileManager::initialize()
{
    context->setContextProperty("FileManager",this);
    qmlRegisterType<VolumeModel>(URI,1,0,"VolumeModel");
    qmlRegisterType<TextPreview>(URI,1,0,"TextPreview");
    return true;
}
/*                                                                                               */
void FileManager::setSelectedFile(const QString &file)
{
    m_selectedFile=file;
    QMimeType mime = db.mimeTypeForFile(file);
    if(mime.name().startsWith("audio/"))
        emit previewAudio();
    else if(mime.name().startsWith("image/"))
        emit previewImage();
    else if(mime.name()=="video/x-mng")
        emit previewAnimation();
    else if(mime.name().startsWith("video/"))
        emit previewVideo();
    else if (mime.inherits("text/plain"))
        emit previewText();
}
/*                                                                                               */
void FileManager::openFile()
{
    QMimeType mime=db.mimeTypeForFile(m_selectedFile);
    if(mime.name().startsWith("application")){
        //qWarning() << "Should execute " << selectedFile;
    }
    else
        if(QDesktopServices::openUrl(QUrl("file://"+m_selectedFile))){
            //qWarning() << "Opened " << selectedFile;
        };
}
/*                                                                                               */
void FileManager::deleteFile()
{
    QFile file(m_selectedFile);
    qDebug() << "Removing file " << m_selectedFile;
    //if(file.remove())
        //qWarning() << "File " << selectedFile << " removed successfully";
    //else
        //qWarning() << "Failed removing file " << selectedFile;
}
/*                                                                                               */