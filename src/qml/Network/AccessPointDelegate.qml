import QtQuick 2.0
import org.rde.ui 1.0
ListDelegate {
    id:item
    mouse.onEntered:view.currentIndex=index;
    mouse.onClicked:Network.openConnection(Identifier);
    Row{
        anchors{fill:parent;margins:Margin}
        spacing:Margin
        Image{
            id:icon
            sourceSize{width:32;height:32}
            anchors{verticalCenter: parent.verticalCenter}
            smooth:true
            antialiasing: true
            fillMode:Image.PreserveAspectFit
            source:"image://NetworkIcon/"+Bearer
            scale:mouse.containsMouse?1.2:1
        }
        Text{
            anchors.verticalCenter: parent.verticalCenter
            text:Name
            renderType: Text.NativeRendering
            textFormat: Text.PlainText
            style:Text.Raised
            //color:mouse.containsMouse?'white':'lightgray'
            color:'white'
            font.pointSize: 12
            font.bold: true
        }
    }
}