import QtQuick 2.0
import org.rde.gaming 1.0
import org.rde.ui 1.0
HistoryReader {
    id:historyReader
    Background{anchors.fill: parent}
    TextEdit{
        id:field
        anchors{fill: parent;margins:Margin}
        readOnly: true
        renderType: Text.NativeRendering
        font.pointSize: 12
        wrapMode: TextEdit.WordWrap
        color:'white'
        text:historyReader.text
        textFormat:Text.AutoText
        clip: true
    }
    Connections{
        target:LibraryModel
        onGameSelected:updateHistory(module,game)
    }
}