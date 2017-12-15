import QtQuick 2.0
Item {
    anchors.fill: parent
    Text{
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        renderType: Text.NativeRendering
        text:styleData.value
        color:styleData.textColor
        font.pointSize: 16
        textFormat: Text.PlainText
        style: Text.Raised
    }
}