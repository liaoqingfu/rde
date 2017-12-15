import QtQuick 2.0
import org.rde.ui 1.0
RBar{
    id:bar
    anchors{left:parent.left;right:parent.right;margins:Margin}
    height:64
    property alias label:label.text
    property alias input:input

    RText{
        //z:1
        id:label
        anchors{left:parent.left;leftMargin:5;verticalCenter:parent.verticalCenter}
    }
    Item{
        anchors{left:parent.horizontalCenter;right:parent.right;top:parent.top;bottom:parent.bottom;margins:Margin}
        //width:200
        z:1
        clip:true
        Rectangle{
            z:0
            anchors.fill: parent
            border.width:1
            radius:8
            opacity:0.5
            gradient:Gradient{
                GradientStop {position:0;color:'black'}
                GradientStop {position:0.5;color:'transparent'}
                GradientStop {position:1;color:'white'}
            }
        }
        TextInput{
            id:input
            anchors{verticalCenter: parent.verticalCenter;left:parent.left;right:parent.right;margins:5}



            //anchors.fill: parent
            renderType: Text.NativeRendering
            color:'white'
            font.pointSize: 16
        }
    }
}