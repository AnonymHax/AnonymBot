/*
 * QML Material - An application framework implementing Material Design.
 * Copyright (C) 2014-2015 Michael Spencer <sonrisesoftware@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 2.1 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
import QtQuick 2.7
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3
import Material 0.1
import Material.ListItems 0.1 as ListItem
import Utils 1.0

/*!
   \qmltype Standard
   \inqmlmodule Material.ListItems 0.1

   \brief A simple list item with a single line of text and optional primary and secondary actions.
 */
ListItem.BaseListItem {
    id: botSelector

    implicitHeight: Units.dp(48)
    height: Units.dp(48)

    property Bot botInstance
    property alias action: actionItem.children
    property alias iconName: icon.name
    property alias iconSource: icon.source
    property alias secondaryItem: secondaryItem.children
    property alias content: contentItem.children
    property alias itemLabel: label

    property alias textColor: label.color
    property alias iconColor: icon.color

    dividerInset: actionItem.visible ? botSelector.height : 0

    interactive: contentItem.children.length === 0

    implicitWidth: {
        var width = botSelector.margins * 2

        if (actionItem.visible)
            width += actionItem.width + row.spacing

        if (contentItem.visible)
            width += contentItem.implicitWidth + row.spacing
        else
            width += label.implicitWidth + row.spacing

        if (secondaryItem.visible)
            width += secondaryItem.width + row.spacing

        return width
    }

    RowLayout {
        id: row
        anchors.fill: parent

        anchors.leftMargin: botSelector.margins
        anchors.rightMargin: botSelector.margins

        spacing: Units.dp(16)

        Item {
            id: actionItem

            Layout.preferredWidth: Units.dp(40)
            Layout.preferredHeight: width
            Layout.alignment: Qt.AlignCenter

            visible: children.length > 1 || icon.valid

            Icon {
                id: icon

                anchors {
                    verticalCenter: parent.verticalCenter
                    left: parent.left
                }


                visible: valid
                color: botSelector.selected ? Theme.primaryColor : Theme.light.iconColor
                size: Units.dp(24)
            }

            Image
            {
                id:characterImage
                anchors {
                    verticalCenter: parent.verticalCenter
                    left: parent.left
                }

                source: {botInstance.characterHeadUrl == "" ? "qrc:/Resources/user.png": botInstance.characterHeadUrl}
                height:Units.dp(35)
                width:Units.dp(35)

               ProgressCircle
               {
                   anchors.fill: parent
                   indeterminate: true
                   visible: {characterImage.status == Image.Ready ? false:true}
               }
            }
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
            Layout.fillWidth: true
            Layout.column: 2

            spacing: Units.dp(3)
            RowLayout {

                Item {
                    id: contentItem

                    Layout.fillWidth: false
                    Layout.preferredHeight: parent.height

                    visible: children.length > 0
                }

                Rectangle
                {
                    id: connectState
                    color: {
                        if(botInstance.connectionState == -1)
                            return "orange"

                        else if(botInstance.connectionState)
                            return "lightgreen"

                        else
                            return "red"
                    }

                    Layout.fillWidth: false
                    radius:height
                    Layout.preferredHeight: label.height/2
                    Layout.preferredWidth: label.height/2
                }

                Label {
                    id: label
                    text: botInstance.characterName
                    Layout.alignment: Qt.AlignLeft
                    Layout.fillWidth: true

                    elide: Text.ElideRight
                    style: "subheading"

                    color: botSelector.selected ? Theme.primaryColor : Theme.light.textColor

                    visible: true
                }


            }

            Label {
                id: subLabel
                visible: botInstance.connectionState == 1
                Layout.fillWidth: true
                Layout.preferredHeight: implicitHeight * maximumLineCount/lineCount

                color: {
                    if (botInstance.botState == Bot.INACTIVE_STATE)
                        return "red"

                    else if(botInstance.botState == Bot.EXCHANGING_STATE)
                        return "orange"

                    else if(botInstance.botState == Bot.MAP_TRANSITION_STATE ||
                            botInstance.botState == Bot.MOVING_STATE)
                        return "violet"

                    else if(botInstance.botState == Bot.CALCULATING_STATE)
                        return "#ffcb05"

                    else if(botInstance.botState == Bot.FIGHTING_STATE)
                        return "pink"

                    else if(botInstance.botState == Bot.FARMING_STATE)
                        return "#01b1da"

                    else if(botInstance.botState == Bot.CRAFTING_STATE)
                        return "#f4f4f4"

                    else if(botInstance.botState == Bot.BANKING_STATE)
                        return "#bbbbbb"

                    else if(botInstance.botState == Bot.REGENERATING_STATE)
                        return "#ffa0a6"

                    return "black"
                }

                text:
                {
                    if (botInstance.botState == Bot.INACTIVE_STATE)
                        return qsTr("Inactif")

                    else if(botInstance.botState == Bot.EXCHANGING_STATE)
                        return qsTr("En échange")

                    else if(botInstance.botState == Bot.MAP_TRANSITION_STATE)
                        return qsTr("Changement de carte")

                    else if(botInstance.botState == Bot.MOVING_STATE)
                        return qsTr("En déplacement")

                    else if(botInstance.botState == Bot.CALCULATING_STATE)
                        return qsTr("En calcul...")

                    else if(botInstance.botState == Bot.FIGHTING_STATE)
                        return qsTr("En combat")

                    else if(botInstance.botState == Bot.FARMING_STATE)
                        return qsTr("En récolte")

                    else if(botInstance.botState == Bot.CRAFTING_STATE)
                        return qsTr("En craft")

                    else if(botInstance.botState == Bot.BANKING_STATE)
                        return qsTr("En banque")

                    else if(botInstance.botState == Bot.REGENERATING_STATE)
                        return qsTr("En regénération")

                    return ""
                }

                elide: Text.ElideRight
                wrapMode: Text.WordWrap
                style: "body1"

                maximumLineCount: botSelector.maximumLineCount - 1
            }
        }

        Item {
            id: secondaryItem

            Layout.alignment: Qt.AlignCenter
            Layout.preferredWidth: childrenRect.width
            Layout.preferredHeight: parent.height

            visible: children.length > 0
        }

        IconButton
        {
            id: close
            iconSource: { "icons/action/highlight_off.svg"}
            Layout.alignment: Qt.AlignRight
            hoverAnimation: true
            clip: true
            onClicked: {
                if(botInstance === controller.get(selectedBot))
                    mainWindow.showWelcomeTab = true

                controller.remove(botInstance);
            }
        }
    }
}
