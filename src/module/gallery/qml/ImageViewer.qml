import QtQuick 2.0
import Gallery 1.0
Image {
    source:Gallery.currentImage
    asynchronous: true
    fillMode:Image.PreserveAspectFit
}