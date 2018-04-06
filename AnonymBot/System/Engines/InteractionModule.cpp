#include "InteractionModule.h"

InteractionModule::InteractionModule(QMap<SocketIO *, BotData> *connectionsData, MapModule *mapModule):
    AbstractModule(ModuleType::INTERACTION, connectionsData),
    m_mapModule(mapModule)
{
}

void InteractionModule::reset(SocketIO *sender)
{
    m_botData[sender].interactionData.actionID = INVALID;
    m_botData[sender].interactionData.finishedAction = true;
    m_botData[sender].interactionData.interactionId = INVALID;
    m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
}

bool InteractionModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

        // todo: supprimer cette partie redondante dans MapModule
    case MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE:
    {
        m_botData[sender].interactionData.interactives.clear();
        foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
        {
            InteractiveDisplayInfos i;
            i.id = e.elementId;
            i.cellId = m_botData[sender].mapData.map.getInteractiveElementCellID(e.elementId);
            i.name = qSharedPointerCast<InteractiveData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INTERACTIVES, e.elementTypeId))->getName();

            m_botData[sender].interactionData.interactives << i;
        }

        foreach (uint npc, m_botData[sender].mapData.npcsOnMap.keys())
        {
            InteractiveDisplayInfos i;
            i.id = npc;
            i.cellId = m_botData[sender].mapData.npcsOnMap[npc].cellId;
            i.name = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, npc))->getName();

            m_botData[sender].interactionData.interactives << i;
        }
    }
        break;

    case MessageEnum::INTERACTIVEUSEERRORMESSAGE:
    {
        if (m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
        {
            alert(sender) << "Interaction Module - Le bot n'a pas pu interagir avec l'élément spécifié (npc, zaap(i), item).";
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
        }
    }
        break;

    case MessageEnum::INTERACTIVEUSEDMESSAGE:
    {
        if (m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
        {
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();

            m_confirmAction << sender;
            QTimer::singleShot(1000, this, SLOT(confirmAction()));
        }
    }
        break;

    case MessageEnum::LEAVEDIALOGMESSAGE:
    {
        if ((m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
                && (m_botData[sender].generalData.botState == BotState::INACTIVE_STATE)
                && (m_botData[sender].interactionData.interactionId != INVALID))
        {
            QString name;
            foreach (int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::NPCS))
            {
                QSharedPointer<NpcData> npc = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, index));

                if (npc->getId() == m_botData[sender].interactionData.interactionId)
                    name = npc->getName();
            }

            if ((name != "Banquier") && (name != "Al Etsop") && (name != "Essiac d'Engrape"))
            {
                m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
                m_botData[sender].interactionData.interactionId = INVALID;
                m_botData[sender].interactionData.finishedAction = true;
                m_botData[sender].interactionData.actionID = INVALID;
                m_botData[sender].interactionData.npcDialogs.clear();
                emit scriptActionDone(sender);
            }

            else
            {
                m_finishedAction << sender;
                QTimer::singleShot(15000, this, SLOT(finishAction()));
                m_botData[sender].interactionData.finishedAction = false;
            }
        }

        else
        {
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
        }
    }
        break;

    case MessageEnum::EXCHANGELEAVEMESSAGE:
    {
        if ((m_botData[sender].generalData.botState == BotState::BANKING_STATE) || (m_botData[sender].interactionData.interactionType == CurrentInteraction::BANK))
        {
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
        }
    }
        break;

    case MessageEnum::ZAAPLISTMESSAGE:
    {
        ZaapListMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].generalData.botState == BotState::INACTIVE_STATE)
        {
            if (!message.mapIds.contains(m_botData[sender].interactionData.interactionId))
            {
                alert(sender) << "Interaction Module - Le bot n'a pas pu utiliser le zaap car la destination est inconnue.";
                m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
                m_botData[sender].interactionData.interactionId = INVALID;
                m_botData[sender].interactionData.finishedAction = true;
                m_botData[sender].interactionData.actionID = INVALID;
                m_botData[sender].interactionData.npcDialogs.clear();
                emit scriptActionDone(sender);
            }

            else
            {
                TeleportRequestMessage reply;
                reply.teleporterType = message.teleporterType;
                reply.mapId = m_botData[sender].interactionData.interactionId;

                m_finishedAction << sender;
                QTimer::singleShot(15000, this, SLOT(finishAction()));
                m_botData[sender].interactionData.finishedAction = false;

                sender->send(reply);
            }
        }

        else
        {
            alert(sender) << "Interaction Module - Le bot n'a pas pu utiliser le zaap car la destination est inconnue.";
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
        }
    }
        break;

    case MessageEnum::TELEPORTDESTINATIONSLISTMESSAGE:
    {
        TeleportDestinationsListMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].generalData.botState == BotState::INACTIVE_STATE)
        {
            if (!message.mapIds.contains(m_botData[sender].interactionData.interactionId))
            {
                alert(sender) << "Interaction Module - Le bot n'a pas pu utiliser le zaap car la destination est inconnue.";
                m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
                m_botData[sender].interactionData.interactionId = INVALID;
                m_botData[sender].interactionData.finishedAction = true;
                m_botData[sender].interactionData.actionID = INVALID;
                m_botData[sender].interactionData.npcDialogs.clear();
                emit scriptActionDone(sender);
            }

            else
            {
                TeleportRequestMessage reply;
                reply.teleporterType = message.teleporterType;
                reply.mapId = m_botData[sender].interactionData.interactionId;

                m_finishedAction << sender;
                QTimer::singleShot(15000, this, SLOT(finishAction()));
                m_botData[sender].interactionData.finishedAction = false;

                sender->send(reply);
            }
        }

        else
        {
            alert(sender) << "Interaction Module - Le bot n'a pas pu utiliser le zaap car la destination est inconnue.";
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
        }
    }

    case MessageEnum::NPCDIALOGCREATIONMESSAGE:
    {
        NpcDialogCreationMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].interactionData.interactionType == CurrentInteraction::NONE
                || m_botData[sender].interactionData.interactionId ==  INVALID)
        {
            LeaveDialogRequestMessage reply;
            sender->send(reply);

            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
        }

        else
        {
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NPC;
            m_waitingReplies << sender;
        }
    }
        break;

    case MessageEnum::NPCDIALOGQUESTIONMESSAGE:
    {
        NpcDialogQuestionMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].interactionData.interactionType == CurrentInteraction::NONE
                || m_botData[sender].interactionData.interactionId ==  INVALID)
        {
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            m_waitingReplies.removeOne(sender);

            LeaveDialogRequestMessage reply;
            sender->send(reply);

            emit scriptActionDone(sender);
        }

        else
        {
            m_botData[sender].interactionData.npcDialogs = message.visibleReplies;
            if (m_waitingReplies.contains(sender))
            {
                m_waitingReplies.removeOne(sender);
                emit scriptActionDone(sender);
            }
        }
    }
        break;

    case MessageEnum::EXCHANGESTARTEDWITHSTORAGEMESSAGE:
    {
        if ((m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
                && m_botData[sender].generalData.botState == BotState::INACTIVE_STATE
                && (m_botData[sender].interactionData.interactionId != INVALID))
        {
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].generalData.botState = BotState::BANKING_STATE;
            m_botData[sender].interactionData.interactionType = CurrentInteraction::BANK;
        }
    }
        break;

    case MessageEnum::STORAGEINVENTORYCONTENTMESSAGE:
    {
        StorageInventoryContentMessage message;
        message.deserialize(&reader);

        if ((m_botData[sender].interactionData.interactionType == CurrentInteraction::BANK)
                && m_botData[sender].generalData.botState == BotState::BANKING_STATE
                && (m_botData[sender].interactionData.interactionId != INVALID))
        {
            QList<QSharedPointer<ObjectItem>> toTake;
            QMap<int, int> toTakeQuantity;
            QList<InventoryObject> toDeposit;
            QMap<int, int> toDepositQuantity;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].generalData.botState = BotState::BANKING_STATE;

            //Process deposit items
            foreach (InventoryObject o, m_botData[sender].playerData.inventoryContent)
                if (concernedByBankDeposit(sender, o.GID))
                    toDeposit << o;

            for (int i = 0; i < toDeposit.size(); i++)
                for (int j = 0; j < m_botData[sender].interactionData.bankData.deposit.size(); j++)
                    if (toDeposit[i].GID == m_botData[sender].interactionData.bankData.deposit[j].itemId)
                        toDepositQuantity[toDeposit[i].UID] = qCeil(toDeposit[i].quantity * (float)(m_botData[sender].interactionData.bankData.deposit[j].pods / 100.0));

            //Process take items
            foreach (QSharedPointer<ObjectItem> o, message.objects)
                if (concernedByBankTake(sender, o->objectGID))
                    toTake << o;

            int freePods = m_botData[sender].playerData.stats.pods.max - m_botData[sender].playerData.stats.pods.current;
            for (int i = 0; i < toTake.size(); i++)
            {
                for (int j = 0; j < m_botData[sender].interactionData.bankData.take.size(); j++)
                {
                    if (toTake[i]->objectGID == m_botData[sender].interactionData.bankData.take[j].itemId)
                    {
                        int quantity = std::fmin(toTake[i]->quantity, qCeil(freePods * (m_botData[sender].interactionData.bankData.take[j].pods /100)));
                        toTakeQuantity[toTake[i]->objectUID] = quantity;
                        freePods -= quantity;
                    }
                }
            }

            m_botData[sender].interactionData.bankData.toDepositQuantity = toDepositQuantity;
            m_botData[sender].interactionData.bankData.toTakeQuantity = toTakeQuantity;

            if (m_botData[sender].interactionData.bankData.toDepositQuantity.size())
            {
                ExchangeObjectMoveMessage depositMessage;
                depositMessage.objectUID = m_botData[sender].interactionData.bankData.toDepositQuantity.firstKey();
                depositMessage.quantity = m_botData[sender].interactionData.bankData.toDepositQuantity.first();
                sender->send(depositMessage);

                info(sender) << "Depot en banque de" << m_botData[sender].interactionData.bankData.toDepositQuantity.first() << nameFromUid(sender, m_botData[sender].interactionData.bankData.toDepositQuantity.firstKey());
                depositMessage.objectUID = m_botData[sender].interactionData.bankData.toDepositQuantity.remove(depositMessage.objectUID = m_botData[sender].interactionData.bankData.toDepositQuantity.firstKey());
            }

            else if (m_botData[sender].interactionData.bankData.toTakeQuantity.size())
            {
                ExchangeObjectMoveMessage takeMessage;
                takeMessage.objectUID = m_botData[sender].interactionData.bankData.toTakeQuantity.firstKey();
                takeMessage.quantity = m_botData[sender].interactionData.bankData.toTakeQuantity.first();
                sender->send(takeMessage);

                info(sender) << "Prise en banque de" << m_botData[sender].interactionData.bankData.toTakeQuantity.first() << nameFromUid(sender, m_botData[sender].interactionData.bankData.toTakeQuantity.firstKey());
                takeMessage.objectUID = m_botData[sender].interactionData.bankData.toTakeQuantity.remove(m_botData[sender].interactionData.bankData.toTakeQuantity.firstKey());
            }

            else
            {
                LeaveDialogRequestMessage reply;
                sender->send(reply);
            }
        }
    }
        break;

    case MessageEnum::STORAGEOBJECTUPDATEMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::BANKING_STATE)
        {
            if (m_botData[sender].interactionData.bankData.toDepositQuantity.size())
            {
                ExchangeObjectMoveMessage depositMessage;
                depositMessage.objectUID = m_botData[sender].interactionData.bankData.toDepositQuantity.firstKey();
                depositMessage.quantity = m_botData[sender].interactionData.bankData.toDepositQuantity.first();
                sender->send(depositMessage);

                info(sender) << "Depot en banque de" << m_botData[sender].interactionData.bankData.toDepositQuantity.first() << nameFromUid(sender, m_botData[sender].interactionData.bankData.toDepositQuantity.firstKey());
                depositMessage.objectUID = m_botData[sender].interactionData.bankData.toDepositQuantity.remove(depositMessage.objectUID = m_botData[sender].interactionData.bankData.toDepositQuantity.firstKey());
            }

            else if (m_botData[sender].interactionData.bankData.toTakeQuantity.size())
            {
                ExchangeObjectMoveMessage takeMessage;
                takeMessage.objectUID = m_botData[sender].interactionData.bankData.toTakeQuantity.firstKey();
                takeMessage.quantity = m_botData[sender].interactionData.bankData.toTakeQuantity.first();
                sender->send(takeMessage);

                info(sender) << "Prise en banque de" << m_botData[sender].interactionData.bankData.toTakeQuantity.first() << nameFromUid(sender, m_botData[sender].interactionData.bankData.toTakeQuantity.firstKey());
                takeMessage.objectUID = m_botData[sender].interactionData.bankData.toTakeQuantity.remove(m_botData[sender].interactionData.bankData.toTakeQuantity.firstKey());
            }

            else
            {
                LeaveDialogRequestMessage reply;
                sender->send(reply);
            }
        }

        else
        {
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
        }
    }
        break;

    }

    return messageFound;
}

