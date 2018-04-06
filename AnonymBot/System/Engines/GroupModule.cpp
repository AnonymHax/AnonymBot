#include "GroupModule.h"

GroupModule::GroupModule(QMap<SocketIO*, BotData> *connectionsData, MapModule *mapModule):
    AbstractModule(ModuleType::GROUP, connectionsData),
    m_mapModule(mapModule)
{
    connect(m_mapModule, SIGNAL(mapContentUpdated(SocketIO*)), this, SLOT(followUpUpdate(SocketIO*)));
    connect(m_mapModule, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(followUpFailure(SocketIO*)));
}

void GroupModule::reset(SocketIO *sender)
{
    m_botData[sender].groupData.isInGroup = false;
    m_botData[sender].groupData.masterId = INVALID;
    m_botData[sender].groupData.partyId = INVALID;
    m_botData[sender].groupData.isFollowing = false;
    m_botData[sender].groupData.hasRequestedFollowUp = false;
    m_botData[sender].groupData.masterPosition.x = INVALID;
    m_botData[sender].groupData.masterPosition.y = INVALID;
    m_botData[sender].groupData.members.clear();
}

void GroupModule::setFollowUpEnabled(SocketIO *sender, bool followUp)
{
    m_botData[sender].groupData.followUp = followUp;

    if(!m_botData[sender].groupData.hasRequestedFollowUp && followUp && m_botData[sender].groupData.isInGroup)
    {
        PartyFollowMemberRequestMessage answer;
        answer.partyId = m_botData[sender].groupData.partyId;
        answer.playerId = m_botData[sender].groupData.masterId;
        sender->send(answer);
    }

    if (!followUp && m_botData[sender].groupData.isFollowing)
    {
        m_mapModule->stopMoving(sender);
        m_botData[sender].groupData.isFollowing = false;
    }

    if(followUp && m_botData[sender].groupData.isInGroup && m_botData[sender].generalData.botState == INACTIVE_STATE && m_botData[sender].groupData.hasRequestedFollowUp)
    {
        QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
        QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

        int mapId = PathfindingMap::coordsToMapId(m_botData[sender].groupData.masterPosition.x,  m_botData[sender].groupData.masterPosition.y, area->getSuperAreaId());

        m_mapModule->stopMoving(sender);
        m_mapModule->changeMap(sender, mapId);
        m_botData[sender].groupData.isFollowing = true;
    }
}

void GroupModule::setMaster(SocketIO *sender, const QString &master)
{
    m_botData[sender].groupData.master = master;
    if(!master.isEmpty() && m_botData[sender].groupData.isInGroup)
    {
        PartyLeaveRequestMessage answer;
        answer.partyId = m_botData[sender].groupData.partyId;
        sender->send(answer);
    }

    updateTeams();
}

SocketIO* GroupModule::getMaster(SocketIO *sender)
{
    QMapIterator<SocketIO*, BotData>i(m_botData);

    while(i.hasNext())
    {
        i.next();
        if(m_botData[sender].connectionData.connectionInfos.character != i.value().connectionData.connectionInfos.character &&
                m_botData[sender].connectionData.connectionInfos.serverId == i.value().connectionData.connectionInfos.serverId &&
                m_botData[sender].groupData.master == i.value().connectionData.connectionInfos.character)
            return i.key();
    }

    return NULL;
}

QList<SocketIO*> GroupModule::getSlaves(SocketIO *sender)
{
    QList<SocketIO*> slaves;
    QString master = m_botData[sender].connectionData.connectionInfos.character;

    foreach(SocketIO *slave, m_botData.keys())
    {
        if(m_botData[slave].connectionData.connectionState == ConnectionState::CONNECTED &&
                m_botData[sender].connectionData.connectionInfos.serverId == m_botData[slave].connectionData.connectionInfos.serverId &&
                m_botData[slave].groupData.master == master &&
                m_botData[slave].groupData.master != m_botData[slave].connectionData.connectionInfos.character)
            slaves<<slave;
    }

    return slaves;
}

