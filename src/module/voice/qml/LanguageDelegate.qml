import org.rde.ui 1.0
RListDelegate{
    label.text:Name
    //icon.source:'image://Icon/'
    mouse{
        onPressed:languageView.currentIndex=index
        onClicked:Voice.locale=Locale
    }
}