import QtQuick 2.7
import QtQuick.Layouts 1.3
import Utils 1.0
import QtQuick.Controls 1.5
import Material.ListItems 0.1 as ListItem
import Material.ViewDelegates 0.1 as ViewDelegates
import Material 0.1

Page
{
    title: qsTr("Inventaire")
    clip : true
    property Bot botInstance

    id: inventory

    TableView {
        id: tableView
        anchors.fill: parent

        model: botInstance.inventoryModel

        numericalColumns: [2,3, 4, 5]

        TableViewColumn {
            id: name
            delegate: ViewDelegates.LabelDelegate {numericalColumns:tableView.numericalColumns}
            title: qsTr("Nom")
            role: "name"
            movable: false
            resizable: true
            width: tableView.viewport.width - quantity.width - id.width - actions.width - typeName.width
        }

        TableViewColumn {
            id: typeName
            delegate: ViewDelegates.LabelDelegate {numericalColumns:tableView.numericalColumns}
            title: qsTr("Type")
            role: "typeName"
            movable: false
            resizable: false
            width: tableView.viewport.width / 6
        }

        TableViewColumn {
            id: quantity
            delegate: ViewDelegates.LabelDelegate {numericalColumns:tableView.numericalColumns}
            title: qsTr("Quantité")
            role: "quantity"
            movable: false
            resizable: false
            width: tableView.viewport.width / 6
        }

        TableViewColumn {
            id: id
            delegate: ViewDelegates.LabelDelegate {numericalColumns:tableView.numericalColumns}
            title: qsTr("GID")
            role: "id"
            movable: false
            resizable: false
            width: tableView.viewport.width / 6
        }

        TableViewColumn {
            id: actions
            title: qsTr("Actions")
            role: "actions"
            movable: false
            resizable: false
            width: tableView.viewport.width / 6

            delegate: ViewDelegates.IconButtonViewDelegate
            {
            numericalColumns:tableView.numericalColumns

            IconButton
            {
                iconName: "action/delete"
                color: Theme.light.iconColor
                size:Units.dp(18)
                description: qsTr("Détruire")
                visible: styleData.value & 0x2
                onClicked: {
                    var q = botInstance.inventoryModel.getQuantity(styleData.row)

                    if(q === 1)
                        botInstance.destroyItem(styleData.row, 1)

                    else
                    {
                        dialog.index = styleData.row
                        dialog.itemQuantity = q
                        dialog.show()
                    }
                }
            }

            IconButton
            {
                iconName: ( styleData.value & 0x8 ) ? "content/redo" : "content/undo"
                color: Theme.light.iconColor
                size:Units.dp(18)
                description: ( styleData.value & 0x8 ) ? qsTr("Désequiper"): qsTr("Equiper")
                visible: styleData.value & 0x4
                onClicked:( styleData.value & 0x8 ) ? botInstance.unequipItem(styleData.row) : botInstance.equipItem(styleData.row)
            }

            IconButton
            {
                iconName: "action/pan_tool"
                color: Theme.light.iconColor
                size:Units.dp(18)
                description: qsTr("Utiliser")
                visible: styleData.value & 0x1
                onClicked: botInstance.useItem(styleData.row)
            }
        }
    }
}

Dialog {
    property int itemQuantity
    property int index

    id: dialog
    width: Units.dp(300)
    title:qsTr("Détruire des items")
    hasActions: true
    positiveButtonText: qsTr("Détruire")
    positiveButtonEnabled: !tf.hasError
    negativeButtonText: qsTr("Annuler")

    Item{
        width:parent.width
        height: Units.dp(40)

        TextField {
            id: tf
            anchors.centerIn: parent
            width:parent.width
            inputMethodHints: Qt.ImhDigitsOnly
            errorColor: "red"
            helperText: qsTr("Maximum: ")+dialog.itemQuantity
            hasError: (parseInt(tf.text) > dialog.itemQuantity) || (parseInt(tf.text) < 1) || isNaN(tf.text)
            height: Units.dp(25)
            focus:true
            placeholderText: qsTr("Quantité")
            floatingLabel: true
        }
    }

    onOpened: {
        tf.text = itemQuantity
        tf.selectAll()
    }

    onAccepted: {
        if(!tf.hasError)
            botInstance.destroyItem(index, parseInt(tf.text))
    }
}
}