bool InteractionModule::processZaap(SocketIO *sender, int mapId)
{
    if ((m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
            || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE
            || m_botData[sender].interactionData.interactionId != INVALID
            || !m_botData[sender].interactionData.npcDialogs.isEmpty())
        return false;

    bool found = false;
    InteractiveElementInfos element;
    foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
    {
        if (qSharedPointerCast<InteractiveData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INTERACTIVES, e.elementTypeId))->getName() == "Zaap")
        {
            found = true;
            element = e;
        }
    }

    if (!found)
        return false;

    m_botData[sender].interactionData.interactionId = mapId;
    m_botData[sender].interactionData.interactionType = CurrentInteraction::ZAAP;
    connect(m_mapModule, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(moved(SocketIO*)));
    connect(m_mapModule, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(noMovement(SocketIO*)));
    m_mapModule->changeCell(sender, m_botData[sender].mapData.map.getInteractiveElementCellID(element.elementId));
}

bool InteractionModule::processZaapi(SocketIO *sender, int mapId)
{
    if ((m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
            || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE
            || m_botData[sender].interactionData.interactionId != INVALID
            || !m_botData[sender].interactionData.npcDialogs.isEmpty())
        return false;

    bool found = false;
    InteractiveElementInfos element;
    foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
    {
        if (qSharedPointerCast<InteractiveData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INTERACTIVES, e.elementTypeId))->getName() == "Zaapi")
        {
            found = true;
            element = e;
        }
    }

    if (!found)
        return false;

    m_botData[sender].interactionData.interactionId = mapId;
    m_botData[sender].interactionData.interactionType = CurrentInteraction::ZAAPI;
    connect(m_mapModule, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(moved(SocketIO*)));
    connect(m_mapModule, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(noMovement(SocketIO*)));
    m_mapModule->changeCell(sender, m_botData[sender].mapData.map.getInteractiveElementCellID(element.elementId));
}

