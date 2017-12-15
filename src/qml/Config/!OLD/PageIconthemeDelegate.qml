import QtQuick 2.0
Rectangle{
    anchors{left:parent.left;right:parent.right;}
    height:64



    //color:Loaded?'green':'red'


    color:"darkblue"

    //color:'transparent'
//    gradient: Gradient{
//        GradientStop {position:0;color:Qt.rgba(0.7,0.7,0.7,0.5)}
//        GradientStop {position:0.5;color:Qt.rgba(0.4,0.4,0.4,0.2)}
//        GradientStop {position:1;color:Qt.rgba(0.3,0.3,0.3,0.5)}
//    }
//    Image{
//        id:icon
//        anchors{left:parent.left;top:parent.top;bottom:parent.bottom}
//        width:height
//        //source:"image://Icon/"+Icon
//        //source:"image://Icon/input-gaming"
//        source:'image://Icon/configure'
//        fillMode:Image.PreserveAspectFit
//    }
    Text{
        anchors{left:icon.right;top:parent.top;bottom:parent.verticalCenter}
        verticalAlignment: Text.AlignVCenter
        renderType: Text.NativeRendering
        font.pointSize: 16
        color:'white'
        text:Name
    }

    Text{
        anchors{left:icon.right;top:parent.verticalCenter;bottom:parent.bottom;}
        verticalAlignment: Text.AlignVCenter
        renderType: Text.NativeRendering
        font.pointSize: 12
        color:'lightgray'
        text:Comment
    }

//    MouseArea{
//        anchors.fill: parent
//        onClicked:moduleModel.currentIndex=index
//    }
}