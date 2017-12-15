//import QtQuick 2.0
//import org.rde.gaming 1.0
//MusicItem{
//    id:musicItem
//    ListView{
//        anchors.fill: parent
//        id:musicView
//        model:MusicModel
//        delegate:MusicViewDelegate{}
//        clip:true
//        boundsBehavior: ListView.StopAtBounds
//        snapMode: ListView.SnapToItem
//        highlight: Rectangle{color:'blue';opacity: 0.8}
//        highlightFollowsCurrentItem: true
//        focus:true
//        currentIndex: MusicModel.currentIndex
//        Connections{
//            target:LibraryModel
//            onGameSelected:MusicModel.updateGame(module,game)
//        }
//        Connections{
//            target: MusicModel
//            onModelReset:musicView.currentIndex=0
//            onCurrentIndexChanged:musicView.currentIndex=MusicModel.currentIndex
//        }

//        Connections{
//            target:gameWindow
//            onGameStarted:musicItem.stop();
//            onGameStopped:musicItem.start();
//        }
//    }
//}