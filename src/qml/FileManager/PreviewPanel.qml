import QtQuick 2.0
import org.rde.ui 1.0
Item{
    id:fileManagerPreview
    //width:300
    Background{anchors.fill: parent}

    RToolBar{
        anchors.top: parent.top
        id:toolbar
    }
    Loader{
        id:previewLoader
        //anchors{left:parent.left;right:parent.right;top:toolbar.bottom;bottom:parent.bottom;margins:Margin}
        anchors{left:parent.left;right:parent.right;top:toolbar.bottom;bottom:parent.bottom}
    }
    Connections{
        target:FileManager
        onPreviewText:previewLoader.setSource("PreviewText.qml")
        onPreviewImage:previewLoader.setSource("PreviewImage.qml")
        onPreviewAudio:previewLoader.setSource("PreviewAudio.qml")
        onPreviewVideo:previewLoader.setSource("PreviewVideo.qml")
        onPreviewAnimation:previewLoader.setSource("PreviewAnimation.qml")
    }
}