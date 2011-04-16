import QtQuick 1.0
import timeprovider 1.0
import physics 1.0

Rectangle {
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

    Simulation {
        anchors.fill: parent
        Particle {
            id: p1
            x: 50
            y: 50
            velocity: "0.01,-0.01,0"
        }

        Particle {
            id: p2
            x: 100
            y: 100
            velocity: "-0.03,0.03,0"
        }
    }

    Text {
        anchors.bottom: parent.bottom
        text: "le fú"
        x: p1.x
    }
}
