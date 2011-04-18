import QtQuick 1.0
import "simulation.js" as Simulation

Rectangle {
    id: root
    color: "black"
    width: 360
    height: 360

    Rectangle {
        id: world
        color: "white"
        anchors.centerIn: parent
        width: Math.min(parent.width, parent.height)
        height: width

        Timer {
            id: timer
            interval: 30
            repeat: true
            running: true
            triggeredOnStart: false
            onTriggered: { Simulation.update(); }
        }

        Component.onCompleted: {
            Simulation.initialize();
            Simulation.create_random_particles(5);
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
}