bool InteractionModule::processNpcInteraction(SocketIO *sender, int cellId)
{
    if ((m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
            || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE
            || m_botData[sender].interactionData.interactionId != INVALID
            || !m_botData[sender].interactionData.npcDialogs.isEmpty())
        return false;

    NpcInfos npc;
    bool found = false;
    foreach (NpcInfos pnj, m_botData[sender].mapData.npcsOnMap.values())
    {
        if (pnj.cellId == cellId)
        {
            npc = pnj;
            found = true;
        }
    }

    if (!found)
    {
        alert(sender) << "Interaction Module - Le bot n'a pas pu interagir avec le PNJ (id:" + QString::number(npc.npcId) + ")";
        m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
        m_botData[sender].interactionData.interactionId = INVALID;
        m_botData[sender].interactionData.npcDialogs.clear();
        return false;
    }

    QMap<int, QString> actions;
    m_botData[sender].interactionData.interactionId = npc.npcId;
    m_botData[sender].interactionData.interactionType = CurrentInteraction::NPC;
    foreach (int j, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::NPCACTIONS))
    {
        QSharedPointer<NpcActionData> npcAction = qSharedPointerCast<NpcActionData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCACTIONS, j));
        actions[npcAction->getId()] = npcAction->getName();
    }

    foreach (int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::NPCS))
    {
        QSharedPointer<NpcData> npcData = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, index));
        if (npcData->getId() == npc.npcId)
        {
            for (int k = 0; k < npcData->getActions().size(); k++)
            {
                if (actions[npcData->getActions()[k]] == "Parler")
                {
                    NpcGenericActionRequestMessage message;
                    message.npcMapId = m_botData[sender].mapData.map.getMapId();
                    message.npcActionId = npcData->getActions()[k];
                    message.npcId = npc.contextualId;

                    m_finishedAction << sender;
                    QTimer::singleShot(15000, this, SLOT(finishAction()));
                    m_botData[sender].interactionData.finishedAction = false;

                    sender->send(message);
                    return true;
                }
            }
        }
    }

    alert(sender) << "Interaction Module - Le bot n'a pas pu interagir avec le PNJ (id:" + QString::number(npc.npcId) + ")";
    m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
    m_botData[sender].interactionData.interactionId = INVALID;
    m_botData[sender].interactionData.npcDialogs.clear();
    return false;
}

