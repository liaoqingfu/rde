import QtQuick 2.0
Item{
    property alias text:text
    Text{
        id:text
        renderType:Text.NativeRendering
        color:'white'
        font{family:DefaultFont;pointSize:DefaultLargeFontSize}
        anchors.fill:parent
    }
    TextGlow{
        anchors.fill:text
        source:text
    }
}