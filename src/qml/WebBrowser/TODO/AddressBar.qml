import QtQuick 2.0
Item {
    anchors{top:parent.top;bottom:parent.bottom}
    width:300

    Rectangle{
        anchors.fill: parent
        z:0
        opacity:0.4
        color:'darkblue'
        radius:6
        border.width: 1
        border.color: 'black'
    }

    TextInput{
        anchors.fill: parent
        clip:true
        maximumLength: 50
        renderType: Text.NativeRendering
        color:'white'
        font.pointSize: 12
        focus:true

        //onAccepted:DataModel.acceptURL(text)
    }
}