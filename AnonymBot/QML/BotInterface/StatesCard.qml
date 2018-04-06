import QtQuick 2.7
import Utils 1.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.5
import Material 0.1

TextCard
{
    property string state:
    {
        if (botInstance.botState === Bot.INACTIVE_STATE)
            return qsTr("Inactif")

        else if(botInstance.botState === Bot.EXCHANGING_STATE)
            return qsTr("En échange")

        else if(botInstance.botState === Bot.MAP_TRANSITION_STATE)
            return qsTr("Changement de carte")

        else if(botInstance.botState === Bot.MOVING_STATE)
            return qsTr("En déplacement")

        else if(botInstance.botState === Bot.CALCULATING_STATE)
            return qsTr("En calcul...")

        else if(botInstance.botState === Bot.FIGHTING_STATE)
            return qsTr("En combat")

        else if(botInstance.botState === Bot.FARMING_STATE)
            return qsTr("En récolte")

        else if(botInstance.botState === Bot.CRAFTING_STATE)
            return qsTr("En craft")

        else if(botInstance.botState === Bot.BANKING_STATE)
            return qsTr("En banque")

        else if(botInstance.botState === Bot.REGENERATING_STATE)
            return qsTr("En regénération")

        return qsTr("NaN")
    }

    property string _color: {
        if (botInstance.botState === Bot.INACTIVE_STATE)
            return "red"

        else if(botInstance.botState === Bot.EXCHANGING_STATE)
            return "orange"

        else if(botInstance.botState === Bot.MAP_TRANSITION_STATE ||
                botInstance.botState === Bot.MOVING_STATE)
            return "violet"

        else if(botInstance.botState === Bot.CALCULATING_STATE)
            return "#ffcb05"

        else if(botInstance.botState === Bot.FIGHTING_STATE)
            return "pink"

        else if(botInstance.botState === Bot.FARMING_STATE)
            return "#01b1da"

        else if(botInstance.botState === Bot.CRAFTING_STATE)
            return "#f4f4f4"

        else if(botInstance.botState === Bot.BANKING_STATE)
            return "#bbbbbb"

        else if(botInstance.botState === Bot.REGENERATING_STATE)
            return "#ffa0a6"

        return ""
    }

    iconName:"action/account_circle"
    text: 'État: <font color="' + _color + '">' + state + "</font><br />Trajet en cours: trajet.txt<br />Maitre du trajet: Jean-Cédrique\n"
}
