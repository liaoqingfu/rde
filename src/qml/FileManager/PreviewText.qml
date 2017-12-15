import QtQuick 2.0
import org.rde.filemanager 1.0
TextPreview{
    id:textPreview
    anchors.fill: parent
    file:FileManager.selectedFile
    Rectangle{
        z:1
        radius:8
        border.width: 2
        color:'black'
        opacity:0.5
        anchors.fill: parent
    }
    TextEdit{
        z:1
        anchors{fill:parent;margins:Margin}
        renderType: Text.NativeRendering
        //text:fileManagerPreview.text
        color:"white"
        clip:true
        antialiasing: false
        readOnly: true
        //Component.onCompleted: Voice.speak("text")
        text:textPreview.text
    }
}