import QtQuick 2.5
import org.rde.ui 1.0
//import QtGraphicalEffects 1.0
Rectangle{
    id:item
    width:400
    property alias input:input
    color:'transparent'
    border.width: 1
    border.color:'black'
    radius:6
    Rectangle{
        z:1
        id:concave
        anchors.fill: parent
        opacity:0
        radius:6
        gradient: Gradient{
            GradientStop {position:0;color:Qt.rgba(0.1,0.1,0.1,0.5)}
            GradientStop {position:0.2;color:Qt.rgba(0.5,0.5,0.5,0.4)}
            GradientStop {position:0.8;color:Qt.rgba(0.9,0.9,0.9,0.5)}
        }
        visible:false
    }
    Rectangle{
        z:1
        id:convex
        anchors.fill: parent
        radius:6
        gradient: Gradient{
            GradientStop {position:0;color:Qt.rgba(0.9,0.9,0.9,0.2)}
            GradientStop {position:1;color:Qt.rgba(0.1,0.1,0.1,0.2)}
        }
    }
    Image{
        z:1
        id:icon
        sourceSize{width:32;height:32}
        width:32
        height:32
        anchors{right:parent.right;verticalCenter:parent.verticalCenter;margins:8}
        source:'image://Icon/edit-find'
        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            onClicked:input.text=''
        }
    }
    RText{
        id:input
        z:1
        clip:true
        focus:true
        //renderType: Text.NativeRendering
        //color:'white'
        //canPaste: false
        //font.pointSize:24

        text.verticalAlignment:Text.AlignVCenter

        anchors{left:parent.left;right:icon.left;verticalCenter:parent.verticalCenter;margins:8}


        //maximumLength:20
        text.onActiveFocusChanged:activeFocus?convexToConcave.start():concaveToConvex.start();
        //validator:RegExpValidator{regExp:/[-\sa-zA-Z0-9]{3,}/}
        //validator:RegExpValidator{regExp:/[-\sa-zA-Z0-9]{1,}/}
        //onAccepted:accept();
        //cursorVisible:false

        //selectByMouse:false
        //canPaste:false
        //cursorDelegate: Rectangle{anchors{top:parent.top;bottom:parent.bottom}width:height}
        //displayText: "Search"

    }
    //TextGlow{
        //anchors.fill:input
        //source:input
    //}
    ParallelAnimation{
        id:convexToConcave
        PropertyAnimation{target:convex;property:'opacity';to:0;duration:50}
        PropertyAnimation{target:concave;property:'opacity';to:1;duration:50}
        onStarted:concave.visible=true
        onStopped:convex.visible=false
    }
    ParallelAnimation{
        id:concaveToConvex
        PropertyAnimation{target:concave;property:'opacity';to:0;duration:50}
        PropertyAnimation{target:convex;property:'opacity';to:0.5;duration:50}
        onStarted:convex.visible=true
        onStopped:concave.visible=false
    }
    signal accept();
}