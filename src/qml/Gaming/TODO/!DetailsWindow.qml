//import QtQuick 2.0
//import org.neon.ui 1.0
//OverlayWindow{
//    id:detailWindow
//    property Item cont;
//    Component.onCompleted:cont=Qt.createComponent("qrc:"+libraryModel.module+"/info.qml").createObject(container);


//    Rectangle{
//        id:topPanel
//        anchors{left:parent.left;right:parent.right;top:parent.top}
//        height:128
//        color:'purple'
//    }

//    Rectangle{
//        id:bottomPanel
//        anchors{left:parent.left;right:parent.right;bottom:parent.bottom}
//        height:128
//        color:'purple'
//        Icon{
//            anchors{right:parent.right;verticalCenter:parent.verticalCenter;margins:Margin}
//            width:64
//            height:64
//            sourceSize{width:width;height:height}
//            //source:"image:/Icon//edit-delete";
//            source:'image://Icon/games-config-options'

//            mouse.onClicked:Voice.say("click")
//        }
//    }





//    //onCurrentItemChanged:loader.setPath(currentItem.label.text+"/config.qml")

//    //Keys.onEnterPressed: Gaming.launchGame(libraryModel.module,libraryModel.game)


//    //z:0
//    //scale:1.2
//    //opacity: 0
//    //id:frame
//    //opacity: 0.2
//    //border.width: 2
//    //radius:16
//    //border.color: 'lightblue'
//    //clip:true
//    //color:'cyan'
//    //anchors{fill:parent;margins:16}

//    //    gradient: Gradient {
//    //        //GradientStop {position:0;color:Qt.rgba(0,0.7,0.9,0.5)}
//    //        //GradientStop {position:0.5;color:Qt.rgba(0,0.4,0.6,0.7)}
//    //        GradientStop {position:1;color:Qt.rgba(0,0.4,0.4,0.3)}
//    //        GradientStop {position:1;color:Qt.rgba(0,0.6,0.6,0.3)}

//    //        //GradientStop { position: 0.0; color: "lightsteelblue" }
//    //        //GradientStop { position: 1.0; color: "blue" }
//    //    }

//    //    ParallelAnimation{
//    //        id:fadeIn
//    //        PropertyAnimation{target:details;property:'scale';to:1;duration:200}
//    //        PropertyAnimation{target:details;property:'opacity';to:1;duration:200}
//    //        //PropertyAnimation{target:gameWindow.libraryPanel;property:'scale';to:0.8;duration:200}
//    //        //PropertyAnimation{target:gameWindow.libraryPanel;property:'opacity';to:0;duration:200}
//    //        //onStarted:SQEWVoice.speak(gameWindow.title)
//    //        onStarted: libraryPanel.enabled=false
//    //        //onStopped:Voice.speak(libraryModel.module)
//    //    }

//    //    ParallelAnimation{
//    //        id:fadeOut
//    //        PropertyAnimation{target:details;property:'scale';to:1.2;duration:200}
//    //        PropertyAnimation{target:details;property:'opacity';to:0;duration:200}
//    //        //PropertyAnimation{target:gameWindow.libraryPanel;property:'scale';to:1;duration:200}
//    //        //PropertyAnimation{target:gameWindow.libraryPanel;property:'opacity';to:1;duration:200}
//    //        //onStarted:SQEWVoice.speak(gameWindow.title)
//    //        //onStarted: gameWindow.enabled=false
//    //        //onStopped: {libraryPanel.enabled=true;libraryPanel.libraryView.forceActiveFocus();detailsWindow.deleteLater()}
//    //        onStopped:libraryPanel.state='select'

//    //    }

//    //    Component.onCompleted:{fadeIn.start();forceActiveFocus();}
//    //    Keys.onEscapePressed:fadeOut.start()
//    //    //Keys.onEscapePressed:{libraryPanel.state='select'}




//    MusicView{
//        anchors.fill: parent

//    }
//}