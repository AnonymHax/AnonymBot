#include "ExchangeModule.h"

ExchangeModule::ExchangeModule(QMap<SocketIO *, BotData> *connectionsData):
    AbstractModule(ModuleType::EXCHANGE, connectionsData)
{
}

void ExchangeModule::reset(SocketIO *sender)
{
    m_botData[sender].exchangeData.sourceId = INVALID;
    m_botData[sender].exchangeData.isLackingKamas = false;
    m_botData[sender].exchangeData.objects.clear();
    m_botData[sender].exchangeData.step = 0;
    m_botData[sender].exchangeData.currentKamas = 0;
    m_botData[sender].exchangeData.isActive = false;
    m_botData[sender].exchangeData.isExchangingWithMaster = false;
}

void ExchangeModule::setState(SocketIO *sender, bool state)
{
    m_botData[sender].exchangeData.isActive = state;

    if(state)
        m_botData[sender].exchangeData.isLackingKamas = false;
}

bool ExchangeModule::isActive(SocketIO *sender) const
{
    return m_botData[sender].exchangeData.isActive;
}

void ExchangeModule::addRequestedObject(SocketIO *sender, const RequestTradeObject &item)
{
    int size = m_botData[sender].exchangeData.requestList.size();
    bool alreadyExist = false;

    for(int i = 0; i < size; i++)
    {
        if(m_botData[sender].exchangeData.requestList[i].GID == item.GID)
        {
            m_botData[sender].exchangeData.requestList[i] = item;
            alreadyExist = true;
            break;
        }
    }

    if(!alreadyExist)
        m_botData[sender].exchangeData.requestList<<item;
}

void ExchangeModule::removeRequestedObject(SocketIO *sender, uint objectGID)
{
    int size = m_botData[sender].exchangeData.requestList.size();

    for(int i = 0; i < size; i++)
    {
        if(m_botData[sender].exchangeData.requestList[i].GID == objectGID)
        {
            m_botData[sender].exchangeData.requestList.removeAt(i);
            break;
        }
    }
}

void ExchangeModule::updateExchange(SocketIO *sender)
{
    if(!m_botData[sender].exchangeData.isExchangingWithMaster)
    {
        int objectsCount = m_botData[sender].exchangeData.objects.size();
        int requestsCount = m_botData[sender].exchangeData.requestList.size();
        int kamas = 0;

        for(int i = 0; i < objectsCount; i++)
        {
            for(int j = 0; j < requestsCount; j++)
            {
                if(m_botData[sender].exchangeData.objects[i].GID == m_botData[sender].exchangeData.requestList[j].GID)
                {
                    if(m_botData[sender].exchangeData.objects[i].quantity <= m_botData[sender].exchangeData.requestList[j].quantity)
                    {
                        if(m_botData[sender].generalData.botState != EXCHANGING_STATE && m_botData[sender].exchangeData.requestList[j].quantity != -1)
                            m_botData[sender].exchangeData.requestList[j].quantity -= m_botData[sender].exchangeData.objects[i].quantity;

                        else if(m_botData[sender].generalData.botState == EXCHANGING_STATE)
                            kamas += m_botData[sender].exchangeData.objects[i].quantity * m_botData[sender].exchangeData.requestList[j].price;
                    }

                    else
                    {
                        if(m_botData[sender].generalData.botState != EXCHANGING_STATE)
                            m_botData[sender].exchangeData.requestList[j].quantity = 0;

                        else
                            kamas += m_botData[sender].exchangeData.requestList[j].price * m_botData[sender].exchangeData.requestList[j].quantity;
                    }

                    if(m_botData[sender].exchangeData.requestList[j].quantity == 0)
                    {
                        m_botData[sender].exchangeData.requestList.removeAt(j);
                        j--;
                        requestsCount--;
                    }
                }
            }
        }


        if(kamas > m_botData[sender].playerData.kamas)
        {
            if(m_botData[sender].exchangeData.isLackingKamas == false)
            {
                m_botData[sender].exchangeData.isLackingKamas = true;
                alert(sender)<<"Il n'y a plus assez d'argent pour les échanges, désactivation du module...";
                setState(sender, false);
            }

            kamas = m_botData[sender].playerData.kamas;

            if(kamas != m_botData[sender].exchangeData.currentKamas)
            {
                m_botData[sender].exchangeData.currentKamas = kamas;
                ExchangeObjectMoveKamaMessage answer;
                answer.quantity = kamas;
                sender->send(answer);
            }
        }

        else if(kamas != m_botData[sender].exchangeData.currentKamas)
        {
            m_botData[sender].exchangeData.currentKamas = kamas;
            ExchangeObjectMoveKamaMessage answer;
            answer.quantity = kamas;
            sender->send(answer);
        }
    }
}

