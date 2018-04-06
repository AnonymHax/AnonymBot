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
        id: ca
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: Units.dp(15)

        verticalAlignment:Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.Wrap
        style: "title"
        text: qsTr("Caractéristiques basiques")
    }

    Label {
        id: lab
        anchors.top: ca.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        verticalAlignment:Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.Wrap
        style: "subheading"
        text: qsTr("Capital de points: ")+ (ready ? botInstance.statsPoints : qsTr("NaN"))
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
            id:f

            anchors.fill: parent

            model: botInstance.basicStatsModel

            numericalColumns: [0, 2, 3]

            TableViewColumn {
                id: action
                role: "action"
                movable: false
                resizable: false
                width: botInstance.statsPoints ? Units.dp(65) : Units.dp(24)

                delegate: ViewDelegates.IconButtonViewDelegate
                {
                numericalColumns:f.numericalColumns

                IconButton
                {
                    iconName: "social/plus_one"
                    color: Theme.light.iconColor
                    size:Units.dp(18)
                    description: qsTr("1 pour ")+styleData.value
                    visible: styleData.value && ready
                    onClicked: botInstance.increaseStat(styleData.row)
                }
            }
        }

        TableViewColumn {
            id: name
            delegate: ViewDelegates.LabelDelegate {numericalColumns:f.numericalColumns}
            title: qsTr("Element")
            role: "name"
            movable: false
            resizable: true
            width: f.viewport.width - base.width - total.width - action.width
        }

        TableViewColumn {
            id: base
            delegate: ViewDelegates.LabelDelegate {
                numericalColumns:f.numericalColumns
                text: ready ? styleData.value : qsTr("NaN")
            }
            title: qsTr("Base")
            role: "base"
            movable: false
            resizable: false
            width: f.viewport.width / 6
        }

        TableViewColumn {
            id: total
            delegate: ViewDelegates.LabelDelegate {
                numericalColumns:f.numericalColumns
                text:  ready ? styleData.value : qsTr("NaN")
            }
            title: qsTr("Total")
            role: "total"
            movable: false
            resizable: false
            width: f.viewport.width / 6
        }
    }

}
}
