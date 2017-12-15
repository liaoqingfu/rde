import QtQuick 2.0
import org.rde.ui 1.0
Item {
    anchors.fill: parent
    RText{
        id:label
        anchors.fill: parent
        text.verticalAlignment: Text.AlignVCenter
        //renderType: Text.NativeRendering
        text.text:styleData.value
        text.color:styleData.textColor
        text.elide:styleData.elideMode
        //font{pointSize:DefaultSmallFontSize}

        //textFormat: Text.PlainText
        //style: Text.Raised
        clip:true

    }
//    TextGlow{
//        anchors.fill: label
//        source:label
//        cached:false
//    }
}