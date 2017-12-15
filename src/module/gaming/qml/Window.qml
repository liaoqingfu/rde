//import QtQuick 2.0
import org.rde.gaming 1.0
import org.rde.ui 1.0
GameWindow{
    id:gameWindow
    anchors.fill:parent
    TempGamingWindow{}
    onGameStarted:{
        Gamepad.enabled=false
        //Dock.hide()
        //Compositor.enabled=false
        MediaPlayer.pause()
        musicPlayer.pause()
        //Display.suspend();
        Voice.say(gameList.model.title)
    }
    onGameStopped:{
        //Compositor.enabled=true;
        //Dock.show();
        MediaPlayer.pause()
        Gamepad.enabled=true;
        musicPlayer.pause()
        //Display.resume();
    }
}