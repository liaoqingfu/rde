import QtQuick 2.0
import org.rde.filemanager 1.0
import org.rde.ui 1.0
ListView{
    anchors{top:viewToolBar.bottom;bottom:parent.bottom;left:parent.left;right:parent.right}
    clip:true
    focus:true
    boundsBehavior:Flickable.StopAtBounds
    snapMode:ListView.SnapToItem
    highlight:ListHighlight{}
    highlightMoveDuration:100
    highlightFollowsCurrentItem:true
    model:VolumeModel{id:volumeModel}
    delegate:VolumeDelegate{}
    section.property:'Device'
    section.criteria:ViewSection.FullString
    section.delegate:Header{label.text:section}
    //onCurrentIndexChanged: volumeModel.currentIndex=currentIndex
    //onCurrentIndexChanged: fileManagerWindow.currentView.path="/Development"
    //mouse.onClicked:fileManagerWindow.currentView.folderModel.folder=RootPath
    //folderViewItem.currentView.path=RootPath
    //onCurrentIndexChanged: console.log(fileManagerWindow.currentView.folderModel.folder)
}