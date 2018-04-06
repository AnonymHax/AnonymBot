import QtQuick 2.7
import Utils 1.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.5
import Material 0.1

Card
{
    RowLayout
    {
        id: rowL
        anchors.fill: parent
        property int nbRows: 5


        ProgressCircle
        {
            id:c
            dashThickness: Units.dp(2)
            Layout.fillWidth : true
            Layout.fillHeight: true
            Layout.minimumWidth: parent.width/parent.nbRows-2*parent.spacing
            Layout.maximumWidth: Layout.minimumWidth
            indeterminate: false
            minimumValue: 0
            maximumValue: 10
            value: 10
            color : "transparent"// color : "#a39fad"


            ProgressCircle
            {
                id:d
                fillOpacity: 0.5
                dashThickness: c.dashThickness
                anchors.fill: parent
                indeterminate: false
                color: "#E32636"
                minimumValue: 0
                maximumValue: {botInstance.maxLifePoints == -1 ? 0 : botInstance.maxLifePoints}
                value: {botInstance.lifePoints == -1 ? 0 : botInstance.lifePoints}

                MouseArea {
                    property string t: qsTr("Vie")+ " - " + botInstance.lifePoints +" / "+ botInstance.maxLifePoints
                    anchors.fill: parent
                    hoverEnabled: parent.maximumValue != 0
                    Tooltip {
                        text: parent.t
                        mouseArea: parent
                    }
                }

                Icon
                {
                    anchors.centerIn:parent
                    name:"action/favorite"
                    height:{parent.height < parent.width ? parent.height/2 : parent.width/2}
                    width:height
                    color : parent.color
                }

                Behavior on value { SmoothedAnimation { velocity: botInstance.maxLifePoints/3 } }
            }
        }

        ProgressCircle
        {
            dashThickness: c.dashThickness
            Layout.fillWidth : true
            Layout.fillHeight: true
            Layout.minimumWidth: parent.width/parent.nbRows-2*parent.spacing
            Layout.maximumWidth: Layout.minimumWidth
            indeterminate: false
            minimumValue: 0
            maximumValue: 10
            value: 10
            color : c.color

            ProgressCircle
            {
                fillOpacity: d.fillOpacity
                dashThickness: c.dashThickness
                anchors.fill: parent
                indeterminate: false
                color : "#2c82ff"

                minimumValue: 0
                maximumValue: {botInstance.maxEnergyPoints == -1 ? 0 : botInstance.maxEnergyPoints}
                value: {botInstance.energyPoints == -1 ? 0 : botInstance.energyPoints}

                MouseArea {
                    property string t: qsTr("Energie")+ " - " + botInstance.energyPoints +" / "+ botInstance.maxEnergyPoints
                    anchors.fill: parent
                    hoverEnabled: parent.maximumValue != 0
                    Tooltip {
                        text: parent.t
                        mouseArea: parent
                    }
                }

                Icon
                {
                    anchors.centerIn:parent
                    name:"image/flash_on"
                    height:{parent.height < parent.width ? parent.height/2 : parent.width/2}
                    width:height
                    color : parent.color
                }

                Behavior on value { SmoothedAnimation { velocity: botInstance.maxEnergyPoints/3 } }
            }
        }

        ProgressCircle
        {
            dashThickness: c.dashThickness
            Layout.fillWidth : true
            Layout.fillHeight: true
            Layout.minimumWidth: parent.width/parent.nbRows-2*parent.spacing
            Layout.maximumWidth: Layout.minimumWidth
            indeterminate: false
            minimumValue: 0
            maximumValue: 10
            value: 10
            color : c.color

            ProgressCircle
            {
                fillOpacity: d.fillOpacity
                dashThickness: c.dashThickness
                anchors.fill: parent
                indeterminate: false
                color : "#4B0082"

                minimumValue: 0
                maximumValue: {botInstance.maxExperience == -1 ? 0 : botInstance.maxExperience}
                value: {botInstance.experience == -1 ? 0 : botInstance.experience}

                MouseArea {
                    property string t: qsTr("Experience")+ " - " + botInstance.experience +" / "+ botInstance.maxExperience
                    anchors.fill: parent
                    hoverEnabled: parent.maximumValue != 0
                    Tooltip {
                        text: parent.t
                        mouseArea: parent
                    }
                }

                Icon
                {
                    anchors.centerIn:parent
                    name:"toggle/star"
                    height:{parent.height < parent.width ? parent.height/2 : parent.width/2}
                    width:height
                    color : parent.color
                }

                Behavior on value { SmoothedAnimation { velocity: botInstance.maxExperience/3 } }
            }
        }

        ProgressCircle
        {
            property color positive: "#00cc00"
            property color negative: "#E32636"

            dashThickness: c.dashThickness
            Layout.fillWidth : true
            Layout.fillHeight: true
            Layout.minimumWidth: parent.width/parent.nbRows-2*parent.spacing
            Layout.maximumWidth: Layout.minimumWidth
            indeterminate: false
            minimumValue: 0
            maximumValue: 100
            value:
            {
                if(botInstance.connectionState != 1)
                    return 0

                else
                    return 100
            }

            color: negative

            ProgressCircle
            {
                fillOpacity: d.fillOpacity
                dashThickness: c.dashThickness
                anchors.fill: parent
                indeterminate: false
                minimumValue: 0
                color : parent.positive
                fillColor :
                {
                    if(value/maximumValue > 0.50)
                        return parent.positive;

                    else
                        return parent.negative;
                }

                maximumValue: 100
                value:
                {
                    if(botInstance.connectionState != 1)
                        return 0

                    else
                        return 60
                }

                MouseArea {
                    property string t : qsTr("Victoire(s) / Défaite(s)")+ " - " + parent.value +" / "+ parent.maximumValue
                    anchors.fill: parent
                    hoverEnabled: parent.maximumValue != 0
                    Tooltip {
                        text: parent.t
                        mouseArea: parent
                    }
                }

                Icon
                {
                    anchors.centerIn:parent
                    name:"action/thumbs_up_down"
                    height:{parent.height < parent.width ? parent.height/2 : parent.width/2}
                    width:height
                    color :
                    {
                        if(parent.value/parent.maximumValue > 0.50)
                            return parent.parent.positive;

                        else
                            return parent.parent.negative;
                    }
                }

                Behavior on value { SmoothedAnimation { velocity: 100/3 } }
            }

            Behavior on value { SmoothedAnimation { velocity: 100/3 } }
        }

        ProgressCircle
        {
            dashThickness: c.dashThickness
            Layout.fillWidth : true
            Layout.fillHeight: true
            Layout.minimumWidth: parent.width/parent.nbRows-2*parent.spacing
            Layout.maximumWidth: Layout.minimumWidth
            indeterminate: false
            minimumValue: 0
            maximumValue: 10
            value: 10
            color : c.color

            ProgressCircle
            {
                fillOpacity: d.fillOpacity
                dashThickness: c.dashThickness
                anchors.fill: parent
                indeterminate: false
                color: "#F6DC12"

                minimumValue: 0
                maximumValue: {botInstance.maxPods == -1 ? 0 : botInstance.maxPods}
                value: {botInstance.pods == -1 ? 0 : botInstance.maxPods-botInstance.pods}

                MouseArea {
                    property string t: qsTr("Pods")+ " - " + botInstance.pods +" / "+ botInstance.maxPods
                    anchors.fill: parent
                    hoverEnabled: parent.maximumValue != 0
                    Tooltip {
                        text: parent.t
                        mouseArea: parent
                    }
                }

                Icon
                {
                    anchors.centerIn:parent
                    name:"action/work"
                    height:{parent.height < parent.width ? parent.height/2 : parent.width/2}
                    width:height
                    color : "#B8860B"
                }

                Behavior on value { SmoothedAnimation { velocity: botInstance.maxPods/3 } }
            }

        }
    }
}

