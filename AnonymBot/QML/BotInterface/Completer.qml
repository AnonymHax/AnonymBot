import QtQuick 2.7
import QtQuick.Layouts 1.3
import Material 0.1
import Utils 1.0
import Material.ListItems 0.1 as ListItem

Item
{
    id:main

    property alias text:t.text
    property alias placeholderText: t.placeholderText
    property alias model: list.model
    property bool suggestionsOnTop: false

    signal accepted(string acceptedText)

    View {
        id: omnibox
        anchors.fill: parent
        radius: Units.dp(2)
        backgroundColor: "white"
        elevation: 1
        opacity: 1

        TextField {
            id:t
            anchors {
                left: parent.left
                right: parent.right
                top: parent.top
                bottom: parent.bottom
                leftMargin: Units.dp(16)
                rightMargin: Units.dp(16)
            }

            showBorder: false
            opacity: 1

            MouseArea {
                anchors.fill: parent
                propagateComposedEvents: true
                hoverEnabled:true

                onPressed: {
                    mouse.accepted = false;
                }
            }

            onTextChanged:{
                if(t.text !== list.model.data(list.currentIndex) || list.currentIndex === -1)
                {
                    list.currentIndex = -1;
                    list.model.update(t.text)
                }
            }

            onAccepted:
            {
                main.accepted(t.text)
                t.text = ""
            }

            Keys.onDownPressed: {
                if(!suggestionsOnTop && list.count-1 > list.currentIndex)
                {
                    list.currentIndex++
                    t.text=list.model.data(list.currentIndex)
                    selectAll()
                }

                else if(suggestionsOnTop && list.currentIndex > 0)
                {
                    list.currentIndex--
                    t.text=list.model.data(list.currentIndex)
                    selectAll()
                }
            }

            Keys.onUpPressed: {

                if(!suggestionsOnTop && list.currentIndex > 0)
                {
                    list.currentIndex--
                    t.text=list.model.data(list.currentIndex)
                    selectAll()
                }

                else if(suggestionsOnTop && list.count-1 > list.currentIndex)
                {
                    list.currentIndex++
                    t.text=list.model.data(list.currentIndex)
                    selectAll()
                }
            }
        }
    }

    View
    {
        anchors.top: suggestionsOnTop ? undefined : omnibox.bottom
        anchors.bottom: suggestionsOnTop ? omnibox.top : undefined
        anchors.left: omnibox.left
        anchors.right: omnibox.right


        height: (t.text === "" || !t.focus) ? 0 : (list.count >= 3 ? Units.dp(150) : Units.dp(50)*list.count)
        backgroundColor: "white"
        elevation: 1
        opacity: 1
        radius: Units.dp(2)
        Behavior on height { PropertyAnimation {} }

        PropertyAnimation { properties: "height"; easing.type: Easing.InOutQuad }

        ListView
        {
            id: list

            verticalLayoutDirection: suggestionsOnTop ? ListView.BottomToTop : ListView.TopToBottom
            anchors.fill: parent

            highlight: Rectangle {
                color: 'grey'
                opacity:0.2
            }

            delegate:
                ListItem.Standard
            {text:suggestion

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    list.currentIndex = index
                    main.accepted(list.model.data(list.currentIndex))
                    t.text = ""
                }
            }

        }
    }
}
}
