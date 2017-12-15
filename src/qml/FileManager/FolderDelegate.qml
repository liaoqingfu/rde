import QtQuick 2.0
import org.rde.ui 1.0
RText{
    anchors.fill: parent
    text.text:styleData.value
    text.verticalAlignment:Text.AlignVCenter
    text.elide:styleData.elideMode
}