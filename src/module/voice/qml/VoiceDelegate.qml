import QtQuick 2.0
import org.rde.ui 1.0
Item {
    anchors.fill: parent
    Text{
        id:label
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        renderType: Text.NativeRendering
        text:styleData.value
        color:styleData.textColor
        font{pointSize:DefaultSmallFontSize}

        textFormat: Text.PlainText
        style: Text.Raised
        clip:true
        elide: styleData.elideMode
    }
    TextGlow{
        anchors.fill: label
        source:label
        cached:false
    }
}