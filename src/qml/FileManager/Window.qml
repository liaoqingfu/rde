import QtQuick 2.0
import org.rde.ui 1.0
import QtQuick.Layouts 1.3

Item{
    anchors.fill: parent
    id:fileManagerWindow
    RowLayout{
        id:layout
        anchors.fill: parent
        spacing:0
        VolumePanel{
            id:volumePanel
            anchors{top:parent.top;bottom:parent.bottom}
            Layout.minimumWidth:256
            Layout.maximumWidth:256
            Layout.fillWidth:false
        }
        FolderPanel{
            id:leftView
            anchors{top:parent.top;bottom:parent.bottom}
            Layout.minimumWidth:300;
            Layout.fillWidth:true
        }
        FolderPanel{
            id:rightView
            anchors{top:parent.top;bottom:parent.bottom}
            Layout.minimumWidth:300
            Layout.fillWidth:true
        }
        PreviewPanel{
            id:previewPanel
            anchors{top:parent.top;bottom:parent.bottom}
            Layout.minimumWidth:fileManagerWindow.width/4
            Layout.fillWidth:false
        }
    }
    property FolderPanel currentView:leftView
}