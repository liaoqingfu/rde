import QtQuick 2.7
Image{
    id:icon
    width:128
    height:128
    sourceSize{width:width;height:height}
    asynchronous: true
    smooth: true
    antialiasing: true
    mipmap:true
    fillMode: Image.PreserveAspectFit
    Connections{
        target:gameList.model
        onGameSelected:icon.source='image://SystemIcon/'+module+'/'+game
    }
}