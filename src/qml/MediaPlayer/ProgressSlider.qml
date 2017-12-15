import QtQuick 2.0
import QtQuick.Controls 1.4
import org.rde.ui 1.0
RBar{
     height:32
     Slider{
         id:slider
         anchors{fill: parent;margins:Margin}
         //onValueChanged:{MediaPlayer.position=value;console.log(value)}
         enabled:MediaPlayer.allowSeeking
     }
     Connections{
         target:MediaPlayer
         onDurationChanged:slider.maximumValue=duration
         onPositionChanged:slider.value=position
     }
}