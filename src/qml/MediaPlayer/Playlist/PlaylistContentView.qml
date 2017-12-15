//import QtQuick 2.0
//import org.neon.mediaplayer 1.0
////import QtMultimedia 5.6
//ListView{
//    boundsBehavior: Flickable.StopAtBounds
//    snapMode: ListView.SnapToItem
//    clip:true
//    delegate: PlaylistContentDelegate{}
//    model:PlaylistViewModel{id:playlistViewModel}
//}


///*
//Rectangle{
//    color:'transparent'
//    border.width: 1
//    border.color: 'white'
//    radius:8
//    property alias playlistModel:playlistModel
//    ListView{
//        id:view
//        anchors{fill:parent;margins:3}
//        model:PlaylistModel{id:playlistModel}
//        delegate: PlaylistContentDelegate{}
//        highlight:highlight
//        highlightMoveDuration: 100
//        //highlightMoveVelocity: -2
//        highlightFollowsCurrentItem: true


//        currentIndex: MediaPlayer.index

//        //preferredHighlightBegin: height/2-20
//        //preferredHighlightEnd: height/2+20
//        //highlightRangeMode: ListView.ApplyRange

//        //    Connections{
//        //        target:MediaPlayer
//        //        onIndexChanged:playlistView.positionViewAtIndex(MediaPlayer.index,ListView.Center);
//        //    }

//        Component {
//            id: highlight
//            Rectangle {
//                anchors{left:view.left;right:view.right}
//                height: 40
//                color: "lightsteelblue"; radius: 5
//                opacity:0.5
//                y: playlistContentView.currentItem.y
//                Behavior on y {
//                    SpringAnimation {
//                        spring: 2
//                        damping: 0.2
//                    }
//                }
//            }
//        }
//    }
//}
//*/