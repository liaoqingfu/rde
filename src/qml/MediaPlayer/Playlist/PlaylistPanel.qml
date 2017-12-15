import QtQuick 2.2
//import QtQuick.Controls 1.4
//import QtQuick.Layouts 1.3
//import org.rde.mediaplayer 1.0
//import org.rde.ui 1.0
Item{
    anchors.fill: parent
    PlaylistBar{
        id:playlistBar

        anchors{top:parent.top;bottom:parent.bottom;left:parent.left}
        width:256
        //anchors{left:parent.left;right:parent.right;top:parent.top}
        //height:72
    }
}
//    TableView{
//        id:playlistView
//        anchors{left:playlistBar.right;right:parent.right;top:parent.top;bottom:parent.bottom}
//        //model:PlaylistsModel{id:playlistsModel}
//        alternatingRowColors: false
//        backgroundVisible: false
//        style:TableStyle{}
//        headerDelegate:TableHeader{}
//        rowDelegate:RTableRowDelegate{}
//        itemDelegate:LibraryItemDelegate{}
//        TableViewColumn{
//            width:200
//            delegate:Image{
//                sourceSize{width:32;height:32}
//                width:32
//                height:32
//                source:'image://Icon/audio-x-flac'
//                fillMode: Image.PreserveAspectFit
//            }
//        }
////        TableViewColumn{
////            //role:index
////            title:'Index'
////            width: parent.width/4
////        }
//        TableViewColumn{
//            role:'Name'
//            title:'Name'
//            width:playlistView.width/4
//        }
//    }
