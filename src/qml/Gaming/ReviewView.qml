import QtQuick 2.7
import org.rde.gaming 1.0
import org.rde.ui 1.0
ReviewItem{
    id:reviewItem
    Background{
        anchors.fill: parent
    }
    Flickable{
        anchors{fill: parent;margins:Margin}
        TextEdit{
            id:textEdit
            anchors.fill:parent
            color:'white'
            renderType:Text.NativeRendering
            wrapMode:TextEdit.WordWrap
            text:reviewItem.text
            //onTextChanged: reviewItem.text=text;
            font{family:DefaultFont;pointSize:DefaultLargeFontSize}
            onEditingFinished:reviewItem.writeText(text)
            Keys.onEscapePressed:gameList.forceActiveFocus()
        }
    }
    Connections{
        target:gameList.model
        onGameSelected:{textEdit.clear();updateReview(module,game)}
    }
}