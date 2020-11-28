import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import session 1.0

Rectangle {
    id: navbar
    color: "lightgray"

    Session {
        id: time
    }

    function toggle_running() {
        if(time.running == true)
            time.running = false
        else
            time.running = true
    }

    Text {
        text: "Time tracking system"
        anchors { left: parent.left; verticalCenter: parent.verticalCenter; leftMargin: 10 }
    }


    Button {
        id: playbutton
        checkable: true
        checked: time.running
        anchors { right: stopbutton.left; rightMargin: 5 }
        width: 75; height: parent.height
        text: checked ? "pause" : "play"
        onClicked: {
            toggle_running();
        }
    }

    Button {
        id: stopbutton
        anchors.right: sessionTime.left
        anchors.rightMargin: 5
        text: "stop"
        width: 75; height: parent.height
        visible: true
        onClicked: {
            toggle_running();
        }

    }


    Label {
        id: sessionTime
        width: 75
        height: parent.height
        verticalAlignment: "AlignVCenter"
        horizontalAlignment: "AlignHCenter"
        anchors {right: parent.right; verticalCenter: parent.verticalCenter}
        text: time.time
    }
}
