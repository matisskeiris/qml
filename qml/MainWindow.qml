import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import qml

ApplicationWindow {
    visible: true
    minimumWidth: 300;
    minimumHeight: 400;
    required property ApplicationModel application;

    ColumnLayout {
        anchors.fill: parent
        Text {
            Layout.fillWidth: true
            Layout.preferredHeight: 30

            verticalAlignment: Qt.AlignVCenter
            horizontalAlignment: Qt.AlignHCenter

            text: "ToDo"
        }

        ListView {
            id: todoList

            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 20;

            model: application.items
            delegate: RowLayout {
                required property string name
                required property int index

                width: todoList.width;
                height: 25;

                Text {
                    Layout.fillWidth: true;
                    Layout.fillHeight: true;
                    text: name;
                }
                Button {
                    Layout.fillHeight: true;
                    text: "-";
                    onClicked: application.items.remove(index)
                }
            }
        }

        Item {
            Layout.fillWidth: true
            Layout.preferredHeight: 25
            Layout.margins: 20
            RowLayout {
                anchors.fill: parent
                TextField {
                    id: newItemName
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    placeholderText: "Add ToDo item"
                }
                Button {
                    Layout.fillHeight: true;
                    text: "+"
                    // TODO: Clear on add, validate input
                    onClicked: application.items.append(newItemName.text);
                }
            }
        }
    }
}
