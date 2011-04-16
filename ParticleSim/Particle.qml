import QtQuick 1.0

Rectangle {
    width: 10
    height: 10
    color: "black"

    property real xvel: 0.0
    property real yvel: 0.0

    function move(time_elapsed) {
        x += xvel * (time_elapsed / 1000)
        y += yvel * (time_elapsed / 1000)
    }
}
