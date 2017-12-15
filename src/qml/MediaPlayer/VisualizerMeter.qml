import QtQuick 2.0
Item {
    Rectangle{
        z:1
        id:meter
        anchors{bottom:parent.bottom;left:parent.left;top:parent.top}

        color:'lightblue'
    }
    property alias meter:meter
}