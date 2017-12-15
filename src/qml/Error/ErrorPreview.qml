import QtQuick 2.0
import org.rde.message 1.0
FileReader{
    id:reader
    Connections{
        target:messageModel
        onFileChanged:reader.file=messageModel.file
    }
    TextEdit{
        anchors.fill: parent
        color:'white'
        font.pointSize:12
        text:reader.content
    }
}