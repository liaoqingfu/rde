import QtQuick 2.0
import org.rde.ui 1.0
RBar{
    property alias key:key
    property alias value:value
    color:"transparent"
    border.width: 1
    clip:true
    Text{
        id:key
        renderType: Text.NativeRendering
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        anchors{left:parent.left;right:parent.horizontalCenter;top:parent.top;bottom:parent.bottom;leftMargin:10}
        color:'white'
        font.pointSize:DefaultSmallFontSize
        font.family:DefaultFont
        textFormat: Text.PlainText
        clip:true
    }
    Text{
        id:value
        renderType: Text.NativeRendering
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
        anchors{left:parent.horizontalCenter;right:parent.right;top:parent.top;bottom:parent.bottom;margins:Margin}
        color:'white'
        font.pointSize:DefaultSmallFontSize
        font.family:DefaultFont
        textFormat: Text.PlainText
        clip:true
    }
    TextGlow{
        anchors.fill:key
        source:key
    }
    TextGlow{
        anchors.fill:value
        source:value
    }
}