import QtQuick 2.7
import QtQuick.Layouts 1.3
import Material 0.1
import Utils 1.0
import QtQuick.Controls 1.5
import Material.ListItems 0.1 as ListItem
import Material.ViewDelegates 0.1 as ViewDelegates
import Material 0.1

Page {
    id: page
    property Bot botInstance
    title: qsTr("Personnage")

    property bool ready: (botInstance.connectionState == 1)

    tabs: [qsTr("C. Basiques & Sorts"), qsTr("C. Primaires & Metiers")]

    TabView {
        id: tabView
        anchors.fill: parent
        currentIndex: page.selectedTab
        model: tabs
    }

    VisualItemModel {
        id: tabs

        Item
        {
            width: tabView.width
            height: tabView.height

            RowLayout
            {
                anchors.fill: parent
                anchors.margins: Units.dp(15)
                spacing: Units.dp(15)

                BasicStatsCard{
                    botInstance:page.botInstance
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }
                SpellsCard{
                    botInstance:page.botInstance
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }
            }
        }

        Item
        {
            width: tabView.width
            height: tabView.height

            RowLayout
            {
                anchors.fill: parent
                anchors.margins: Units.dp(15)
                spacing: Units.dp(15)

                PrimaryStatsCard{
                    botInstance:page.botInstance
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }
                JobsCard{
                    botInstance:page.botInstance
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }
            }
        }
    }

}
