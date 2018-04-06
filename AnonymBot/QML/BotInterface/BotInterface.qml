import QtQuick 2.7
import Utils 1.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.5
import Material 0.1

Item
{
    property Bot botInstance
    property var sectionTitles: [ qsTr("Console"), qsTr("Personnage"), qsTr("Inventaire"), qsTr("Carte"), qsTr("Flood"),
        qsTr("Combat"), qsTr("Récolte"), qsTr("Parametres")]

    property variant interfaces: [consoleInterface.createObject(), characterInterface.createObject(), inventoryInterface.createObject(),
        mapInterface.createObject(), floodInterface.createObject(), fightInterface.createObject(), craftInterface.createObject(),
        parametersInterface.createObject()]

    Component
    {
        id:consoleInterface
        Console{botInstance:basic.botInstance}
    }

    Component
    {
        id:characterInterface
        Character{botInstance:basic.botInstance}
    }

    Component
    {
        id: inventoryInterface
        Inventory{botInstance:basic.botInstance}
    }

    Component
    {
        id:mapInterface
        Map{botInstance:basic.botInstance}
    }

    Component
    {
        id:floodInterface
        Flood{botInstance:basic.botInstance}
    }

    Component
    {
        id:fightInterface
        Fight{botInstance:basic.botInstance}
    }

    Component
    {
        id:craftInterface
        Craft{botInstance:basic.botInstance}
    }

    Component
    {
        id:parametersInterface
        Parameters{botInstance:basic.botInstance}
    }

    clip:true

    Toolbar {
        id: toolBar
    }

    PageStack {
        z:8
        id: pageStack
        anchors {
            left: parent.left
            right: parent.right
            top: toolBar.bottom
            bottom: parent.bottom
        }

        initialItem: containerPage
        onPushed: toolBar.push(page)
        onPopped: toolBar.pop(page)
        onReplaced: toolBar.replace(page)
    }

    id:basic
    Page
    {
        id:containerPage

        title: qsTr("Résumé")
        width:parent.width
        height:parent.height
        x:0
        y:0

        Item
        {
            z:6
            id: it
            width:parent.width-menu.width
            height:parent.height
            x:0
            y:0

            Behavior on x { PropertyAnimation {} }

            PropertyAnimation { properties: "x,y"; easing.type: Easing.InOutQuad }

            RectangularGlow {
                anchors.fill: parent
                width: parent.width
                height: parent.height


                glowRadius: Units.dp(10)
                opacity: 0.25
                spread: 0.05
                color: "black"
                cornerRadius: 0.5 + 0.5 * 2.5
            }

            Rectangle
            {
                ActionButton
                {
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.margins: Units.dp(15)
                    backgroundColor: Theme.primaryColor
                    isMiniSize: true
                    enabled: botInstance.connectionState != -1
                    elevation: enabled
                    iconColor:

                    {
                        if(enabled)
                            return "white"

                        else
                            "#BCC0C0"
                    }

                    Behavior on elevation { PropertyAnimation {} }

                    PropertyAnimation { properties: "elevation"; easing.type: Easing.InOutQuad }

                    source:
                    {
                        if(botInstance.connectionState != 1)
                            "qrc:/Resources/connect.svg"

                        else
                            "qrc:/Resources/disconnect.svg"
                    }

                    onClicked:
                    {
                        if(botInstance.connectionState)
                            botInstance.disconnect()

                        else
                            botInstance.connect()
                    }
                }

                color: Theme.backgroundColor
                clip:true
                width:parent.width
                height:parent.height
                x:0
                y:0

                ColumnLayout
                {
                    id:main
                    clip:true

                    anchors.fill: parent
                    anchors.centerIn: parent
                    anchors.left: parent.left
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right

                    RowLayout
                    {
                        Item
                        {
                            id: imageContainer
                            clip: true
                            Layout.minimumHeight:characterImage.height
                            Layout.minimumWidth: characterImage.width/1.5
                            Layout.maximumHeight: Layout.minimumHeight
                            Layout.maximumWidth: Layout.minimumWidth

                            Image
                            {
                                id:characterImage
                                height:main.height/2
                                width: (height/sourceSize.height)*sourceSize.width
                                anchors.centerIn: parent
                                source: {botInstance.characterFullUrl == "" ? "qrc:/Resources/character.png": botInstance.characterFullUrl}
                            }

                            ProgressCircle
                            {
                                anchors.fill: parent
                                indeterminate: true
                                visible: {characterImage.status == Image.Ready ? false:true}
                            }
                        }

                        Column
                        {
                            Layout.alignment: Qt.AlignTop
                            spacing: Units.dp(20)

                            Label
                            {
                                id:characterName
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                fontSizeMode: Text.Fit
                                style:"title"
                                minimumPointSize: Units.dp(1)
                                font.pointSize: Units.dp(25)
                                font.bold: true
                                Layout.maximumHeight: main.height/6
                                color: Theme.light.textColor
                                text:(botInstance.level != -1) ? (botInstance.characterName + " - " + qsTr("Niveau")+ " " + botInstance.level) : botInstance.characterName
                            }

                            BubblesCard
                            {
                                id:bubblesCard
                                height:(characterImage.height-characterName.height)/3
                                width: main.width/2
                            }

                            StatesCard
                            {
                                x:0
                                id:w
                                height:bubblesCard.height
                                width: bubblesCard.width
                            }

                            PositionCard
                            {
                                height:bubblesCard.height*2/3
                                width: bubblesCard.width
                            }
                        }
                    }

                    RowLayout
                    {

                        Layout.minimumHeight:main.height/3
                        Layout.minimumWidth: main.width
                        Layout.maximumHeight: Layout.minimumHeight
                        Layout.maximumWidth: Layout.minimumWidth

                        LogsCard
                        {
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            Layout.margins: Units.dp(20)
                        }
                    }

                }
            }
        }

        // BUTTON
        Rectangle
        {
            function expandMenu()
            {
                it.x = - Units.dp(135)
                separator.width = Units.dp(135)
                separator.x = -Units.dp(135)
            }

            function collapseMenu()
            {
                it.x = 0
                separator.width = 0
                separator.x = 0
            }


            color:Theme.light.hintColor
            opacity:0.6
            id:menu
            x: basic.width-Units.dp(25)
            y: 0
            height: basic.height-toolBar.height
            width: Units.dp(25)

            MouseArea
            {
                anchors.fill: parent
                hoverEnabled: true

                onEntered: menu.expandMenu()

                onExited: menu.collapseMenu()
            }

            Rectangle
            {
                id:separator
                width:Units.dp(1)
                height:parent.height

                x:0
                y:0

                color: Theme.light.hintColor
                opacity:0.6

                Behavior on x { PropertyAnimation {} }
                Behavior on width {PropertyAnimation{}}
            }

            RowLayout
            {
                width:parent.width
                height:parent.height
                x: -Units.dp(150)
                y:0

                ColumnLayout
                {
                    spacing: (basic.height-toolBar.height-9*(Units.dp(40)))/9
                    Layout.alignment: Qt.AlignHCenter

                    Repeater
                    {
                        model:8
                        RowLayout
                        {
                            spacing:0
                            Layout.alignment:Qt.AlignRight
                            Item
                            {
                                Layout.alignment: Qt.AlignHCenter
                                clip:true
                                id:container
                                width : Units.dp(150)
                                height: highlighter.height

                                Rectangle
                                {
                                    id:highlighter
                                    z:5
                                    width:Units.dp(5)
                                    height:t2.height+Units.dp(20)
                                    x:separator.x+parent.width
                                    y:0
                                    opacity:0
                                    color: Theme.primaryColor

                                    Behavior on opacity { PropertyAnimation {} }

                                    PropertyAnimation { properties: "opacity"; easing.type: Easing.InOutQuad }
                                }

                                Rectangle
                                {
                                    id: selector
                                    height:highlighter.height
                                    width:container.width
                                    opacity:highlighter.opacity/2
                                    x:separator.x+parent.width
                                    y:highlighter.y
                                    color: Theme.dark.hintColor
                                }

                                Text
                                {
                                    z:0
                                    id : t2
                                    x:parent.width
                                    y:(parent.height-contentHeight)/2
                                    text: sectionTitles[index]
                                    font.pointSize: Units.dp(20)
                                    font.bold: true
                                    color: Theme.primaryColor

                                    Behavior on x { PropertyAnimation {} }

                                    PropertyAnimation { properties: "x"; easing.type: Easing.InOutQuad }
                                }

                            }


                            Item
                            {
                                Layout.alignment: Qt.AlignHCenter

                                id:icon

                                height: highlighter.height
                                width: i.width

                                Rectangle
                                {
                                    anchors.fill:parent
                                    color: Theme.light.iconColor
                                    id: round

                                    opacity: 0

                                    Behavior on opacity{ SmoothedAnimation { velocity: 2.5 } }
                                }

                                Icon
                                {
                                    height: Units.dp(25)
                                    width:Units.dp(25)
                                    id:i
                                    anchors.centerIn : parent
                                    name:"hardware/keyboard_arrow_right"
                                }

                                MouseArea
                                {
                                    id:iconMA
                                    anchors.fill: parent
                                    hoverEnabled: true

                                    onEntered:
                                    {
                                        t2.x = (container.width+Units.dp(20)-t2.contentWidth)/2;
                                        i.color= Theme.primaryColor;
                                        round.opacity = 0.5;
                                        highlighter.opacity =1;
                                        menu.expandMenu()
                                    }

                                    onExited:
                                    {
                                        t2.x = container.width
                                        i.color= Theme.light.iconColor;
                                        round.opacity = 0;
                                        highlighter.opacity = 0;

                                        menu.collapseMenu()
                                    }

                                    onClicked: pageStack.push({ item: interfaces[index], destroyOnPop:false })
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