bool InteractionModule::processUse(SocketIO *sender, int id, QString action)
{
    if ((m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
            || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE
            || m_botData[sender].interactionData.interactionId != INVALID
            || !m_botData[sender].interactionData.npcDialogs.isEmpty())
        return false;

    int skill = INVALID;
    InteractiveElementInfos elem;
    foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
    {
        if (e.elementId == id)
        {
            elem = e;
            foreach (int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::SKILLS))
            {
                if (qSharedPointerCast<SkillData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SKILLS, index))->getName().indexOf(action, Qt::CaseInsensitive) >= 0)
                    skill = qSharedPointerCast<SkillData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SKILLS, index))->getId();
            }
        }
    }

    if (action.isEmpty() && elem.enabledSkills.size())
        skill = elem.enabledSkills.first().ID;

    if (skill == INVALID)
        return false;

    m_botData[sender].interactionData.actionID = skill;
    m_botData[sender].interactionData.interactionId = elem.elementId;
    m_botData[sender].interactionData.interactionType = CurrentInteraction::ITEM;
    connect(m_mapModule, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(moved(SocketIO*)));
    connect(m_mapModule, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(noMovement(SocketIO*)));
    m_mapModule->changeToNearestCell(sender, m_botData[sender].mapData.map.getInteractiveElementCellID(elem.elementId));

    return true;
}

