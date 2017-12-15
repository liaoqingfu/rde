#ifndef FILEMANAGER_H
/*                                                                                               */
#define FILEMANAGER_H
#define URI "org.rde.filemanager"
/*                                                                                               */
#include "filemanager_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
#include <QDesktopServices>
/*                                                                                               */
#include "volumemodel.h"
#include "textpreview.h"
/*                                                                                               */
class FileManager:public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "FileManager" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)
    Q_PROPERTY(QString selectedFile READ selectedFile WRITE setSelectedFile NOTIFY selectedFileChanged)

public:
    QString selectedFile()const{return m_selectedFile;}
    void setSelectedFile(const QString &file);

public slots:
    void openFile();
    void deleteFile();

private:
    Type type(){return Icon;}
    bool initialize();
    QString m_selectedFile;
    QMimeDatabase db;

signals:
    void selectedFileChanged();
    void previewText();
    void previewAudio();
    void previewImage();
    void previewVideo();
    void previewAnimation();
};
/*                                                                                               */
#endif
