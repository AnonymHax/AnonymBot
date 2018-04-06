import QtQuick 2.7
import QtQuick.Layouts 1.3
import Material 0.1
import Utils 1.0
import Material.ListItems 0.1 as ListItem

Page
{
    title: qsTr("Parametres")
    clip : true
    property Bot botInstance

    Card
    {
        anchors.centerIn: parent
        height:parent.height/1.25
        width:height
    }
}
