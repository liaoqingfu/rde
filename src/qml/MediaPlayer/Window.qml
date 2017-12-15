import QtQuick 2.0
import org.rde.core 1.0
import org.rde.ui 1.0
import org.rde.mediaplayer 1.0
Item{
    id:mediaWindow
    anchors.fill:parent
    CorePlaylist{
        id:playlist
        anchors{left:parent.left;top:parent.top;bottom:parent.bottom}
        width:parent.width/3
    }
    Item{
        anchors{left:playlist.right;right:parent.right;top:parent.top;bottom:parent.bottom}
        RTabBar{
            id:tabBar
            model:ListModel{
                id:listModel
                ListElement{type:'Library';iconName:'library-music'}
                ListElement{type:'Playlist';iconName:'view-media-playlist'}
                ListElement{type:'Streams';iconName:'x-media-podcast'}
                ListElement{type:'Disc';iconName:'media-optical'}
            }
            delegate:TabDelegate{}
            onCurrentIndexChanged:{
                panelLoader.setPath('/development/rde/src/qml/MediaPlayer/'+listModel.data(listModel.index(currentIndex,0),1)+'/'+listModel.data(listModel.index(currentIndex,0),1)+"Panel.qml");
                //MediaPlayer.setMode(currentIndex)
                //mediaWindow.index=currentIndex
            }
            //currentIndex:MediaPlayer.index
        }
        Surface{
            id:panelLoader
            anchors{left:parent.left;right:parent.right;top:tabBar.bottom;bottom:parent.bottom}
        }
    }
    Component.onDestruction:MediaPlayer.closeWindow()
}