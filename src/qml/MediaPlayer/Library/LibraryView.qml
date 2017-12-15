import QtQuick 2.2
import QtQuick.Controls 1.4
import org.rde.ui 1.0
TableView{
    model:libraryModel
    alternatingRowColors: false
    backgroundVisible: false
    style:TableStyle{}
    headerDelegate:RTableHeader{}
    rowDelegate:RRowDelegate{}
    itemDelegate:LibraryItemDelegate{}
    focus:true
    TableViewColumn{
        width: 64
        delegate:Image{
            sourceSize{width:32;height:32}
            width:32
            height:32
            source:"image://Icon/audio-x-flac"
            fillMode: Image.PreserveAspectFit
        }
    }
    TableViewColumn{
        role:'Title'
        title:'Title'
        width:libraryView.width/4
    }
    TableViewColumn{
        role:'Artist'
        title:'Artist'
        width:libraryView.width/4
    }
    TableViewColumn{
        role:'Album'
        title:'Album'
        width:libraryView.width/4
    }
    TableViewColumn{
        role:'Genre'
        title:'Genre'
        width:libraryView.width/4
    }
    onActivated: MediaPlayer.openFile(libraryModel.data(libraryModel.index(row,0),"File"))
}