import QtQuick 2.0
import org.rde.ui 1.0
import org.rde.core 1.0
RListDelegate{
    icon.source:'image://Icon/'+IconName
    label.text:IID
    mouse{
        onClicked:moduleView.currentIndex=index;
        onDoubleClicked: moduleModel.toggle(index)
    }
    Rectangle{
        z:0
        //anchors{top:parent.top;bottom:parent.bottom;right:parent.right;margins: Margin}
        anchors.fill: parent
        //width:height
        //radius:8
        //border.width: 1
        //color:'blue'
        color:Loaded?'green':'red'
        opacity: 0.2
    }

    //anchors{left:parent.left;right:parent.right;}
    //height:64



    //color:Loaded?'green':'red'

    //color:'transparent'
    //    gradient: Gradient{
    //        GradientStop {position:0;color:Qt.rgba(0.7,0.7,0.7,0.5)}
    //        GradientStop {position:0.5;color:Qt.rgba(0.4,0.4,0.4,0.2)}
    //        GradientStop {position:1;color:Qt.rgba(0.3,0.3,0.3,0.5)}
    //    }
    //    Image{
    //        //id:icon
    //        anchors{left:parent.left;top:parent.top;bottom:parent.bottom}
    //        width:height
    //        //source:"image://Icon/"+Icon
    //        //source:"image://Icon/input-gaming"
    //        source:'image://Icon/video-television'
    //        //icon.source:'image://Icon/video-television'
    //        fillMode:Image.PreserveAspectFit
    //    }
    //    Text{
    //        anchors{left:icon.right;top:parent.top;bottom:parent.verticalCenter}
    //        verticalAlignment: Text.AlignVCenter
    //        renderType: Text.NativeRendering
    //        font.pointSize: 16
    //        color:'white'
    //        text:IID
    //    }

    //    Text{
    //        anchors{left:icon.right;top:parent.verticalCenter;bottom:parent.bottom;}
    //        verticalAlignment: Text.AlignVCenter
    //        renderType: Text.NativeRendering
    //        font.pointSize: 12
    //        color:'lightgray'
    //        text:Description
    //    }

    //    MouseArea{
    //        anchors.fill: parent

    //    }
}