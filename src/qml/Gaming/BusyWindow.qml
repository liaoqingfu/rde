import QtQuick 2.0
import QtQuick.Controls 1.4
Item{
    anchors.fill: parent
    BusyIndicator{
        anchors.fill: parent
    }

    Component.onCompleted: gameView.visible=false
}