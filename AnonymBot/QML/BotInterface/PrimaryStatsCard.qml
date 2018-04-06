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
        id: lab
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: Units.dp(15)

        verticalAlignment:Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.Wrap
        style: "title"
        text: qsTr("Caractéristiques primaires")
    }

    Item
    {
        anchors.top:lab.bottom
        anchors.margins:Units.dp(20)
        anchors.bottom:parent.bottom
        anchors.left:parent.left
        anchors.right:parent.right

        TableView
        {
            id:s

            anchors.fill: parent

            model: botInstance.primaryStatsModel

            numericalColumns: [1]

            TableViewColumn {
                id: name2
                delegate: ViewDelegates.LabelDelegate {numericalColumns:s.numericalColumns}
                role: "name"
                title: qsTr("Caractéristique")
                movable: false
                resizable: true
                width: s.viewport.width - value.width
            }

            TableViewColumn {
                id: value
                delegate: ViewDelegates.LabelDelegate {numericalColumns:s.numericalColumns}
                role: "value"
                title: qsTr("Total")
                movable: false
                resizable: false
                width: s.viewport.width / 3
            }
        }

    }
}