bool InteractionModule::processNpcDialog(SocketIO *sender, QString dialog)
{
    if (m_botData[sender].interactionData.interactionType == CurrentInteraction::NONE
            || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE
            || m_botData[sender].interactionData.interactionId == INVALID
            || m_botData[sender].interactionData.npcDialogs.isEmpty())
    {
        alert(sender) << "InteractionModule - Le bot n'a pas pu dialoguer avec le PNJ (id:" + QString::number(m_botData[sender].interactionData.interactionId) + ")";
        return false;
    }

    int replyID = INVALID;
    QMap<int, QPoint> replies;
    foreach (int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::NPCS))
    {
        QSharedPointer<NpcData> npc = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, index));
        if (npc->getId() == m_botData[sender].interactionData.interactionId)
        {
            for (int i = 0; i < npc->getDialogReplies().size(); i++)
                for (int j = 0; j < npc->getDialogReplies()[i].size(); j++)
                    for (int k = 0; k < m_botData[sender].interactionData.npcDialogs.size(); k++)
                        if (m_botData[sender].interactionData.npcDialogs[k] == npc->getDialogReplies()[i][j])
                            replies[m_botData[sender].interactionData.npcDialogs[k]] = QPoint(i, j);

            foreach (int id, replies.keys())
            {
                if (D2OManagerSingleton::get()->getI18N()->getText((npc->getDialogReplies().at(replies[id].x()).at(replies[id].y()+1))).indexOf(dialog, 0, Qt::CaseInsensitive) >= 0)
                {
                    replyID = id;
                    break;
                }
            }
        }
    }

    if (replyID == INVALID)
    {
        alert(sender) << "Interaction Module - Le bot n'a pas pu interagir avec le PNJ (id:" + QString::number(m_botData[sender].interactionData.interactionId) + ") car le dialogue n'existe pas.";
        m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
        m_botData[sender].interactionData.interactionId = INVALID;
        m_botData[sender].interactionData.npcDialogs.clear();
        return false;
    }

    NpcDialogReplyMessage msg;
    msg.replyId = replyID;

    m_finishedAction << sender;
    QTimer::singleShot(15000, this, SLOT(finishAction()));
    m_botData[sender].interactionData.finishedAction = false;

    sender->send(msg);
    return true;
}

