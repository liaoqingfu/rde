import org.rde.ui 1.0
RListDelegate{
    icon.source:'image://MimeIcon/'+RootPath;
    label.text:DisplayName
    mouse.onPressed:volumeView.currentIndex=index
    mouse.onClicked:fileManagerWindow.currentView.view.model.folder=RootPath
}