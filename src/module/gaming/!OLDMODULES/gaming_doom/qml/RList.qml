import QtQuick 2.0
ListView{
    id:list
    boundsBehavior:Flickable.StopAtBounds
    snapMode:ListView.SnapToItem
    focus:true
    clip:true
    currentIndex:0
    highlight: Rectangle{color:'blue'}
}