bool GroupModule::isGroupOnMapAndInactive(SocketIO *master)
{
    QList<SocketIO*> slaves = getSlaves(master);


    if(m_botData[master].generalData.botState == INACTIVE_STATE)
    {
        foreach(SocketIO *slave, slaves)
        {
            if(m_botData[master].mapData.map.getMapId() != m_botData[slave].mapData.map.getMapId()
                    || m_botData[slave].generalData.botState != INACTIVE_STATE)
                return false;
        }
    }

    return true;
}

void GroupModule::updateTeams()
{
    QMapIterator<SocketIO*, BotData>i(m_botData);

    while(i.hasNext())
    {
        i.next();

        QList<SocketIO*> slaves = getSlaves(i.key());

        foreach(SocketIO *slave, slaves)
        {
            if(!i.value().groupData.members.values().contains(m_botData[slave].connectionData.connectionInfos.character))
            {
                PartyInvitationRequestMessage answer;
                answer.name = m_botData[slave].connectionData.connectionInfos.character;
                i.key()->send(answer);
            }
        }
    }    
    StartupActionsListMessage a;
}

bool GroupModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::CHARACTERSELECTEDFORCEMESSAGE:
    case MessageEnum::CHARACTERLOADINGCOMPLETEMESSAGE:
        updateTeams();
        break;

    case MessageEnum::PARTYINVITATIONMESSAGE:
    {
        PartyInvitationMessage message;
        message.deserialize(&reader);

        if((PartyTypeEnum)message.partyType == PartyTypeEnum::PARTY_TYPE_CLASSICAL &&
                message.fromName == m_botData[sender].groupData.master)
        {
            m_botData[sender].groupData.masterId = message.fromId;
            m_botData[sender].groupData.partyId = message.partyId;
            m_botData[sender].groupData.isInGroup = true;

            PartyAcceptInvitationMessage answer;
            answer.partyId = message.partyId;
            sender->send(answer);

            action(sender)<<"On accepte l'invitation de groupe de la part de"<<message.fromName;
        }

        else
        {
            PartyRefuseInvitationMessage answer;
            answer.partyId = message.partyId;
            sender->send(answer);
            action(sender)<<"Refus de l'invitation de groupe de la part de"<<message.fromName;
        }
    }
        break;

    case MessageEnum::PARTYJOINMESSAGE:
    {
        PartyJoinMessage message;
        message.deserialize(&reader);

        if((PartyTypeEnum)message.partyType == PartyTypeEnum::PARTY_TYPE_CLASSICAL)
        {
            QString masterName;

            m_botData[sender].groupData.members.clear();
            foreach(QSharedPointer<PartyMemberInformations> member, message.members)
            {
                if(member->id == message.partyLeaderId)
                    masterName = member->name;

                m_botData[sender].groupData.members[member->id] = member->name;
            }

            action(sender)<<"Le bot appartient désormais au groupe qui a pour chef"<<masterName;

            m_botData[sender].groupData.masterId = message.partyLeaderId;
            m_botData[sender].groupData.partyId = message.partyId;
            m_botData[sender].groupData.isInGroup = true;

            if(!m_botData[sender].groupData.master.isEmpty() && masterName != m_botData[sender].groupData.master)
            {
                PartyLeaveRequestMessage answer;
                answer.partyId = message.partyId;
                sender->send(answer);
            }

            else if(m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY &&
                    m_botData[sender].mapData.map.isInit())
            {
                PartyFollowMemberRequestMessage answer;
                answer.partyId = message.partyId;
                answer.playerId = message.partyLeaderId;
                sender->send(answer);
            }
        }
    }
        break;

    case MessageEnum::PARTYUPDATEMESSAGE:
    {
        PartyUpdateMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].groupData.partyId == message.partyId &&
                m_botData[sender].groupData.masterId == message.memberInformations->id)
        {
            if(message.memberInformations->mapId)
            {
                Map map = D2PManagerSingleton::get()->getMap(message.memberInformations->mapId);

                m_botData[sender].groupData.masterPosition.x = map.getPosition().getX();
                m_botData[sender].groupData.masterPosition.y = map.getPosition().getY();
            }

            else
            {
                m_botData[sender].groupData.masterPosition.x = m_botData[sender].mapData.map.getPosition().getX();
                m_botData[sender].groupData.masterPosition.y = m_botData[sender].mapData.map.getPosition().getY();

                if(m_botData[sender].groupData.hasRequestedFollowUp)
                {
                    PartyStopFollowRequestMessage answer;
                    answer.partyId = m_botData[sender].groupData.partyId;
                    sender->send(answer);
                }
            }
        }
    }
        break;

    case MessageEnum::PARTYFOLLOWSTATUSUPDATEMESSAGE:
    {
        PartyFollowStatusUpdateMessage message;
        message.deserialize(&reader);

        if(message.partyId == m_botData[sender].groupData.partyId &&
                message.followedId == 0 && m_botData[sender].groupData.hasRequestedFollowUp)
        {
            m_botData[sender].groupData.hasRequestedFollowUp = false;
            PartyFollowMemberRequestMessage answer;
            answer.partyId = message.partyId;
            answer.playerId = m_botData[sender].groupData.masterId;
            sender->send(answer);
        }

        else if(message.partyId == m_botData[sender].groupData.partyId &&
                message.followedId == m_botData[sender].groupData.masterId)
            m_botData[sender].groupData.hasRequestedFollowUp = true;

        else if(message.partyId == m_botData[sender].groupData.partyId && message.followedId != 0)
        {
            m_botData[sender].groupData.masterPosition.x = m_botData[sender].mapData.map.getPosition().getX();
            m_botData[sender].groupData.masterPosition.y = m_botData[sender].mapData.map.getPosition().getY();

            PartyStopFollowRequestMessage answer;
            answer.partyId = m_botData[sender].groupData.partyId;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::PARTYNEWMEMBERMESSAGE:
    {
        PartyNewMemberMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].groupData.partyId == message.partyId)
            m_botData[sender].groupData.members[message.memberInformations->id] = message.memberInformations->name;
    }
        break;

    case MessageEnum::PARTYMEMBEREJECTEDMESSAGE:
    case MessageEnum::PARTYMEMBERREMOVEMESSAGE:
    {
        PartyMemberRemoveMessage message;
        message.deserialize(&reader);

        m_botData[sender].groupData.members.remove(message.leavingPlayerId);

        if(message.leavingPlayerId == m_botData[sender].groupData.masterId &&
                message.partyId == m_botData[sender].groupData.partyId)
        {
            m_botData[sender].groupData.members.clear();
            PartyLeaveRequestMessage answer;
            answer.partyId = m_botData[sender].groupData.partyId;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::PARTYDELETEDMESSAGE:
    {
        PartyDeletedMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].groupData.partyId == message.partyId)
        {
            action(sender)<<"Le groupe a été détruit";

            m_botData[sender].groupData.members.clear();
            m_botData[sender].groupData.partyId = 0;
            m_botData[sender].groupData.masterId = 0;
            m_botData[sender].groupData.isInGroup = false;

            if(m_botData[sender].groupData.isFollowing &&
                    (m_botData[sender].generalData.botState == MOVING_STATE ||
                     m_botData[sender].generalData.botState == CALCULATING_STATE))
                m_mapModule->stopMoving(sender);
        }
    }
        break;

    case MessageEnum::PARTYKICKEDBYMESSAGE:
    {
        PartyKickedByMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].groupData.partyId == message.partyId)
        {
            action(sender)<<"Le bot a été exclu du groupe";

            m_botData[sender].groupData.members.clear();
            m_botData[sender].groupData.partyId = 0;
            m_botData[sender].groupData.masterId = 0;
            m_botData[sender].groupData.isInGroup = false;


            if(m_botData[sender].groupData.isFollowing &&
                    (m_botData[sender].generalData.botState == MOVING_STATE ||
                     m_botData[sender].generalData.botState == CALCULATING_STATE))
                m_mapModule->stopMoving(sender);
        }
    }
        break;

    case MessageEnum::PARTYLEAVEMESSAGE:
    {
        PartyLeaveMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].groupData.partyId == message.partyId)
        {
            action(sender)<<"Le bot a quitté le groupe car le chef configuré n'est plus/pas présent";

            m_botData[sender].groupData.members.clear();
            m_botData[sender].groupData.partyId = INVALID;
            m_botData[sender].groupData.masterId = INVALID;
            m_botData[sender].groupData.isInGroup = false;
            m_botData[sender].groupData.masterPosition.x = INVALID;
            m_botData[sender].groupData.masterPosition.y = INVALID;

            if(m_botData[sender].groupData.isFollowing &&
                    (m_botData[sender].generalData.botState == MOVING_STATE ||
                     m_botData[sender].generalData.botState == CALCULATING_STATE))
                m_mapModule->stopMoving(sender);
        }
    }

    case MessageEnum::COMPASSUPDATEPARTYMEMBERMESSAGE:
    {
        CompassUpdatePartyMemberMessage message;
        message.deserialize(&reader);

        if(message.memberId == m_botData[sender].groupData.masterId)
        {
            m_botData[sender].groupData.masterPosition.x = message.coords->worldX;
            m_botData[sender].groupData.masterPosition.y = message.coords->worldY;

            if(m_botData[sender].groupData.followUp)
            {
                QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
                QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

                int mapId = PathfindingMap::coordsToMapId(message.coords->worldX, message.coords->worldY, area->getSuperAreaId());

                m_mapModule->stopMoving(sender);
                m_mapModule->changeMap(sender, mapId);
                m_botData[sender].groupData.isFollowing = true;
            }
        }
    }
        break;

    case MessageEnum::PARTYUPDATELIGHTMESSAGE:
        break;
    }

    return messageFound;
}

