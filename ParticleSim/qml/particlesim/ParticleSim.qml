import QtQuick 1.0
import Physics 1.0
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

        Particle {
            x: 143
            y: 43
            xvel: -50
            yvel: 96
            color: "green"
            radius: 20
        }

        Component.onCompleted: {
            Simulation.initialize();
            //Simulation.create_random_particles(5);
        }
    }

    Column {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 5

        Rectangle {
            id: addbutton
            color: "grey"
            border.color: "darkGrey"
            border.width: 2
            width: addbutton_label.paintedWidth + 20
            height: addbutton_label.paintedHeight + 10

            Text {
                id: addbutton_label
                text: "Add particle"
                anchors.centerIn: parent
            }

            MouseArea {
                anchors.fill: parent
                onClicked: Simulation.create_random_particle();
            }
        }

        Rectangle {
            id: quitbutton
            color: "grey"
            border.color: "darkGrey"
            border.width: 2
            width: quitbutton_label.paintedWidth + 20
            height: quitbutton_label.paintedHeight + 10

            Text {
                id: quitbutton_label
                text: "Quit"
                anchors.centerIn: parent
            }

            MouseArea {
                anchors.fill: parent
                onClicked: Qt.quit();
            }
        }
    }
}
