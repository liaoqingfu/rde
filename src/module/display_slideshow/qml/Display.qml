import QtQuick 2.3
//import org.neon.slideshow 1.0
Item{
    //parent: DesktopRoot
    anchors.fill: parent
    Image{
        id:imageA
        anchors.fill: parent
        antialiasing: true
        smooth: true
        mipmap: true
        asynchronous: true
        fillMode: Image.PreserveAspectFit
    }
    Image{
        id:imageB
        anchors.fill: parent
        antialiasing: true
        smooth: true
        mipmap: true
        asynchronous: true
        fillMode: Image.PreserveAspectFit
    }

    Connections{
        target: Slideshow
        onSetA:imageA.source="file:"+source
        onSetB:imageB.source="file:"+source
    }
    //onSetA:
    //onSetB:
    Component.onCompleted:Slideshow.setImages(imageA,imageB)
}