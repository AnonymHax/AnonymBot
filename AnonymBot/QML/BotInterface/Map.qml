import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import Utils 1.0
import "../ViewDelegates" as ViewDelegates
import Material.ViewDelegates 0.1 as ViewDelegates
import QtQuick.Controls 1.5
import Material 0.1

Page
{
    title: qsTr("Carte")
    property Bot botInstance

    property color  gridColor: '#C6C4B5'

    property color cellNoCollisionColor: "#9EA79E"
    property color cellNoCollisionAlternativeColor: "#949B93"

    property color collisionBlockColor: "grey"

    property color cellInteractiveColor: "blue"
    property color cellUsableColor: "green"

    property color innerBotColor: "violet"
    property color aroundBotColor: "white"

    property color innerPlayerBotColor: "yellow"
    property color aroundPlayerBotColor: "white"

    property color innerPlayerColor: "blue"
    property color aroundPlayerColor: "white"

    property color innerMonsterColor: "white"
    property color aroundMonsterColor: "red"

    property color innerNpcColor: "orange"
    property color aroundNpcColor: "white"


    Connections
    {
        target: botInstance
        onEntityTypesChanged: canvas.requestPaint()
        onCollisionTypesChanged: canvas.requestPaint()
        onInteractiveTypesChanged: canvas.requestPaint()
    }

    Item
    {
        anchors.fill: parent
        anchors.margins: Units.dp(15)

        Item
        {
            id:canvasContainer

            anchors.left: parent.left
            anchors.top: parent.top
            anchors.rightMargin: Units.dp(25)
            width:parent.width-Units.dp(250)
            anchors.bottom: mapLabels.top

            Canvas {
                id: canvas

                property int ratio: Screen.devicePixelRatio

                clip:true
                scale: 1/ratio

                width: parent.width * ratio
                height: parent.height * ratio
                anchors.centerIn: parent

                renderStrategy: Canvas.Threaded
                antialiasing: true
                onPaint: draw();

                function draw()
                {
                    if(botInstance.collisionTypes.length !== 0)
                    {
                        var ctx = canvas.getContext("2d");
                        ctx.reset();
                        ctx.clearRect(0, 0, canvas.width, canvas.height);

                        var dimensionX = canvas.width/14*13.5/14
                        var dimensionY = canvas.height/20*19/20;

                        ctx.translate(0, dimensionY/2);

                        var index = 0;
                        for(var i = 0; i < 40; i++)
                        {
                            for(var j=0; j < 14; j++)
                            {
                                ctx.lineWidth = ratio
                                ctx.strokeStyle = gridColor

                                var margin = 0;

                                if(i%2 != 0)
                                {
                                    ctx.fillStyle = cellNoCollisionColor;
                                    margin = dimensionX/2;
                                }

                                else
                                    ctx.fillStyle = cellNoCollisionAlternativeColor;

                                if(botInstance.collisionTypes[index] === Bot.NOTHING)
                                {
                                    ctx.beginPath();

                                    ctx.moveTo(j*dimensionX+margin, (dimensionY/2)*(i+1)); // LEFT MIDDLE
                                    ctx.lineTo(dimensionX/2+j*dimensionX+margin, (dimensionY/2)*(i+2)); // BOTTOM MIDDLE
                                    ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1));    // RIGHT MIDDLE
                                    ctx.lineTo(dimensionX/2+j*dimensionX+margin, -(dimensionY/2)+(dimensionY/2)*(i+1)); // TOP MIDDLE

                                    ctx.lineTo(j*dimensionX+margin, (dimensionY/2)*(i+1)); // LEFT MIDDLE

                                    ctx.fill();

                                    if(botInstance.interactiveTypes[index] !== Bot.NOTHING)
                                    {
                                        if(botInstance.interactiveTypes[index] === Bot.INTERACTIVE)
                                            ctx.fillStyle = cellInteractiveColor

                                        else if(botInstance.interactiveTypes[index] === Bot.USABLE)
                                            ctx.fillStyle = cellUsableColor

                                        ctx.globalAlpha = 0.5
                                        ctx.fill();
                                        ctx.globalAlpha=1
                                    }

                                    ctx.stroke();
                                }

                                if(botInstance.collisionTypes[index] === Bot.COLLISION_NO_SIGHT)
                                {
                                    ctx.beginPath();

                                    ctx.moveTo(j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2); // LEFT MIDDLE
                                    ctx.lineTo(dimensionX/2+j*dimensionX+margin, dimensionY/2+(dimensionY/2)*(i+1)-dimensionY/2);  // BOTTOM MIDDLE
                                    ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2);  // RIGHT MIDDLE
                                    ctx.lineTo(dimensionX/2+j*dimensionX+margin, -(dimensionY/2)+(dimensionY/2)*(i+1)-dimensionY/2); // TOP MIDDLE

                                    ctx.fillStyle = collisionBlockColor;

                                    ctx.fill();

                                    if(botInstance.interactiveTypes[index] !== Bot.NOTHING)
                                    {
                                        if(botInstance.interactiveTypes[index] === Bot.INTERACTIVE)
                                            ctx.fillStyle = cellInteractiveColor

                                        else if(botInstance.interactiveTypes[index] === Bot.USABLE)
                                            ctx.fillStyle = cellUsableColor

                                        ctx.globalAlpha = 0.5
                                        ctx.fill();
                                        ctx.globalAlpha=1
                                    }


                                    ctx.beginPath();

                                    ctx.moveTo(j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2); // LEFT MIDDLE
                                    ctx.lineTo(j*dimensionX+margin, (dimensionY/2)*(i+1)); // LEFT MIDDLE
                                    ctx.lineTo(dimensionX/2+j*dimensionX+margin, (dimensionY/2)*(i+2)); // BOTTOM MIDDLE
                                    ctx.lineTo(dimensionX/2+j*dimensionX+margin, dimensionY/2+(dimensionY/2)*(i+1)-dimensionY/2); //BOTTOM MIDDLE

                                    ctx.fillStyle = collisionBlockColor;

                                    ctx.fill();

                                    if(botInstance.interactiveTypes[index] !== Bot.NOTHING)
                                    {
                                        if(botInstance.interactiveTypes[index] === Bot.INTERACTIVE)
                                            ctx.fillStyle = cellInteractiveColor

                                        else if(botInstance.interactiveTypes[index] === Bot.USABLE)
                                            ctx.fillStyle = cellUsableColor

                                        ctx.globalAlpha = 0.5
                                        ctx.fill();
                                        ctx.globalAlpha=1
                                    }

                                    ctx.beginPath();

                                    ctx.moveTo(dimensionX/2+j*dimensionX+margin, dimensionY/2+(dimensionY/2)*(i+1)-dimensionY/2);  // BOTTOM MIDDLE
                                    ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2);  // RIGHT MIDDLE
                                    ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1));    // RIGHT MIDDLE
                                    ctx.lineTo(dimensionX/2+j*dimensionX+margin, (dimensionY/2)*(i+2)); // BOTTOM MIDDLE

                                    ctx.fillStyle = collisionBlockColor;

                                    ctx.fill();

                                    if(botInstance.interactiveTypes[index] !== Bot.NOTHING)
                                    {
                                        if(botInstance.interactiveTypes[index] === Bot.INTERACTIVE)
                                            ctx.fillStyle = cellInteractiveColor

                                        else if(botInstance.interactiveTypes[index] === Bot.USABLE)
                                            ctx.fillStyle = cellUsableColor

                                        ctx.globalAlpha = 0.5
                                        ctx.fill();
                                        ctx.globalAlpha=1
                                    }

                                    ctx.beginPath();

                                    ctx.moveTo(j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2); // LEFT MIDDLE
                                    ctx.lineTo(j*dimensionX+margin, (dimensionY/2)*(i+1)); // LEFT MIDDLE
                                    ctx.lineTo(dimensionX/2+j*dimensionX+margin, (dimensionY/2)*(i+2)); // BOTTOM MIDDLE
                                    ctx.lineTo(dimensionX/2+j*dimensionX+margin, dimensionY/2+(dimensionY/2)*(i+1)-dimensionY/2);  // BOTTOM MIDDLE
                                    ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2);  // RIGHT MIDDLE
                                    ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1));  // RIGHT MIDDLE

                                    ctx.moveTo(dimensionX/2+j*dimensionX+margin, dimensionY/2+(dimensionY/2)*(i+1)-dimensionY/2);  // BOTTOM MIDDLE
                                    ctx.lineTo(j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2); // LEFT MIDDLE
                                    ctx.lineTo(dimensionX/2+j*dimensionX+margin, -(dimensionY/2)+(dimensionY/2)*(i+1)-dimensionY/2); // TOP MIDDLE
                                    ctx.lineTo(dimensionX+j*dimensionX+margin, (dimensionY/2)*(i+1)-dimensionY/2);  // RIGHT MIDDLE

                                    ctx.stroke();
                                }


                                if(botInstance.entityTypes[index] !== Bot.NOTHING)
                                {
                                    if(botInstance.entityTypes[index] === Bot.PLAYER)
                                    {
                                        ctx.fillStyle = innerPlayerColor;
                                        ctx.strokeStyle = aroundPlayerColor;
                                    }

                                    else if(botInstance.entityTypes[index] === Bot.PLAYER_BOT)
                                    {
                                        ctx.fillStyle = innerPlayerBotColor;
                                        ctx.strokeStyle = aroundPlayerBotColor;
                                    }

                                    else if(botInstance.entityTypes[index] === Bot.BOT)
                                    {
                                        ctx.fillStyle = innerBotColor;
                                        ctx.strokeStyle = aroundBotColor;
                                    }

                                    else if(botInstance.entityTypes[index] === Bot.NPC)
                                    {
                                        ctx.fillStyle = innerNpcColor;
                                        ctx.strokeStyle = aroundNpcColor;
                                    }

                                    else if(botInstance.entityTypes[index] === Bot.MONSTER)
                                    {
                                        ctx.fillStyle = innerMonsterColor;
                                        ctx.strokeStyle = aroundMonsterColor;
                                    }

                                    ctx.beginPath();

                                    ctx.lineWidth = dimensionY/8

                                    ctx.arc(j*dimensionX+margin+dimensionX/2, (dimensionY/2)*(i+1), dimensionY/4, 0, 2*Math.PI);
                                    ctx.fill();

                                    ctx.stroke();
                                }

                                index++;
                            }
                        }
                    }
                }
            }
        }

        Label {
            id: mapLabels

            clip:true
            minimumPointSize: Units.dp(1)
            font.pointSize: Units.dp(25)
            anchors.margins: Units.dp(5)
            anchors.bottom: parent.bottom
            anchors.left: canvasContainer.left
            width: canvasContainer.width
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter

            text: '<b><font color="' + innerBotColor + '">' + qsTr("Bot Courant") + '</font> - ' +
                  '<font color="' + innerPlayerBotColor + '">' + qsTr("Bots") + '</font> - ' +
                  '<font color="' + innerPlayerColor + '">' + qsTr("Joueurs") + '</font> - ' +
                  '<font color="' + aroundMonsterColor + '">' + qsTr("Monstres") + '</font> - ' +
                  '<font color="' + innerNpcColor + '">' + qsTr("PNJ") + '</font> - ' +
                  '<font color="' + cellInteractiveColor + '">'  + qsTr("E. Interactifs") + '</font> - ' +
                  '<font color="' + cellUsableColor + '">' + qsTr("E. Utilisables") + '</font></b>'
        }


        Item
        {
            id:controls

            anchors.top:parent.top
            anchors.bottom:parent.bottom
            anchors.right: parent.right
            anchors.left: canvasContainer.right

            Column
            {
                anchors.centerIn: parent
                spacing: Units.dp(60)
                anchors.margins: Units.dp(15)

                Column
                {
                    spacing: Units.dp(25)

                    PositionCard
                    {
                        id:pc
                        width: b.width
                        height: b.height*1.5
                    }

                    TextCard
                    {
                        width:pc.width
                        height:pc.height*0.6
                        iconName: "maps/add_location"
                        text: botInstance.mapId !== -1 ? ("MapId: "+botInstance.mapId) : ("MapId: "+qsTr("NaN"))
                    }
                }

                GridLayout
                {
                    rows:3
                    columns:3

                    anchors.horizontalCenter: parent.horizontalCenter


                    ActionButton{
                        Layout.row: 0
                        Layout.column: 1

                        iconName:"navigation/expand_less"
                        onClicked: botInstance.changeMapTop()
                    }

                    ActionButton{
                        Layout.row: 1
                        Layout.column: 0

                        iconName:"navigation/chevron_left"
                        onClicked: botInstance.changeMapLeft()
                    }

                    ActionButton{
                        Layout.row: 1
                        Layout.column: 2

                        iconName:"navigation/chevron_right"
                        onClicked: botInstance.changeMapRight()
                    }

                    ActionButton{
                        Layout.row: 2
                        Layout.column: 1

                        iconName:"navigation/expand_more"
                        onClicked: botInstance.changeMapBottom()
                    }
                }

                Button{
                    id: b
                    anchors.horizontalCenter: parent.horizontalCenter

                    elevation: 1
                    backgroundColor: Theme.primaryColor

                    text: qsTr("Elements interactifs")
                    onClicked: dialog.show()
                }
            }

        }
    }

    Dialog {
        id: dialog
        title: qsTr("Elements interactifs")
        hasActions: false

        Item
        {
            width:Units.dp(350)
            height:Units.dp(250)

            TableView {
                id: tableView
                anchors.fill: parent

                model: botInstance.interactiveModel

                numericalColumns: [1,2]

                TableViewColumn {
                    id: name
                    delegate: ViewDelegates.LabelDelegate {numericalColumns:tableView.numericalColumns}
                    title: qsTr("Nom")
                    role: "name"
                    movable: false
                    resizable: true
                    width: tableView.viewport.width - uid.width - cellId.width
                }

                TableViewColumn {
                    id: uid
                    delegate: ViewDelegates.LabelDelegate {numericalColumns:tableView.numericalColumns}
                    title: qsTr("UID")
                    role: "uid"
                    movable: false
                    resizable: false
                    width: tableView.viewport.width / 4
                }

                TableViewColumn {
                    id: cellId
                    delegate: ViewDelegates.LabelDelegate {numericalColumns:tableView.numericalColumns}
                    title: qsTr("CellID")
                    role: "cellId"
                    movable: false
                    resizable: false
                    width: tableView.viewport.width / 4
                }
            }

        }
    }
}

