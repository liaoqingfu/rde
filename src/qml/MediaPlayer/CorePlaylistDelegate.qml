import QtQuick 2.0
import org.rde.ui 1.0
RText{
    anchors.fill:parent
    text.verticalAlignment:Text.AlignVCenter
    text.text:styleData.value
    //text.text:"heheh"
    text.color:styleData.textColor
    text.elide:styleData.elideMode
    clip:true
}