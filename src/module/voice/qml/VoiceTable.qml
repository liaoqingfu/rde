import QtQuick 2.2
import QtQuick.Controls 1.4
import org.rde.ui 1.0
import org.rde.voice 1.0
TableView{
    model:VoiceModel{id:voiceModel}
    alternatingRowColors:false
    backgroundVisible:false
    style:TableStyle{}
    headerDelegate:RTableHeader{}
    rowDelegate:RRowDelegate{}
    itemDelegate:VoiceDelegate{}
    focus:true
    highlightOnFocus:true
    TableViewColumn{
        width: 64
        delegate:Image{
            sourceSize{width:32;height:32}
            width:32
            height:32
            source:"image://Icon/preferences-desktop-text-to-speech"
            fillMode: Image.PreserveAspectFit
        }
    }
    TableViewColumn{
        role:'Name'
        title:'Name'
        width:voiceTable.width/3
    }
    TableViewColumn{
        role:'Gender'
        title:'Gender'
        width:voiceTable.width/3
    }
    TableViewColumn{
        role:'Age'
        title:'Age'
        width:voiceTable.width/3
    }
    //onActivated: MediaPlayer.setMedia(playlistModel.data(playlistModel.index(row,0),"File"))
    //onSe
    //onh
    onActivated:voiceModel.data(voiceModel.index(row,0),"Voice")
}