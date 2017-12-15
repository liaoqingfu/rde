import QtQuick 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import org.rde.mediaplayer 1.0
import org.rde.ui 1.0
Item{
    id:libraryPanel
    anchors.fill: parent

    property LibraryImporter importer;
    LibraryModel{id:libraryModel}

    LibraryPanelBar{
        id:libraryPanelBar
        //anchors.left: parent.left
        //anchors.right: parent.right
        anchors{left:parent.left;right:parent.right;top:parent.top}
        // prints warnings in the console
    }

//    RBar{
//        //anchors{left:parent.left;right:parent.right;top:parent.top}
//    }





    Item{
        id:filterBox
        //anchors{left:parent.left;right:parent.right;bottom:parent.bottom}


        height:72
        focus:false
        Rectangle{
            z:0
            color:'darkblue'
            opacity:0.7
            anchors.fill: parent
        }
        RText{
            id:filterLabel
            anchors.fill: parent
            text.horizontalAlignment:Text.AlignLeft
            text.verticalAlignment:Text.AlignVCenter
            text.text:libraryModel.filter
            text.onTextChanged:{
                if(text.text.length==0)
                    filterBox.visible=false
                else
                    filterBox.visible=true
            }
        }
    }
    LibraryView{
        id:libraryView
        anchors{left:parent.left;right:parent.right;top:libraryPanelBar.bottom;bottom:parent.bottom}
    }

    Keys.onPressed:{
        if(event.key===Qt.Key_Backspace)
            libraryModel.backspaceKey()
        else if(event.key===Qt.Key_Delete)
            libraryModel.deleteKey()
        else if(event.key===Qt.Key_Return)
            MediaPlayer.setMedia(libraryModel.data(libraryModel.index(row,0),"File"))
        else if(event.key===Qt.Key_Escape)
            Voice.say("escape")
        else
            libraryModel.typeKey(event.text)
    }
    function openImport(){
        importer=Qt.createComponent("LibraryImporter.qml").createObject(libraryView)
    }
    Connections{
        target:MediaPlayer
        onResourceNotFound:libraryModel.deleteFile(file)
    }


}