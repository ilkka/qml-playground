import QtQuick 1.0
import timeprovider 1.0
import physics 1.0

Simulation {
    width: 360
    height: 360
    TimeProvider {
        id: time
    }

    Text {
        text: "Hello World at " + time.timeNow
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Particle {
        x: 50
        y: 50
        velocity: "1,-1,0"
    }
}
