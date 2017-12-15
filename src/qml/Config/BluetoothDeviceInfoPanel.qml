import QtQuick 2.0
import org.rde.ui 1.0
Item{
    ToolBar{
        id:deviceInfoToolBar
        anchors.top:parent.top
    }

    Column{
        anchors{left:parent.left;right:parent.right;top:deviceInfoToolBar.bottom;bottom:parent.bottom}
        spacing:Margin

        InfoBar{
            anchors{left:parent.left;right:parent.right;}
            key.text:'Address'
            value.text:deviceModel.address
        }
        InfoBar{
            anchors{left:parent.left;right:parent.right;}
            key.text:'Type'
            value.text:'Type'
        }
        Rectangle{
            anchors{left:parent.left;right:parent.right;}
            height:64
            //color:deviceModel.connected?'green':'red'
        }
    }
}