import QtQuick 2.0
//-------------------------------------------------------------------------------------------------
Item {
    anchors.fill: parent
    //---------------------------------------------------------------------------------------------
    Row{
        anchors{fill:parent;margins:5}
        spacing:5

        //-----------------------------------------------------------------------------------------
        Icon{
            id:backButton
            //mouse.onClicked: view.back()
            source:"image://ThemeIcon/go-previous"
        }
        //-----------------------------------------------------------------------------------------
        Icon{
            id:forwardButton
            //mouse.onClicked: view.forward()
            source:"image://ThemeIcon/go-next"
        }
        //-----------------------------------------------------------------------------------------
        Icon{
            id:toggleBookmarksPanelButton
            source:"image://ThemeIcon/bookmarks"
            //mouseArea.onClicked:webCore.toggleBookmarkPanel()
        }
        //-----------------------------------------------------------------------------------------
        AddressBar{
            id:addressBar
        }
        //-----------------------------------------------------------------------------------------
    }





}
//-------------------------------------------------------------------------------------------------
