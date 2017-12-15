import QtQuick 2.0
import org.rde.voice 1.0
ListView{
    model:VoiceModel{id:voiceModel}
    delegate:VoiceDelegate{}
    highlight: Rectangle{color:'darkblue'}
    boundsBehavior: Flickable.StopAtBounds
    snapMode: ListView.SnapToItem
    currentIndex:voiceModel.currentIndex
    onCurrentIndexChanged: voiceModel.currentIndex=currentIndex
}