bool InteractionModule::leaveNpcDialog(SocketIO *sender)
{
    m_botData[sender].interactionData.interactionId = INVALID;
    if (m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
    {
        LeaveDialogRequestMessage message;
        sender->send(message);
        return true;
    }

    m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
    m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
    m_botData[sender].interactionData.interactionId = INVALID;
    m_botData[sender].interactionData.finishedAction = true;
    m_botData[sender].interactionData.actionID = INVALID;
    m_botData[sender].interactionData.npcDialogs.clear();
    return false;
}

void InteractionModule::moved(SocketIO *sender)
{
    disconnect(m_mapModule, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(moved(SocketIO*)));
    disconnect(m_mapModule, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(noMovement(SocketIO*)));

    if (m_botData[sender].interactionData.interactionType == CurrentInteraction::NONE
            || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE
            || m_botData[sender].interactionData.interactionId == INVALID)
    {
        alert(sender) << "Interaction Module - Le bot n'a pas pu interagir avec l'élément spécifié (npc, zaap(i), item).";
        m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
        m_botData[sender].interactionData.interactionId = INVALID;
        m_botData[sender].interactionData.finishedAction = true;
        m_botData[sender].interactionData.actionID = INVALID;
        m_botData[sender].interactionData.npcDialogs.clear();
        emit scriptActionDone(sender);
    }

    else if (m_botData[sender].interactionData.interactionType == CurrentInteraction::ZAAP
             || m_botData[sender].interactionData.interactionType == CurrentInteraction::ZAAPI)
    {
        int id = INVALID;
        int skill = INVALID;
        foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
        {
            if (qSharedPointerCast<InteractiveData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INTERACTIVES, e.elementTypeId))->getName() == "Zaap")
            {
                id = e.elementId;
                skill = e.enabledSkills.first().UID;
            }
        }

        if ((skill == INVALID) || (id == INVALID))
        {
            alert(sender) << "Interaction Module - Le bot n'a pas pu interagir avec l'élément spécifié (zaap(i) ou élément interactif).";
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
            return;
        }

        InteractiveUseRequestMessage message;
        message.skillInstanceUid = skill;
        message.elemId = id;

        m_finishedAction << sender;
        QTimer::singleShot(15000, this, SLOT(finishAction()));
        m_botData[sender].interactionData.finishedAction = false;

        sender->send(message);
    }

    else if (m_botData[sender].interactionData.interactionType == CurrentInteraction::ITEM)
    {
        int skill = INVALID;
        foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
            foreach (InteractiveSkillInfos s, e.enabledSkills)
                if (s.ID == m_botData[sender].interactionData.actionID)
                    skill = s.UID;

        if (skill == INVALID)
        {
            alert(sender) << "Interaction Module - Le bot n'a pas pu interagir avec l'élément interactif (id:" << m_botData[sender].interactionData.interactionId << ").";
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
        }

        InteractiveUseRequestMessage message;
        message.skillInstanceUid = skill;
        message.elemId = m_botData[sender].interactionData.interactionId;

        m_finishedAction << sender;
        QTimer::singleShot(15000, this, SLOT(finishAction()));
        m_botData[sender].interactionData.finishedAction = false;

        sender->send(message);
    }
}