void GroupModule::followUpUpdate(SocketIO *sender)
{
    if((m_botData[sender].mapData.map.getPosition().getX() == m_botData[sender].groupData.masterPosition.x &&
        m_botData[sender].mapData.map.getPosition().getY() == m_botData[sender].groupData.masterPosition.y) ||
            !m_botData[sender].groupData.isInGroup)
        m_botData[sender].groupData.isFollowing = false;


    else if(m_botData[sender].groupData.isInGroup &&
            (m_botData[sender].groupData.masterPosition.x != m_botData[sender].mapData.map.getPosition().getX() ||
             m_botData[sender].groupData.masterPosition.y != m_botData[sender].mapData.map.getPosition().getY()) &&
            m_botData[sender].generalData.botState == INACTIVE_STATE &&
            m_botData[sender].groupData.followUp &&
            !m_botData[sender].groupData.isFollowing &&
            m_botData[sender].groupData.hasRequestedFollowUp &&
            m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY)
    {
        QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
        QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

        int mapId = PathfindingMap::coordsToMapId(m_botData[sender].groupData.masterPosition.x, m_botData[sender].groupData.masterPosition.y, area->getSuperAreaId());

        m_mapModule->stopMoving(sender);
        m_mapModule->changeMap(sender, mapId);
        m_botData[sender].groupData.isFollowing = true;
    }

    else if(m_botData[sender].groupData.isInGroup &&
            m_botData[sender].generalData.botState == INACTIVE_STATE &&
            m_botData[sender].groupData.followUp &&
            !m_botData[sender].groupData.isFollowing &&
            !m_botData[sender].groupData.hasRequestedFollowUp &&
            m_botData[sender].mapData.map.isInit() &&
            m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY)
    {
        PartyFollowMemberRequestMessage answer;
        answer.partyId = m_botData[sender].groupData.partyId;
        answer.playerId = m_botData[sender].groupData.masterId;
        sender->send(answer);
    }
}

void GroupModule::followUpFailure(SocketIO *sender)
{
    m_botData[sender].groupData.isFollowing = false;
}
