import QtQuick 2.7
import QtQuick.Layouts 1.3
import Material 0.1
import Utils 1.0
import QtQuick.Controls 1.5
import Material.ListItems 0.1 as ListItem
import Material.ViewDelegates 0.1 as ViewDelegates
import Material 0.1

Item
{
    property Bot botInstance

    Card
    {
        id:card
        anchors.top:parent.top
        width:parent.width
        anchors.bottom: completer.top
        anchors.bottomMargin:Units.dp(5)

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

        Item
        {
            anchors.top:ca2.bottom
            anchors.margins:Units.dp(20)
            anchors.bottom:parent.bottom
            anchors.left:parent.left
            anchors.right:parent.right

            TableView
            {
                id:f

                anchors.fill: parent

                model: botInstance.fightSpellsModel

                numericalColumns: [2, 3, 6]

                TableViewColumn {
                    id: intelligent
                    role: "intelligentSpell"
                    title: qsTr("IA")
                    movable: false
                    resizable: false
                    width: Units.dp(65)

                    delegate: ViewDelegates.CheckBoxDelegate{
                        numericalColumns:f.numericalColumns
                        onCheckedChanged:  botInstance.fightSpellsModel.setSpellAI(styleData.row, checked)
                    }
                }

                TableViewColumn {
                    id: name
                    delegate: ViewDelegates.LabelDelegate {numericalColumns:f.numericalColumns}
                    title: qsTr("Sort")
                    role: "name"
                    movable: false
                    resizable: true
                    width: f.viewport.width - intelligent.width - cost.width - range.width - castNb.width - cible.width - actions.width
                }

                TableViewColumn {
                    id: cost
                    delegate: ViewDelegates.LabelDelegate {numericalColumns:f.numericalColumns}
                    title: qsTr("PA")
                    role: "cost"
                    movable: false
                    resizable: false
                    width: f.viewport.width / 10
                }

                TableViewColumn {
                    id: range
                    delegate: ViewDelegates.LabelDelegate {numericalColumns:f.numericalColumns}
                    title: qsTr("Portée")
                    role: "range"
                    movable: false
                    resizable: false
                    width: Units.dp(60)
                }

                TableViewColumn {
                    id: castNb
                    delegate: ViewDelegates.MenuFieldDelegate {
                        numericalColumns:f.numericalColumns
                        model:[qsTr("Max"), 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
                        onItemSelected:  botInstance.fightSpellsModel.setSpellCastNb(styleData.row, index)
                    }
                    title: qsTr("Nb. Lancers")
                    role: "castNb"
                    movable: false
                    resizable: false
                    width: Units.dp(100)
                }

                TableViewColumn {
                    id: cible
                    delegate: ViewDelegates.MenuFieldDelegate {
                        numericalColumns:f.numericalColumns
                        model:[qsTr("Ennemi"), qsTr("Allié"), qsTr("Direction"), qsTr("Soi-même")]
                        onItemSelected:  botInstance.fightSpellsModel.setSpellCible(styleData.row, index)
                    }
                    title: qsTr("Cible")
                    role: "cible"
                    movable: false
                    resizable: false
                    width: Units.dp(120)
                }

                TableViewColumn {
                    id: actions
                    movable: false
                    resizable: false
                    width: Units.dp(120)
                    delegate: ViewDelegates.IconButtonViewDelegate {
                        numericalColumns:f.numericalColumns

                        IconButton
                        {
                            iconName: "content/clear"
                            color: Theme.light.iconColor
                            size:Units.dp(18)
                            description: qsTr("Retirer")
                            onClicked:  botInstance.fightSpellsModel.removeSpell(styleData.row)
                        }

                        IconButton
                        {
                            iconName: "hardware/keyboard_arrow_down"
                            color: Theme.light.iconColor
                            size:Units.dp(18)
                            description: qsTr("Descendre")
                            onClicked:  botInstance.fightSpellsModel.moveSpellDown(styleData.row)
                        }

                        IconButton
                        {
                            iconName: "hardware/keyboard_arrow_up"
                            color: Theme.light.iconColor
                            size:Units.dp(18)
                            description: qsTr("Monter")
                            onClicked:  botInstance.fightSpellsModel.moveSpellUp(styleData.row)
                        }
                    }
                }
            }

        }
    }

    Completer
    {
        id:completer
        anchors.bottom:parent.bottom
        suggestionsOnTop: true
        width:parent.width
        height:Units.dp(50)
        model:botInstance.spellsCompleterModel
        placeholderText: qsTr("Chercher un sort")
        onAccepted: botInstance.addSpell(acceptedText)
    }

}
