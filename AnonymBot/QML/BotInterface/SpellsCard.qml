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
        id:ca2

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: Units.dp(15)

        verticalAlignment:Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        width: parent.width
        wrapMode: Text.Wrap
        style: "title"
        text: qsTr("Sorts")
    }

    Label {
        id: lab2
        anchors.top: ca2.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        verticalAlignment:Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.Wrap
        style: "subheading"
        text: qsTr("Capital de points: ")+ (ready ? botInstance.spellsPoints : qsTr("NaN"))
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

            model: botInstance.spellsModel

            numericalColumns: [0,2]

            TableViewColumn {
                id: actions2
                role: "action"
                movable: false
                resizable: false
                width: botInstance.spellsPoints ? Units.dp(65) : Units.dp(24)


                delegate: ViewDelegates.IconButtonViewDelegate
                {
                numericalColumns:v.numericalColumns

                IconButton
                {
                    iconName: "social/plus_one"
                    color: Theme.light.iconColor
                    description: qsTr("Coût: ") + styleData.value + qsTr(" point(s)")
                    visible: styleData.value
                    onClicked: botInstance.increaseSpell(styleData.row)
                }
            }
        }

        TableViewColumn {
            id: name3
            delegate: ViewDelegates.LabelDelegate {numericalColumns:v.numericalColumns}
            title: qsTr("Sort")
            role: "name"
            movable: false
            resizable: true
            width: v.viewport.width - level.width - actions2.width
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
