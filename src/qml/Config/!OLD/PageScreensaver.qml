import QtQuick 2.0
AbstractPage{



    ListView{
        id:screensaverList
        anchors{left:parent.left;top:parent.top;bottom:parent.bottom;margins:Margin}
        width:200
        model:ScreensaverModel
        delegate:ScreensaverDelegate{}
    }
}