void InteractionModule::noMovement(SocketIO *sender)
{
    disconnect(m_mapModule, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(moved(SocketIO*)));
    disconnect(m_mapModule, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(noMovement(SocketIO*)));

    m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
    m_botData[sender].interactionData.interactionId = INVALID;
    m_botData[sender].interactionData.finishedAction = true;
    m_botData[sender].interactionData.actionID = INVALID;
    m_botData[sender].interactionData.npcDialogs.clear();
    emit scriptActionDone(sender);
}

void InteractionModule::finishAction()
{
    if (m_botData[m_finishedAction.first()].interactionData.interactionType == CurrentInteraction::NPC)
    {
        LeaveDialogRequestMessage message;
        m_finishedAction.first()->send(message);

        m_botData[m_finishedAction.first()].interactionData.finishedAction = true;
        m_finishedAction.removeFirst();
        return;
    }

    if (!m_botData[m_finishedAction.first()].interactionData.finishedAction)
        emit scriptActionDone(m_finishedAction.first());

    m_botData[m_finishedAction.first()].interactionData.finishedAction = true;
    m_finishedAction.removeFirst();
}

void InteractionModule::confirmAction()
{
    emit scriptActionDone(m_confirmAction.first());
    m_confirmAction.removeFirst();
}

void InteractionModule::clearBankData(SocketIO *sender)
{
    m_botData[sender].interactionData.bankData.deposit.clear();
    m_botData[sender].interactionData.bankData.take.clear();
}

BankData InteractionModule::getBankData(SocketIO *sender)
{
    return m_botData[sender].interactionData.bankData;
}

void InteractionModule::addDepositBankItem(SocketIO *sender, BankItem item)
{
    m_botData[sender].interactionData.bankData.deposit.append(item);
}

void InteractionModule::addTakeBankItem(SocketIO *sender, BankItem item)
{
    m_botData[sender].interactionData.bankData.take.append(item);
}

void InteractionModule::removeDepositBankItem(SocketIO *sender, BankItem item)
{
    m_botData[sender].interactionData.bankData.deposit.removeOne(item);
}

void InteractionModule::removeTakeBankItem(SocketIO *sender, BankItem item)
{
    m_botData[sender].interactionData.bankData.take.removeOne(item);
}

void InteractionModule::updateTakeBankItem(SocketIO *sender, uint itemId, uint pods)
{
    for (int i = 0; i < m_botData[sender].interactionData.bankData.take.size(); i++)
        if (m_botData[sender].interactionData.bankData.take[i].itemId == itemId)
            m_botData[sender].interactionData.bankData.take[i].pods = pods;
}

void InteractionModule::updateDepositBankItem(SocketIO *sender, uint itemId, uint pods)
{
    for (int i = 0; i < m_botData[sender].interactionData.bankData.deposit.size(); i++)
        if (m_botData[sender].interactionData.bankData.deposit[i].itemId == itemId)
            m_botData[sender].interactionData.bankData.deposit[i].pods = pods;
}

void InteractionModule::setTakeCondition(SocketIO *sender, BankInclusion condition)
{
    m_botData[sender].interactionData.bankData.takeCondition = condition;
}

void InteractionModule::setDepositCondition(SocketIO *sender, BankInclusion condition)
{
    m_botData[sender].interactionData.bankData.depositCondition = condition;
}

void InteractionModule::toggleFeed(SocketIO *sender, bool toggle)
{
    m_botData[sender].interactionData.petData.toggleFeed = toggle;
    if (!toggle)
    {
        for (int i = 0; i < m_botData[sender].interactionData.petData.petInfos.size(); i++)
            m_botData[sender].interactionData.petData.petInfos[i].timer->stop();

        return;
    }

    foreach (PetFeedInfos pet, m_botData[sender].interactionData.petData.petInfos)
    {
        if (pet.foodId != INVALID && pet.waitingTime != INVALID)
        {
            if (pet.timer != NULL)
                pet.timer->stop();

            else if (pet.timer == NULL)
            {
                pet.timer = QSharedPointer<QTimer>(new QTimer(this));
                QObject::connect(pet.timer.data(), SIGNAL(timeout()), this, SLOT(feed()));
            }

            pet.timer->setSingleShot(true);
            pet.timer->setInterval(pet.waitingTime*3600000);
            pet.timer->start();
        }
    }
}

