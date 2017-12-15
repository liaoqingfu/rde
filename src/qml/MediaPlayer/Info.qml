import QtQuick 2.0
import org.rde.ui 1.0
InfoDisplay{
    height:48
    Flickable{
        anchors{fill:parent;margins: Margin}
        contentWidth: label.contentWidth
        boundsBehavior:Flickable.StopAtBounds
        clip:true
        Text{
            id:label
            anchors.fill:parent
            horizontalAlignment:Text.AlignHCenter
            verticalAlignment:Text.AlignVCenter
            renderType:Text.NativeRendering
            color:'white'
            //font{family:DefaultFont;pointSize:16}
            font{family:DefaultFont;pointSize:DefaultLargeFontSize}
            textFormat: Text.PlainText
        }
        TextGlow{
            source:label
            anchors.fill: label
        }
    }
    Connections{
        target:MediaPlayer
        onMetaChanged:label.text=MediaPlayer.artist+" - "+MediaPlayer.title
        onLoadingMedia:label.text='Loading'
        onLoadedMedia:label.text='Loaded'
        onNoMedia:label.text=''
        //onBufferStatusChanged:label.text='Buffering:'+percentFilled
    }
}