bool ExchangeModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::EXCHANGEREQUESTEDTRADEMESSAGE:
    {
        ExchangeRequestedTradeMessage message;
        message.deserialize(&reader);

        m_botData[sender].exchangeData.sourceId = message.source;

        if((m_botData[sender].exchangeData.isActive || m_botData[sender].mapData.playersOnMap[message.source].name == m_botData[sender].groupData.master) &&
                m_botData[sender].generalData.botState == INACTIVE_STATE)
        {
            ExchangeAcceptMessage answer;
            sender->send(answer);
        }

        else
        {
            action(sender)<<"Echange avec"<<m_botData[sender].mapData.playersOnMap[m_botData[sender].exchangeData.sourceId].name<<"refusé par le bot";

            if(m_botData[sender].generalData.botState != INACTIVE_STATE)
                qDebug()<<"ERREUR - ExchangeModule ne peut lancer l'échange car le bot est occupé";

            LeaveDialogRequestMessage answer;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::EXCHANGESTARTEDWITHPODSMESSAGE:
    {
        m_botData[sender].exchangeData.currentKamas = 0;
        m_botData[sender].generalData.botState = EXCHANGING_STATE;
        m_botData[sender].exchangeData.step = 0;
        m_botData[sender].exchangeData.objects.clear();

        if(m_botData[sender].mapData.playersOnMap[m_botData[sender].exchangeData.sourceId].name == m_botData[sender].groupData.master)
        {
            m_botData[sender].exchangeData.isExchangingWithMaster = true;
            action(sender)<<"Echange avec "<<m_botData[sender].mapData.playersOnMap[m_botData[sender].exchangeData.sourceId].name<<"(chef) en cours...";
            ExchangeObjectMoveKamaMessage answer;
            answer.quantity = m_botData[sender].playerData.kamas;
            sender->send(answer);
        }

        else
        {
            m_botData[sender].exchangeData.isExchangingWithMaster = false;
            action(sender)<<"Echange avec"<<m_botData[sender].mapData.playersOnMap[m_botData[sender].exchangeData.sourceId].name<<"en cours...";
        }
    }
        break;

    case MessageEnum::EXCHANGELEAVEMESSAGE:
    {
        ExchangeLeaveMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].generalData.botState == EXCHANGING_STATE)
        {
            m_botData[sender].generalData.botState = INACTIVE_STATE;

            if(message.success)
            {
                updateExchange(sender);
                action(sender)<<"Succès de l'échange";
            }

            else
                action(sender)<<"Echec de l'échange";
        }

        else
            m_botData[sender].generalData.botState = INACTIVE_STATE;
    }
        break;

    case MessageEnum::EXCHANGEOBJECTADDEDMESSAGE:
    {
        ExchangeObjectAddedMessage message;
        message.deserialize(&reader);

        if(message.remote)
        {
            InventoryObject item;
            item.GID = message.object->objectGID;
            item.UID = message.object->objectUID;
            item.quantity = message.object->quantity;

            m_botData[sender].exchangeData.objects<<item;
            updateExchange(sender);
        }

        m_botData[sender].exchangeData.step++;
    }
        break;

    case MessageEnum::EXCHANGEOBJECTMODIFIEDMESSAGE:
    {
        ExchangeObjectModifiedMessage message;
        message.deserialize(&reader);

        if(message.remote)
        {
            int size = m_botData[sender].exchangeData.objects.size();
            for(int i = 0; i < size; i++)
            {
                if(m_botData[sender].exchangeData.objects[i].UID == message.object->objectUID)
                {
                    InventoryObject item;
                    item.GID = message.object->objectGID;
                    item.UID = message.object->objectUID;
                    item.quantity = message.object->quantity;

                    m_botData[sender].exchangeData.objects[i] = item;
                    break;
                }
            }

            updateExchange(sender);
        }

        m_botData[sender].exchangeData.step++;
    }
        break;

    case MessageEnum::EXCHANGEOBJECTREMOVEDMESSAGE:
    {
        ExchangeObjectRemovedMessage message;
        message.deserialize(&reader);

        if(message.remote)
        {
            int size = m_botData[sender].exchangeData.objects.size();
            for(int i = 0; i < size; i++)
            {
                if(message.objectUID == m_botData[sender].exchangeData.objects[i].UID)
                {
                    m_botData[sender].exchangeData.objects.removeAt(i);
                    break;
                }
            }
            updateExchange(sender);
        }

        m_botData[sender].exchangeData.step++;
    }
        break;

    case MessageEnum::EXCHANGEISREADYMESSAGE:
    {
        ExchangeIsReadyMessage message;
        message.deserialize(&reader);

        if(message.ready)
        {
            ExchangeReadyMessage answer;
            answer.ready = true;
            answer.step = m_botData[sender].exchangeData.step;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::EXCHANGEKAMAMODIFIEDMESSAGE:
    {
        ExchangeKamaModifiedMessage message;
        message.deserialize(&reader);

        if(message.remote)
            updateExchange(sender);

        m_botData[sender].exchangeData.step++;

    }
        break;

    }

    return messageFound;
}
