import QtQuick 2.7
Image{
    id:cover
    z:0
    fillMode: Image.PreserveAspectFit
    anchors.fill:parent
    sourceSize{width:width;height:height}
    asynchronous:true
    mipmap: true
    smooth: true
    antialiasing:true
    verticalAlignment: Image.AlignTop
    horizontalAlignment: Image.AlignHCenter
    Connections{
        target:gameList.model
        onGameSelected:{cover.source='image://GameCover/'+module+'/'+game}
    }
}