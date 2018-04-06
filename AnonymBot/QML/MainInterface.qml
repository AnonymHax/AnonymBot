import QtQuick 2.7
import QtQuick.Controls 1.5
import Material 0.1
import Material.ListItems 0.1 as ListItem
import QtQuick.Dialogs 1.2
import Utils 1.0
import QtQuick.Layouts 1.3
import "ViewDelegates" as ViewDelegates
import Material.ViewDelegates 0.1 as ViewDelegates


ApplicationWindow {
    id: mainWindow
    visible: true
    property int defaultWidth: Units.dp(1000)
    property  int defaultHeight: Units.dp(600)
    contentItem.minimumWidth:defaultWidth/1.5
    contentItem.minimumHeight:defaultHeight/1.5
    width: defaultWidth
    height: defaultHeight
    title: qsTr("AnonymBot ")

    property int selectedBot : 0
    property  bool  showWelcomeTab : true

    theme {
        primaryColor: Palette.colors["blue"]["500"]
        primaryDarkColor: Palette.colors["blue"]["700"]
        accentColor: Palette.colors["red"]["A200"]
        tabHighlightColor: "white"
    }

    initialPage: Page {
        id: page

        title: qsTr("Panel")

        Sidebar {
            id: sidebar
            width:
            {
                if(parent.width <= defaultWidth)
                    return parent.width/4

                else
                    return defaultWidth/4
            }
            expanded: true

            Column {
                width: parent.width

                Repeater {
                    model: controller

                    delegate: ViewDelegates.BotSelectorDelegate
                    {
                    botInstance : botData
                    onClicked: {selectedBot = index; showWelcomeTab = false}
                    selected: (botInstance == controller.get(selectedBot) && !showWelcomeTab)
                }
            }
        }

    }

    ActionButton
    {
        anchors.bottom: sidebar.bottom
        anchors.right: sidebar.right
        anchors.margins: 25
        iconName: "content/add"
        onClicked: {controller.on_manageAccounts_triggered()}
    }

    Flickable
    {
        id: welcomeFlickable
        anchors {
            left: sidebar.right
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }
        visible: showWelcomeTab

        ColumnLayout
        {
            anchors.centerIn: parent
            spacing: Units.dp(15)

            Text
            {
                Layout.alignment: Qt.AlignCenter
                font.pointSize: Units.dp(30)
                text: "AnonymBot Beta"
                color: Theme.light.textColor
            }

            Text
            {
                Layout.alignment: Qt.AlignCenter
                font.pointSize: Units.dp(15)
                font.italic: true
                text: qsTr("Selectionnez un bot")
                color: Theme.light.textColor
            }
        }
    }

    TabView
    {
        id: tabView
        cacheBuffer: tabView.height*64
        orientation: Qt.Vertical
        visible: !showWelcomeTab
        currentIndex: selectedBot
        anchors {
            left: sidebar.right
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }

        model:controller


        delegate: Item {
            width: tabView.width
            height: tabView.height
            clip: true


            Flickable {
                id: flickable
                anchors {
                    left: parent.left
                    right: parent.right
                    top: parent.top
                    bottom: parent.bottom
                }

                Loader
                {
                    id: botInterface
                    anchors.fill: parent
                    asynchronous: true
                    visible: status == Loader.Ready
                    source:  Qt.resolvedUrl("BotInterface/BotInterface.qml")
                    onLoaded: botInterface.item.botInstance = botData
                }

                ProgressCircle {
                    anchors.centerIn: parent
                    visible: botInterface.status == Loader.Loading
                }
            }

            Scrollbar {
                flickableItem: flickable
            }
        }
    }
}
}
