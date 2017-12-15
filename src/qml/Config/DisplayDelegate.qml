import QtQuick 2.0
import org.rde.ui 1.0
RListDelegate{
    label.text:IID
    mouse.onClicked:displayList.currentIndex=index;
}