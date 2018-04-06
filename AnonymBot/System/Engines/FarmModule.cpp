#include "FarmModule.h"

FarmModule::FarmModule(QMap<SocketIO *, BotData> *connectionsData, MapModule *mapModule) :
    AbstractModule(ModuleType::FARM, connectionsData),
    m_mapModule(mapModule)
{
    QObject::connect(m_mapModule, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(activateSkill(SocketIO*)));

    foreach (int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::ITEMS))
    {
        QSharedPointer<ItemData> item = D2OManagerSingleton::get()->getItem(index);

        UsableItem u;
        u.id = item->getId();
        u.usable = item->getUsable();
        m_items[item->getName()] = u;
    }
}

void FarmModule::reset(SocketIO *sender)
{
    m_botData[sender].farmData.moved = false;
    m_botData[sender].farmData.farming = false;
}

bool FarmModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default:
        messageFound = false;
        break;

    case MessageEnum::JOBLEVELUPMESSAGE:
    {
        JobLevelUpMessage message;
        message.deserialize(&reader);

        action(sender) << "Votre métier" << qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, message.jobsDescription->jobId))->getName() << "vient de passer niveau" << message.newLevel;
        m_botData[sender].craftData.jobs[message.jobsDescription->jobId].jobLevel = message.newLevel;
    }
        break;

    case MessageEnum::JOBEXPERIENCEMULTIUPDATEMESSAGE:
    {
        JobExperienceMultiUpdateMessage message;
        message.deserialize(&reader);

        foreach(const JobExperience &e, message.experiencesUpdate)
            m_botData[sender].craftData.jobs[e.jobId] = e;
    }
        break;

    case MessageEnum::JOBEXPERIENCEUPDATEMESSAGE:
    {
        JobExperienceUpdateMessage message;
        message.deserialize(&reader);

        m_botData[sender].craftData.jobs[message.experiencesUpdate.jobId] = message.experiencesUpdate;
    }
        break;

    case MessageEnum::INTERACTIVEELEMENTUPDATEDMESSAGE:
    {
        InteractiveElementUpdatedMessage message;
        message.deserialize(&reader);

        if (message.interactiveElement->enabledSkills.size())
        {
            bool update = true;
            for (int i = 0; i < m_botData[sender].farmData.interactiveElementsList.size(); i++)
                if (m_botData[sender].farmData.interactiveElementsList[i].ie.elementId == message.interactiveElement->elementId)
                    update = false;

            if (update)
            {
                InteractiveElementAction e;
                InteractiveElementInfos info;

                info.elementId = message.interactiveElement->elementId;
                info.elementTypeId = message.interactiveElement->elementTypeId;
                for (int i = 0; i < message.interactiveElement->enabledSkills.size(); i++)
                {
                    InteractiveSkillInfos s;
                    s.ID = message.interactiveElement->enabledSkills[i]->skillId;
                    s.UID = message.interactiveElement->enabledSkills[i]->skillInstanceUid;

                    info.enabledSkills << s;
                }
                for (int i = 0; i < message.interactiveElement->disabledSkills.size(); i++)
                {
                    InteractiveSkillInfos s;
                    s.ID = message.interactiveElement->disabledSkills[i]->skillId;
                    s.UID = message.interactiveElement->disabledSkills[i]->skillInstanceUid;

                    info.disabledSkills << s;
                }

                e.ie = info;
                e.skillInstanceUid = message.interactiveElement->enabledSkills.first()->skillInstanceUid;
                e.position = MapPoint::fromCellId(m_botData[sender].mapData.map.getInteractiveElementCellID(message.interactiveElement->elementId));
            }
        }

        else if (message.interactiveElement->disabledSkills.size())
        {
            for (int i = 0; i < m_botData[sender].farmData.interactiveElementsList.size(); i++)
            {
                if (m_botData[sender].farmData.interactiveElementsList[i].ie.elementId == message.interactiveElement->elementId)
                {
                    m_botData[sender].farmData.interactiveElementsList.removeAt(i);
                    break;
                }
            }
        }
    }
        break;

    case MessageEnum::INTERACTIVEUSEENDEDMESSAGE:
    {   
        if (m_botData[sender].farmData.farming)
        {
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            if (m_botData[sender].farmData.interactiveElementsList.size())
                farmAction(sender);
            else
            {
                m_botData[sender].farmData.farming = false;
                emit scriptActionDone(sender);
            }
        }
    }
        break;

    case MessageEnum::INTERACTIVEUSEERRORMESSAGE:
    {
        InteractiveUseErrorMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].farmData.farming)
        {
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            qDebug() << "Le bot n'a pas pu récolter la ressources d'id" << message.elemId;

            if (m_botData[sender].farmData.interactiveElementsList.size())
                farmAction(sender);
            else
            {
                m_botData[sender].farmData.farming = false;
                emit scriptActionDone(sender);
            }
        }
    }
        break;
    }

    return messageFound;
}

