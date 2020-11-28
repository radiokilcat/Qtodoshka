import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Tasks 1.0

Rectangle {
    id: root
    color: "#6d7276"

    property int rowHeight: 40
    property string taskColor: "#d1d8e0"

    TaskModel{
        id: modelItem
    }

    ListView {
        id: tasks
        anchors { top: parent.top; bottom: parent.bottom; left: parent.left; }
        width: parent.width * 3/4
        footer: addTask
        model: modelItem

        delegate: Task {
            height: rowHeight
            width: tasks.width
            color: taskColor
        }
    }

    Component {
        id: addTask

        Button {
            id: addButton
            width: tasks.width
            height: rowHeight
            icon.source: "img/plus.svg.png"
            onClicked: {
                tasks.footer = createTask
            }
        }
    }

    Component {
        id: createTask

        Item {

            Rectangle {
                id: editColor
                anchors.fill: taskEdit
                color: taskColor
            }

            TextEdit {
                id: taskEdit
                width: tasks.width
                height: rowHeight
                horizontalAlignment: TextEdit.AlignHCenter
                verticalAlignment: TextEdit.AlignVCenter
            }

            Button {
                id: editDone
                anchors { right: discardChanges.left }
                height: rowHeight
                width: rowHeight
                icon.source: "img/checkmark.png"
                onClicked: {
                    modelItem.createTask(taskEdit.text)
                    tasks.footer = addTask
                }
            }
            Button {
                id: discardChanges
                anchors { right: taskEdit.right }
                height: rowHeight
                width: rowHeight
                icon.source: "img/cross.svg.png"
                onClicked: tasks.footer = addTask
            }
        }
    }
}
