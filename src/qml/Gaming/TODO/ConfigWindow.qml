import QtQuick 2.0
import org.rde.core 1.0
//import org.rde.ui 1.0
import org.rde.gaming 1.0

OverlayWindow{
    id:configWindow
    ModuleModel{
        id:gameModuleModel
    }
    ModuleList{
        id:moduleList
        anchors{top:parent.top;left:parent.left;right:parent.right;margins: Margin}
        height:720
        //width:256
    }
    Item{
        anchors{left:parent.left;right:parent.right;top:moduleList.bottom;bottom:parent.bottom}

//        ConfigModuleBox{
//            id:configModuleBox
//            anchors{left:parent.left;right:parent.right;top:parent.top}
//        }
        Surface{
            id:loader
            //anchors{left:parent.left;right:parent.right;top:configModuleBox.bottom;bottom:parent.bottom}
            anchors.fill: parent
        }
    }
    Component.onDestruction: gameView.forceActiveFocus()
}