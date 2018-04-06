import QtQuick 2.0

import QtQuick 2.7
import QtQuick.Layouts 1.3
import Material 0.1
import Utils 1.0
import QtQuick.Controls 1.5
import Material.ListItems 0.1 as ListItem
import Material.ViewDelegates 0.1 as ViewDelegates
import Material 0.1

Card
{
    property Bot botInstance

    Label {
        id:lab2

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: Units.dp(15)

        verticalAlignment:Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        width: parent.width
        wrapMode: Text.Wrap
        style: "title"
        text: qsTr("Métiers")
    }

    Item
    {
        anchors.top:lab2.bottom
        anchors.margins:Units.dp(20)
        anchors.bottom:parent.bottom
        anchors.left:parent.left
        anchors.right:parent.right

        TableView
        {
            anchors.fill: parent
            id: v

            model: botInstance.jobsModel

            numericalColumns: [1, 2]


            TableViewColumn {
                id: name3
                delegate: ViewDelegates.LabelDelegate {numericalColumns:v.numericalColumns}
                title: qsTr("Métier")
                role: "name"
                movable: false
                resizable: true
                width: v.viewport.width - level.width - experience.width
            }

            TableViewColumn {
                id: experience
                delegate: ViewDelegates.LabelDelegate {
                    numericalColumns:v.numericalColumns
                    text: (styleData.value)[0] + "%"
                    description: styleData.value[1] + " / " + styleData.value[2]
                }
                role: "experience"
                title: qsTr("Experience")
                movable: false
                resizable: false
                width: Units.dp(130)
            }

            TableViewColumn {
                id: level
                delegate: ViewDelegates.LabelDelegate {numericalColumns:v.numericalColumns}
                title: qsTr("Niveau")
                role: "level"
                movable: false
                resizable: false
                width: Units.dp(65)
            }
        }
    }
}
