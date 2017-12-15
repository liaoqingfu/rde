import QtQuick 2.0
import org.rde.ui 1.0
Item{
    width:parent.width
    height:48

    Rectangle{
        z:0
        anchors.fill: parent
        border{width:1;color:'white'}
        color:'darkblue'
    }

    Row{
        anchors{fill: parent;margins:Margin}
        spacing:Margin
        Icon{
            sourceSize{width:32;height:32}
            width:32
            height:32
            anchors{verticalCenter:parent.verticalCenter}
            source:"image://Icon/drive-harddisk";//+RootPath;
        }


        Text {
            anchors{top:parent.top;bottom:parent.bottom}
            renderType: Text.NativeRendering
            text: section
            color:'white'
            //font.bold: true
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            //horizontalAlignment: Text.AlignHCenter
        }
    }
}