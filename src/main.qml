import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    color: "#1A1A1A"

    Navbar {
        id: navBar
        anchors { top: parent.top; bottom: undefined }
        width: parent.width
        implicitHeight: 40
    }

    Rectangle {
        id: timeLabel
        anchors { top: navBar.bottom; bottom: footer.top; left: parent.left  }
        width: 150
        color: "#1A1A1A"

        TimeLabel {
            anchors.fill: parent
        }
    }

    TaskView {
        id: taskas
        anchors { top: navBar.bottom; bottom: footer.top; left: timeLabel.right; right: parent.right  }
    }

    ActivityScale {
        id: footer
        width: parent.width
        height: 200
        anchors.bottom: parent.bottom
    }
}
