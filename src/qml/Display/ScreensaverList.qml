import QtQuick 2.0
ListView{
    highlight: Rectangle{color:'darkblue';opacity:0.5}
    model:ScreensaverModel
    delegate:ScreensaverDelegate{}
    currentIndex:ScreensaverModel.currentIndex
}