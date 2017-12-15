import QtQuick 2.0
Column{
    SliderPanel{
        anchors{left:parent.left;right:parent.right}
        slider{
            id:volumeSlider
            minimumValue:0.0
            maximumValue:1.0
            stepSize:0.1
            value:Voice.volume
            onValueChanged:Voice.volume=slider.value
        }
    }
    SliderPanel{
        anchors{left:parent.left;right:parent.right}
        slider{
            id:rateSlider
            minimumValue:-1.0
            maximumValue:1.0
            stepSize:0.1
            value:Voice.rate
            onValueChanged:Voice.rate=slider.value
        }
    }
    SliderPanel{
        anchors{left:parent.left;right:parent.right}
        slider{
            id:pitchSlider
            minimumValue:-1.0
            maximumValue:1.0
            stepSize:0.1
            value:Voice.pitch
            onValueChanged:Voice.pitch=slider.value
        }
    }


    //    Slider{
    //        id:volumeSlider
    //        //anchors{top:parent.top;bottom:parent.bottom}
    //        anchors{left:parent.left;right:parent.right}
    //        updateValueWhileDragging: true
    //        minimumValue:0.0
    //        maximumValue:1.0
    //        stepSize:0.1
    //        value:Voice.volume
    //        onValueChanged:Voice.volume=value
    //        //orientation: Qt.Vertical
    //    }
    //    Slider{
    //        id:rateSlider
    //        //anchors{top:parent.top;bottom:parent.bottom}
    //        anchors{left:parent.left;right:parent.right}
    //        updateValueWhileDragging: true
    //        minimumValue:-1.0
    //        maximumValue:1.0
    //        stepSize:0.1
    //        value:Voice.rate
    //        onValueChanged:Voice.rate=value
    //        //orientation: Qt.Vertical
    //    }
    //    Slider{
    //        id:pitchSlider
    //        //anchors{top:parent.top;bottom:parent.bottom}
    //        anchors{left:parent.left;right:parent.right}
    //        updateValueWhileDragging:true
    //        minimumValue:-1.0
    //        maximumValue:1.0
    //        stepSize:0.1
    //        value:Voice.pitch
    //        onValueChanged:Voice.pitch=value
    //        //orientation: Qt.Vertical
    //    }


    //Component.onCompleted:volumeSlider.value=Voice.volume


    //Component.onCompleted:volumeSlider.value=Voice.volume
    Component.onDestruction: Voice.saveSettings()
}