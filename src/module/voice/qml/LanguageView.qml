import QtQuick 2.0
import org.rde.voice 1.0
ListView{
    boundsBehavior:Flickable.StopAtBounds
    snapMode:ListView.SnapToItem
    clip:true
    model:LanguageModel{}
    delegate:LanguageDelegate{}
    highlight: Rectangle{color:'blue';opacity:0.5}
}