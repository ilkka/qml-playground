import QtQuick 1.0
import "simulation.js" as Simulation

Rectangle {
    id: world
    width: 360
    height: 360

    Timer {
        id: timer
        interval: 30
        repeat: true
        running: true
        triggeredOnStart: false
        onTriggered: { Simulation.update(); }
    }

    Particle {
        x: 50
        y: 50
        xvel: 50
        yvel: 50
        color: "red"
    }

    Particle {
        x: 244
        y: 125
        xvel: -86
        yvel: -35
        color: "blue"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
}
