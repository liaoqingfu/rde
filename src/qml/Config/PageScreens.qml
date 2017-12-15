import QtQuick 2.0
import org.rde.screen 1.0
AbstractPage{
    ListView{
        anchors{top:parent.top;bottom:parent.bottom;left:parent.left}
        width:256
        model:ScreenModel{id:screenModel}
        delegate:ScreenDelegate{}
    }
}