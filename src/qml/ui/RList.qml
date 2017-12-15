import QtQuick 2.0
Rectangle{
    id:item
    border.color: 'white'
    color:'transparent'
    property alias view:view
    signal keyPress(event Key)
    clip:true
    ListView{
        id:view
        anchors.fill: parent
        boundsBehavior: Flickable.StopAtBounds
        snapMode:ListView.SnapToItem
        focus:true
        highlightFollowsCurrentItem:true
        highlightMoveDuration:100
        Keys.onPressed:item.keyPress(event)
    }
}