void InteractionModule::setPetFood(SocketIO *sender, uint id, int food)
{
    for (int i = 0; i < m_botData[sender].interactionData.petData.petInfos.size(); i++)
        if (m_botData[sender].interactionData.petData.petInfos[i].GID == id)
            m_botData[sender].interactionData.petData.petInfos[i].foodId = food;
}

void InteractionModule::setFeedTimer(SocketIO *sender, uint id, int timer)
{
    for (int i = 0; i < m_botData[sender].interactionData.petData.petInfos.size(); i++)
        if (m_botData[sender].interactionData.petData.petInfos[i].GID == id)
            m_botData[sender].interactionData.petData.petInfos[i].waitingTime = timer;
}

void InteractionModule::feed()
{
    QTimer *t = static_cast<QTimer*>(QObject::sender());
    foreach (SocketIO *sender, m_botData.keys())
    {
        foreach (PetFeedInfos pet, m_botData[sender].interactionData.petData.petInfos)
        {
            if (pet.timer == t)
            {
                int foodUid = getFoodUID(sender, pet.UID, pet.foodId);
                if (pet.toRemove || (pet.foodId == INVALID) || m_botData[sender].interactionData.petData.toggleFeed || (foodUid == INVALID))
                    return;

                ObjectFeedMessage message;
                message.foodUID = foodUid;
                message.foodQuantity = 1;
                message.objectUID = pet.UID;

                pet.timer->setSingleShot(true);
                pet.timer->setInterval(pet.waitingTime*3600000);
                pet.timer->start();
            }
        }
    }
}

QString InteractionModule::nameFromUid(SocketIO *sender, int uid)
{
    foreach (InventoryObject o, m_botData[sender].playerData.inventoryContent)
        if (o.UID == uid)
            return D2OManagerSingleton::get()->getItem(o.GID)->getName();

    return "";
}

bool InteractionModule::concernedByBankTake(SocketIO *sender, int id)
{
    QList<int> itemsId;
    foreach (BankItem b, m_botData[sender].interactionData.bankData.take)
        itemsId << b.itemId;

    if (m_botData[sender].interactionData.bankData.takeCondition == BankInclusion::NONE_EXCEPT)
        if (itemsId.contains(id))
            return true;
    else if (m_botData[sender].interactionData.bankData.takeCondition == BankInclusion::ALL_EXCEPT)
        if (!itemsId.contains(id))
            return true;

    return false;
}

bool InteractionModule::concernedByBankDeposit(SocketIO *sender, int id)
{
    QList<int> itemsId;
    foreach (BankItem b, m_botData[sender].interactionData.bankData.deposit)
        itemsId << b.itemId;

    if (m_botData[sender].interactionData.bankData.depositCondition == BankInclusion::NONE_EXCEPT)
        if (itemsId.contains(id))
            return true;
    else if (m_botData[sender].interactionData.bankData.depositCondition == BankInclusion::ALL_EXCEPT)
        if (!itemsId.contains(id))
            return true;

    return false;
}

int InteractionModule::getFoodUID(SocketIO *sender, int uid, int food)
{
    int foodUid = INVALID;
    foreach (InventoryObject o, m_botData[sender].playerData.inventoryContent)
        if (o.GID = food)
            foodUid = o.GID;

    if (foodUid == INVALID)
    {
        for (int i = 0; i < m_botData[sender].interactionData.petData.petInfos.size(); i++)
        {
            if (m_botData[sender].interactionData.petData.petInfos[i].UID = uid)
            {
                m_botData[sender].interactionData.petData.petInfos[i].foodId = INVALID;
                m_botData[sender].interactionData.petData.petInfos[i].toRemove = true;
                return INVALID;
            }
        }
    }

    else
        return foodUid;
}
