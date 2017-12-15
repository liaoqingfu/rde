import QtQuick 2.0
Column{
    anchors.fill:parent
    ControlBox{
        id:controlBox
        anchors{left:parent.left;right:parent.right}
        height:72
    }
    Tray{
        id:tray
        anchors{left:parent.left;right:parent.right}
        height:72
    }
}