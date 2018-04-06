import QtQuick 2.7
import QtQuick.Layouts 1.3
import Material 0.1
import Utils 1.0
import Material.ListItems 0.1 as ListItem

Page
{
    id:page
    title: qsTr("Combat")
    clip : true
    property Bot botInstance

    Item
    {
        width: parent.width
        height: parent.height

        RowLayout
        {
            anchors.fill: parent
            anchors.margins: Units.dp(15)
            spacing: Units.dp(15)

            FightSpellsCard{
                botInstance:page.botInstance
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
//            FightSpellsCard{
//                botInstance:page.botInstance
//                Layout.fillHeight: true
//                Layout.fillWidth: true
//            }
        }
    }

//    Completer
//    {
//        anchors.centerIn: parent
//        width:Units.dp(500)
//        height:Units.dp(50)
//        model:botInstance.monstersCompleterModel
//        placeholderText: qsTr("Chercher un monstre")
//        onAccepted: botInstance.addMonster(acceptedText)
//    }
}

