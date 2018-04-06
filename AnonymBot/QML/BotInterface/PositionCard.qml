import QtQuick 2.7
import Utils 1.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.5
import Material 0.1

TextCard
{
    property string area:
    {
        if(botInstance.area.length != 0)
            return botInstance.area

        else
            return qsTr("Inconnue")
    }
    property string subArea:
    {
        if(botInstance.subArea.length != 0)
            return botInstance.subArea

        else
            return qsTr("Inconnue")
    }
    property string s_x:
    {
        if(botInstance.area.length != 0)
            return botInstance.position.x

        else
            return qsTr("NaN")
    }
    property string s_y:
    {
        if(botInstance.area.length != 0)
            return botInstance.position.y

        else
            return qsTr("NaN")
    }

    iconName:"maps/place"
    iconColor:"#E32636"

    text: ""+qsTr("Localisation")+": "+area+" - "+subArea+"\n"+qsTr("Position")+": [ "+s_x+", "+s_y+" ]";
}
