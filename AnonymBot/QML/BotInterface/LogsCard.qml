import QtQuick 2.7
import Utils 1.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.5
import Material 0.1

Card
{
    Connections
    {
        target: botInstance
        onAddConsoleLineRequest:
        {
            textEdit.append(content);
            var y = textEdit.contentHeight-flickArea.height;

            if(y > 0)
                flickArea.contentY = textEdit.contentHeight-flickArea.height;
        }
    }

    Scrollbar
    {
        flickableItem: flickArea
    }

    Flickable
    {
        id: flickArea
        anchors.fill: parent
        anchors.margins: Units.dp(5)
        contentWidth: parent.width
        contentHeight: textEdit.contentHeight
        flickableDirection: Flickable.VerticalFlick
        clip: true

        Behavior on contentY { PropertyAnimation {} }

        PropertyAnimation { properties: "contentY"; easing.type: Easing.InOutQuad }

        TextEdit
        {
            anchors.fill: parent
            id: textEdit

            readOnly: true
            textFormat: TextEdit.RichText
            wrapMode: TextEdit.WordWrap
            mouseSelectionMode: TextEdit.SelectCharacters
            selectByMouse: true
        }
    }

}
