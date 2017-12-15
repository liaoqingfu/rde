import QtQuick 2.0
Rectangle{
    color:'transparent'
    border.color:'black'
    ListView{
        id:spriteList
        anchors{fill:parent;margins:1}
        //model:spriteModel
        model:characterModel
        delegate: SpriteDelegate{}
        boundsBehavior: Flickable.StopAtBounds
        snapMode: ListView.SnapToItem
        clip:true
        focus:true
        onCurrentIndexChanged:characterModel.currentIndex=currentIndex
    }
}