import QtQuick 2.7
import QtQuick.Layouts 1.3
import Material 0.1
import Utils 1.0
import Material.ListItems 0.1 as ListItem

Page
{
    title: qsTr("Console")
    clip : true
    property Bot botInstance

    id: root

    LogsCard
    {
        id: logs

        anchors.margins: Units.dp(15)
        anchors.top: parent.top
        anchors.bottom: controls.top
        anchors.left: parent.left
        anchors.right: parent.right
        width:parent.width
    }

    Item
    {
        anchors.margins: Units.dp(15)
        id: controls

        height: list.implicitHeight

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        MenuField
        {
            id: list

            anchors.left: parent.left
            width: { implicitWidth > Units.dp(125) ? implicitWidth : Units.dp(125) }
            height: implicitHeight

            model: [qsTr("Général"), qsTr("Groupe"), qsTr("Guilde"), qsTr("Commerce"), qsTr("Recrutement"), qsTr("Équipe")]
        }

        TextField {

            id: input
            placeholderText: qsTr("Envoyer un message dans le chat ...")

            height: parent.height - Units.dp(7);
            anchors.leftMargin: Units.dp(15)
            anchors.left: list.right
            anchors.right: parent.right

            onAccepted: {
                if (input.text !== "") {
                    botInstance.sendChatMessage(list.selectedIndex, input.text);
                    input.text = "";
                }
            }
        }
    }
}

