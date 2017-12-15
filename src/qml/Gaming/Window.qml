import QtQuick 2.0
import org.rde.gaming 1.0
//import QtQuick.Layouts 1.3
//import QtGraphicalEffects 1.0
Item{
    anchors.fill:parent
    ArtView{
        anchors{top:parent.top;bottom:parent.bottom;right:parent.right;left:parent.horizontalCenter}
    }
    MusicPlayer{
        id:musicPlayer
        Connections{
            target:gameList.model
            onGameSelected:musicPlayer.playMusic(module,game)
        }
    }
    Rectangle{
        id:gameListFrame
        color:'transparent'
        border{width:1;color:'white'}
        anchors{top:parent.top;bottom:parent.bottom}
        width:parent.width/4
        clip:true
        GameList{
            id:gameList
        }
        GameListBar{
            id:gameListBar
            //FilterBox{
            //id:filterBox;
            anchors{top:parent.top;left:parent.left;right:parent.right}
            //height:
        }
    }
    InfoPanel{
        id:infoPanel
        anchors{left:gameListFrame.right;top:parent.top;bottom:parent.bottom;right:parent.right}
    }

    Component.onCompleted:{
        //console.log("setting game list to index "+gameList.model.currentIndex)

        //gameList.currentIndex=gameList.model.currentIndex
        //gameList.forceActiveFocus();
    }
}


//property BusyWindow busyWindow;
//property LaunchWindow launchWindow;
//Behavior on scale{NumberAnimation{duration:50}}
//Behavior on opacity{NumberAnimation{duration:50}}


//Rectangle{
//id:coverPanel
//z:0
//anchors{top:parent.top;bottom:parent.bottom;right:parent.right;left:parent.horizontalCenter}
//anchors.fill: parent
//color:'transparent'
//border{width:1;color:'black'}
//Layout.minimumWidth: 256
//Layout.fillWidth: true
//opacity: 0.5





//onSayTitle:Voice.say(title)
//onOpenLaunchWindow:{
//}

//    Connections{
//        target:LibraryModel
//        onTitleChanged:flick.opacity=1
//    }

/*
RowLayout{
    id:layout
    anchors.fill:parent
    spacing:0


}

//    FastBlur{
//        anchors.fill:layout
//        source:layout
//    }




function openBusyWindow(){
    busyWindow=Qt.createComponent("BusyWindow.qml").createObject(gameWindow)
}
onImporting: openBusyWindow();
onReady:{
    if(busyWindow){
        busyWindow.destroy();
        //busyWindow=NULL;
    }
    gameWindow.visible=true;
}
Component.onCompleted: gameList.forceActiveFocus();
}
*/