import QtQuick 2.0
import org.rde.ui 1.0
Item{
    anchors.fill: parent
    /*
    EngineList{
        id:engineList
        anchors{left:parent.left;top:parent.top;bottom:parent.bottom}
        width:200
    }
    VoiceList{
        id:voiceList
        anchors{left:engineList.right;top:parent.top;bottom:parent.bottom}
        width:200
    }
    */
}




//    Column{
//        anchors{left:voiceList.right;right:parent.right;top:parent.top;bottom:parent.bottom;margins:Margin}
//        spacing: Margin
//        SliderBox{
//            id:volumeSlider
//            label.text:'Volume'
//            slider.minimumValue:0
//            slider.maximumValue:200
//            slider.value: Voice.volume
//            slider.onValueChanged: Voice.volume=slider.value
//        }

//        SliderBox{
//            id:rateSlider
//            label.text:'Rate'
//            slider.minimumValue:80
//            slider.maximumValue:450
//            slider.value: Voice.rate
//            slider.onValueChanged: Voice.rate=slider.value
//        }

//        SliderBox{
//            id:pitchSlider
//            label.text:'Pitch'
//            slider.minimumValue:0
//            slider.maximumValue:100
//            slider.value: Voice.pitch
//            slider.onValueChanged: Voice.pitch=slider.value
//        }
//}
//}