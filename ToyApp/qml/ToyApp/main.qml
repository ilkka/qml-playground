import QtQuick 1.0
import com.ilkka.TimeProvider 1.0

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
}
