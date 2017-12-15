import QtQuick 2.0
import org.rde.ui 1.0
RListDelegate {
    Row{
        anchors{fill:parent;margins:3}
        spacing:5
        Image{
            id:icon
            anchors{verticalCenter:parent.verticalCenter}
            sourceSize{width:32;height:32}
            width:32
            height:32
            //source:"image://WineLogo/"+Name
            source:"image://ThemeIcon/view-calendar-list"
            opacity:mouse.containsMouse?1:0.9
            scale:mouse.containsMouse?1.1:1
            Behavior on scale{NumberAnimation{duration:100}}
            Behavior on opacity{NumberAnimation{duration:100}}
        }

        Text{
            id:label
            font.pointSize: 14
            renderType: Text.NativeRendering
            color:mouse.containsMouse?'white':'lightgrey'
            style: Text.Raised
            anchors.verticalCenter: parent.verticalCenter
            text:Description
        }
    }
}