bool FarmModule::processFarm(SocketIO *sender)
{
    m_botData[sender].farmData.interactiveElementsList.clear();
    m_botData[sender].farmData.currentElement.skillInstanceUid = INVALID;
    if (m_botData[sender].farmData.elementsId.isEmpty())
        return false;

    foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
    {
        if (m_botData[sender].farmData.elementsId.contains(e.elementTypeId) && !e.enabledSkills.isEmpty())
        {
            InteractiveElementAction ie;
            ie.ie = e;
            ie.skillInstanceUid = e.enabledSkills.first().UID;
            ie.position = MapPoint::fromCellId(m_botData[sender].mapData.map.getInteractiveElementCellID(e.elementId));

            m_botData[sender].farmData.interactiveElementsList << ie;
        }
    }

    if (m_botData[sender].farmData.farming == true ||
            m_botData[sender].farmData.interactiveElementsList.isEmpty() ||
            m_botData[sender].generalData.botState != BotState::INACTIVE_STATE)
        return false;

    m_botData[sender].farmData.farming = true;
    farmAction(sender);
    return true;
}

void FarmModule::farmAction(SocketIO *sender)
{
    if (!m_botData[sender].farmData.farming |
            m_botData[sender].generalData.botState != BotState::INACTIVE_STATE)
        return;

    MapPoint bot = MapPoint::fromCellId(m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId);
    m_botData[sender].farmData.currentElement = m_botData[sender].farmData.interactiveElementsList.first();
    m_botData[sender].farmData.interactiveElementsList.removeFirst();
    QList<CellData> map = m_botData[sender].mapData.map.getCellData();
    QList<uint> cells;

    for (int i = 0; i < 8; i++)
    {
        MapPoint cell = m_botData[sender].farmData.currentElement.position.getNearestCellInDirection(i);
        if (cell.getCellId() <= map.size())
        {
            CellData cellData = map[cell.getCellId()];
            if (!CellInfo::pointMov(map, cell.getX(), cell.getY(), false) || cellData.isFarmCell())
                cells << cell.getCellId();
        }
    }

    MapPoint mp = m_botData[sender].farmData.currentElement.position.getNearestFreeCellInDirection(m_botData[sender].farmData.currentElement.position.advancedOrientationTo(bot),
                                                                                                   m_botData[sender].mapData.map.getCellData(),
                                                                                                   cells,
                                                                                                   true,
                                                                                                   true,
                                                                                                   false);
    if (cells.indexOf(mp.getCellId()) == -1)
        mp = m_botData[sender].farmData.currentElement.position;

    if (mp.getCellId() == bot.getCellId())
        activateSkill(sender);
    else
        m_botData[sender].farmData.moved = m_mapModule->changeCell(sender, mp.getCellId());
}

void FarmModule::activateSkill(SocketIO *sender)
{
    if (m_botData[sender].farmData.currentElement.skillInstanceUid == INVALID ||
            m_botData[sender].generalData.botState != BotState::INACTIVE_STATE ||
            !m_botData[sender].farmData.farming)
        return;

    InteractiveUseRequestMessage r;
    r.elemId = m_botData[sender].farmData.currentElement.ie.elementId;
    r.skillInstanceUid = m_botData[sender].farmData.currentElement.skillInstanceUid;

    sender->send(r);
    m_botData[sender].generalData.botState = BotState::FARMING_STATE;
    m_botData[sender].farmData.currentElement.skillInstanceUid = INVALID;
}

bool FarmModule::canFarmResource(InteractiveElementInfos element)
{
    if (element.enabledSkills.isEmpty())
        return false;

    return true;
}

bool FarmModule::editResourcesList(SocketIO *sender, uint id, bool add)
{
    if (add)
        m_botData[sender].farmData.elementsId << id;
    else
        m_botData[sender].farmData.elementsId.removeOne(id);

    if (m_botData[sender].farmData.elementsId.isEmpty())
        return true;

    return false;
}

bool FarmModule::resourcesListIsEmpty(SocketIO *sender)
{
    if (m_botData[sender].farmData.elementsId.isEmpty())
        return true;

    return false;
}

void FarmModule::clearAutoDeleteList(SocketIO *sender)
{
    m_botData[sender].farmData.resourcesToDelete.clear();
}

void FarmModule::removeResourceToDelete(SocketIO *sender, QString name)
{
    m_botData[sender].farmData.resourcesToDelete.removeOne(getItemId(name));
}

void FarmModule::addResourceToDelete(SocketIO *sender, QString name)
{
    m_botData[sender].farmData.resourcesToDelete << getItemId(name);
}

uint FarmModule::getItemId(QString name)
{
    return m_items[name].id;
}

QString FarmModule::getJobName(uint jobId)
{
    foreach (const int &id, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::JOBS))
        if (jobId == qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, id))->getId())
            return qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, id))->getName();

    return "";
}

bool FarmModule::isItemUsable(QString name)
{
    return m_items[name].usable;
}
