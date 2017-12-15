import QtQuick 2.0
ListView{
    anchors{top:parent.top;left:parent.left;right:parent.right}
    height:72
    orientation:ListView.Horizontal
    boundsBehavior:Flickable.StopAtBounds
    snapMode: ListView.SnapToItem
    clip:true
}