import QtQuick 2.0
import org.rde.ui 1.0
Rectangle{
    color:'transparent'
    border.width: 1
    RToolBar{
        id:volumeToolBar
    }
    VolumeView{
        id:volumeView
        anchors{left:parent.left;right:parent.right;top:volumeToolBar.bottom;bottom:parent.bottom}

    }
}