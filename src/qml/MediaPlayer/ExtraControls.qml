import QtQuick 2.0
import QtQuick.Controls 1.4
Row{
    spacing:Margin
    height:64
    Slider{
        id:volumeSlider
        anchors{top:parent.top;bottom:parent.bottom}
        orientation: Qt.Vertical
        width:32
        minimumValue: 0
        maximumValue: 100
        //value:MediaPlayer.volume
        value:50
        onValueChanged: MediaPlayer.volume=value
        updateValueWhileDragging:true
    }
    Slider{
        id:speedSlider
        anchors{top:parent.top;bottom:parent.bottom}
        orientation: Qt.Vertical
        width:32
        minimumValue: 0
        maximumValue: 2.0
        stepSize: 0.1
        //value:MediaPlayer.speed
        value:1
        onValueChanged: MediaPlayer.speed=value
        updateValueWhileDragging:true
        enabled: MediaPlayer.allowSpeed
    }
}