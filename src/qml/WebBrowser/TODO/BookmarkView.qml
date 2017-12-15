import QtQuick 2.0
import WebBrowser 1.0
Item {
    Rectangle{
        z:0
        anchors.fill: parent
        color:'black'
        opacity:0.3
        radius:8
    }
    ListView{
        id:bookmarkView
        z:1
        focus:true
        anchors{fill:parent;margins:5}
        model:BookmarkModel{id:bookmarkModel}
        delegate:BookmarkDelegate{}
        boundsBehavior: Flickable.StopAtBounds
        snapMode: ListView.SnapToItem
    }
}