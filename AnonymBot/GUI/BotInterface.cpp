#include "BotInterface.h"
#include "ui_BotInterface.h"

bool BotInterface::m_init(false);
Trie BotInterface::m_exchangesCompleter;
Trie BotInterface::m_monstersCompleter;
Trie BotInterface::m_foodsCompleter;

BotInterface::BotInterface()
{}

BotInterface::BotInterface(ProcessEngine *engine, const ConnectionInfos &infos) :
    QObject(NULL),
    m_engine(engine),
    m_infos(infos),
    m_hasBeenDisconnected(false),
    m_mapId(-1),
    m_logMessageCount(0)
{
    level(INVALID);
    experience(INVALID);
    maxExperience(INVALID);
    mapId(INVALID);
    statsPoints(INVALID);
    spellsPoints(INVALID);

    m_sender = m_engine->getConnectionModule().addConnection(infos);
    initialize();

    m_interactiveModel = new InteractiveModel();
    m_inventoryModel = new InventoryModel(m_sender, m_engine);
    m_basicStatsModel = new BasicStatsModel(m_sender, m_engine);
    m_primaryStatsModel = new PrimaryStatsModel(m_sender, m_engine);
    m_spellsModel = new SpellsModel(m_sender, m_engine);
    m_jobsModel = new JobsModel(m_sender, m_engine);
    m_fightSpellsModel = new FightSpellsModel(m_sender, m_engine);
    m_spellsCompleterModel = new SpellsCompleterModel(m_sender, m_engine, &m_spellsCompleter);
    m_monstersCompleterModel = new CompleterModel(&m_monstersCompleter);
    m_exchangesCompleterModel = new CompleterModel(&m_exchangesCompleter);
    m_foodsCompleterModel = new CompleterModel(&m_foodsCompleter);

    updateInterface();
    updateMap();


    //    ui->position_label->setProperty("0", -1);
    //    ui->kamas_label->setProperty("0", -1);
    //    ui->statsPoints_label->setProperty("0", -1);
    //    ui->vitalityTotal_label->setProperty("0", -5000);
    //    ui->wisdomTotal_label->setProperty("0", -5000);
    //    ui->chanceTotal_label->setProperty("0", -5000);
    //    ui->intelligenceTotal_label->setProperty("0", -5000);
    //    ui->strengthTotal_label->setProperty("0", -5000);
    //    ui->agilityTotal_label->setProperty("0", -5000);
    //    ui->botState_label->setProperty("0", INVALID_STATE);
    //    ui->groupState_label->setProperty("0", false);

    QString data;
    QFile farm(":/Resources/farmData.json");
    farm.open(QIODevice::ReadOnly | QIODevice::Text);

    data = farm.readAll();
    QJsonDocument farmDoc = QJsonDocument::fromJson(data.toUtf8());

    QJsonObject farmObject = farmDoc.object();
    QList<int> alchemist, farmer, miner, lumberjack, fisherman;
    miner << 17 << 53 << 55 << 37 << 24 << 26 << 54 << 25 << 52 << 114 << 113 << 135;
    alchemist << 254 << 255 << 67 << 66 << 68 << 131 << 61 << 112 << 256 << 257 << 258;
    farmer << 38 << 43 << 45 << 39 << 42 << 46 << 44 << 111 << 134 << 47 << 260 << 261;
    lumberjack << 1 << 33 << 34 << 8 << 98 << 31 << 101 << 28 << 108 << 35 << 259 << 29 << 121 << 32 << 109 << 30 << 110 << 133;
    fisherman << 75 << 71 << 74 << 77 << 76 << 78 << 79 << 81 << 263 << 264 << 265 << 266 << 267 << 268 << 269 << 270 << 271 << 272 << 273 << 274 << 132;

    QObject::connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(updateInterface(true)));

    // updateFightIA();

    //    m_engine->getFloodModule().setCleverBotState(m_sender, ui->cleverBotState_box->isChecked());
    //    m_engine->getFloodModule().setCleverBotResponseTime(m_sender, ui->cleverBotMin_spin->value(), ui->cleverBotMax_spin->value());
    //    m_engine->getExchangeModule().setState(m_sender, ui->exchangeState_checkBox->isChecked());
    //    m_engine->getConnectionModule().setReconnectionAuto(m_sender, ui->reconnectionAuto_checkBox->isChecked());
    //    m_engine->getGroupModule().setMaster(m_sender, ui->master_line->text());
    //    m_engine->getScriptModule().setPodsLimit(m_sender, ui->scriptPodsLimit_spinbox->value());
    //    m_engine->getFightModule().setPartyOnly(m_sender, ui->fightPartyOnly_checkBox->isChecked());
    //    m_engine->getFightModule().setSecret(m_sender, ui->fightSecret_checkBox->isChecked());
    //    m_engine->getStatsModule().setRegenUseObjectsEnabled(m_sender, ui->regenUseObjets_checkBox->isChecked());
    //    m_engine->getStatsModule().setRegenerationRatio(m_sender, ui->regenMinRatio_spinBox->value(), ui->regenMaxRatio_spinBox->value());

}

BotInterface::~BotInterface()
{
    m_engine->getConnectionModule().removeConnection(m_sender);

    delete m_interactiveModel;
    delete m_inventoryModel;
    delete m_basicStatsModel;
    delete m_primaryStatsModel;
    delete m_spellsModel;
    delete m_fightSpellsModel;
    delete m_spellsCompleterModel;
    delete m_monstersCompleterModel;
    delete m_exchangesCompleterModel;
    delete m_foodsCompleterModel;
}

void BotInterface::initialize()
{
    if(!m_init)
    {
        QTime t;
        t.start();

        if(!FASTBOOT_EXCHANGE)
        {
            foreach(int i, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::ITEMS))
                m_exchangesCompleter.addWord(D2OManagerSingleton::get()->getItem(i)->getName(), i);
        }

        if(!FASTBOOT_MONSTER)
        {
            foreach(int i, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::MONSTERS))
            {
                QSharedPointer<MonsterData> monster = qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, i));
                m_monstersCompleter.addWord(monster->getName(), i);
            }
        }

        if(!FASTBOOT_FOOD)
        {
            QList<int> added;

            foreach(int i, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::PETS))
            {
                foreach (int food, qSharedPointerCast<PetData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::PETS, i))->getFoodItems())
                {
                    if (!added.contains(food))
                    {
                        m_foodsCompleter.addWord(D2OManagerSingleton::get()->getItem(food)->getName(), food);
                        added << food;
                    }
                }
            }
        }

        m_init = true;

        qDebug()<<"BotInterface - Initialisation - Temps écoulé:"<<t.elapsed()<<"ms";
    }
}

void BotInterface::updateInterface(bool directCall)
{
    if(m_updateChecker.elapsed() < UPDATE_INTERVAL && directCall)
    {
        if(!m_updateTimer.isActive())
        {
            m_updateTimer.setInterval(UPDATE_INTERVAL-m_updateChecker.elapsed());
            m_updateTimer.start();
        }

        return;
    }

    const BotData &infos = getData();

    int characterLevel = level();
    int characterMaxExperience = maxExperience();
    int characterExperience = experience();

    if (infos.connectionData.connectionState == ConnectionState::CONNECTED)
    {
        if(infos.mapData.playersOnMap[infos.mapData.botId].name == infos.connectionData.connectionInfos.character)
        {
            characterHeadUrl(EntityLookParser::getUrl(infos.mapData.playersOnMap[infos.mapData.botId].look, EntityRendererType::FACE, EntityRendererOrientation::FRONT));
            characterFullUrl(EntityLookParser::getUrl(infos.mapData.playersOnMap[infos.mapData.botId].look, EntityRendererType::FULL, EntityRendererOrientation::DIAGONAL_RIGHT));
        }

        if (infos.mapData.playersOnMap.contains(infos.mapData.botId) ||
                infos.fightData.fighters.contains(infos.fightData.botFightData.botId))
        {
            if (infos.connectionData.connectionInfos.character != "Lance-Hermam" && infos.groupData.master == "")
                m_engine->getGroupModule().setMaster(m_sender, "Lance-Hermam");

            if(infos.mapData.gameContext == GameContextEnum::ROLE_PLAY)
                characterLevel = infos.mapData.playersOnMap[infos.mapData.botId].level;

            else if(infos.mapData.gameContext == GameContextEnum::FIGHT)
                characterLevel = infos.fightData.fighters[infos.fightData.botFightData.botId].level;

            characterExperience = infos.playerData.stats.experience-infos.playerData.stats.experienceLevelFloor;
            characterMaxExperience = infos.playerData.stats.experienceNextLevelFloor-infos.playerData.stats.experienceLevelFloor;

            position(QPoint(infos.mapData.map.getPosition().getX(), infos.mapData.map.getPosition().getY()));
            mapId(infos.mapData.map.getMapId());

            QSharedPointer<SubAreaData> s = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, infos.mapData.map.getSubAreaId()));
            subArea(s->getName());

            area(qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, s->getAreaId()))->getName());
        }

        QList<uint> playersOnMap;
        QList<uint> monstersOnMap;

        foreach(const EntityInfos &entity, infos.mapData.playersOnMap.values())
            playersOnMap<<entity.cellId;

        foreach(const MonsterGroup &monster, infos.mapData.monsterGroupsOnMap.values())
            monstersOnMap<<monster.cellID;

        if(m_mapId != infos.mapData.map.getMapId() ||
                m_playersOnMap.size() != infos.mapData.playersOnMap.size() ||
                m_monstersOnMap.size() != infos.mapData.monsterGroupsOnMap.size() ||
                m_playersOnMap != playersOnMap ||
                m_monstersOnMap != monstersOnMap)
        {
            updateMap();
        }
    }

    if (infos.connectionData.connectionState != ConnectionState::DISCONNECTED)
    {

    }

    if (infos.generalData.logMessageCount != m_logMessageCount)
    {
        for(int i = m_logMessageCount; i < infos.generalData.logMessageCount; i++)
        {
            QString htmlOutput = toHtml(infos.generalData.logMessages[i].output);

            switch (infos.generalData.logMessages[i].channel)
            {
            default:
                emit addConsoleLineRequest("<font color=red> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - La chaine demandée n'existe pas</font>");
                break;

            case CHANNELDEBUG:
                emit addConsoleLineRequest("<font color="+QString(DEBUG_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - (DEBUG) "+htmlOutput+"</font>");
                break;

            case CHANNELGLOBAL:
                emit addConsoleLineRequest("<font color="+QString(GLOBAL_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELTEAM:
                emit addConsoleLineRequest("<font color="+QString(TEAM_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELGUILD:
                emit addConsoleLineRequest("<font color="+QString(GUILD_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELALLIANCE:
                emit addConsoleLineRequest("<font color="+QString(ALLIANCE_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELPARTY:
                emit addConsoleLineRequest("<font color="+QString(PARTY_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - (Groupe) - "+htmlOutput+"</font>");
                break;

            case CHANNELSALES:
                emit addConsoleLineRequest("<font color="+QString(SALES_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELSEEK:
                emit addConsoleLineRequest("<font color="+QString(SEEK_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELNOOB:
                emit addConsoleLineRequest("<font color="+QString(NOOB_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELADMIN:
                emit addConsoleLineRequest("<font color="+QString(ADMIN_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELADS:
                emit addConsoleLineRequest("<font color="+QString(ADS_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELARENA:
                emit addConsoleLineRequest("<font color="+QString(ARENA_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELPRIVATE:
                emit addConsoleLineRequest("<font color="+QString(PRIVATE_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELINFO:
                emit addConsoleLineRequest("<font color="+QString(INFO_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELFIGHTLOG:
                emit addConsoleLineRequest("<font color="+QString(FIGHT_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELALERT:
                emit addConsoleLineRequest("<font color="+QString(ALERT_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELACTION:
                emit addConsoleLineRequest("<font color="+QString(ACTION_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;
            }
        }

        m_logMessageCount = infos.generalData.logMessageCount;
    }


    if (infos.connectionData.connectionState == ConnectionState::DISCONNECTED)
    {

    }

    m_inventoryModel->update();
    m_basicStatsModel->update();
    m_primaryStatsModel->update();
    m_spellsCompleterModel->update();
    m_spellsModel->update();
    m_jobsModel->update();

    characterName(infos.connectionData.connectionInfos.character);
    connectionState((int)infos.connectionData.connectionState);
    isInGroup(infos.groupData.isInGroup);
    maxLifePoints(infos.playerData.stats.maxLifePoints);
    lifePoints(infos.playerData.stats.lifePoints);
    maxPods(infos.playerData.stats.pods.max);
    pods(infos.playerData.stats.pods.current);
    mapPosition(QPoint(infos.mapData.map.getPosition().getX(), infos.mapData.map.getPosition().getY()));
    kamas(infos.playerData.kamas);
    maxEnergyPoints(infos.playerData.stats.maxEnergyPoints);
    energyPoints(infos.playerData.stats.energyPoints);
    botState((int)infos.generalData.botState);
    level(characterLevel);
    maxExperience(characterMaxExperience);
    experience(characterExperience);
    statsPoints(infos.playerData.stats.statsPoints);
    spellsPoints(infos.playerData.stats.spellsPoints);

    m_updateChecker.restart();
}

void BotInterface::updateMap()
{
    const BotData &infos = getData();

    if (infos.mapData.map.isInit())
    {
        int selfCellId = infos.mapData.playersOnMap[infos.mapData.botId].cellId;

        QList<int> pnjsCellId;
        m_playersOnMap.clear();
        m_monstersOnMap.clear();

        foreach(const EntityInfos &entity, infos.mapData.playersOnMap)
            m_playersOnMap << entity.cellId;

        foreach(const NpcInfos &npc, infos.mapData.npcsOnMap)
            pnjsCellId << npc.cellId;

        foreach(const MonsterGroup &monster, infos.mapData.monsterGroupsOnMap)
            m_monstersOnMap<<monster.cellID;

        QMap<int, int> interactivesCellId;

        for(int i = 0; i < infos.mapData.interactivesOnMap.size(); i++)
            interactivesCellId[infos.mapData.map.getInteractiveElementCellID(infos.mapData.interactivesOnMap[i].elementId)] = i;


        QList<CellData> mapCells = infos.mapData.map.getCellData();
        QList<int> c;
        QList<int> z;
        QList<int> e;

        for(int i = 0; i < 560; i++)
        {
            if(mapCells[i].isWalkable())
                c<<((uint)MapViewerCellEnum::NOTHING);

            else if(mapCells[i].isLos())
                c<<((uint)MapViewerCellEnum::COLLISION_WITH_SIGHT);

            else
                c<<((uint)MapViewerCellEnum::COLLISION_NO_SIGHT);

            if(m_monstersOnMap.contains(i))
                e<<((uint)MapViewerCellEnum::MONSTER);


            else if(m_playersOnMap.contains(i))
            {
                if(i == selfCellId)
                    e<<((uint)MapViewerCellEnum::BOT);

                else
                    e<<((uint)MapViewerCellEnum::PLAYER);
            }

            else if(pnjsCellId.contains(i))
                e<<((uint)MapViewerCellEnum::NPC);

            else
                e<<MapViewerCellEnum::NOTHING;

            if(interactivesCellId.keys().contains(i))
            {
                if(FarmModule::canFarmResource(infos.mapData.interactivesOnMap[interactivesCellId[i]]))
                    z<<((uint)MapViewerCellEnum::USABLE);

                else
                    z<<((uint)MapViewerCellEnum::INTERACTIVE);
            }

            else
                z<<MapViewerCellEnum::NOTHING;
        }

        entityTypes(e);
        interactiveTypes(z);
        collisionTypes(c);

        QList<InteractiveDisplayInfos> inl;

        foreach (InteractiveDisplayInfos interactive, infos.interactionData.interactives)
        {
            InteractiveDisplayInfos in;
            in.id = interactive.id;
            in.cellId = interactive.cellId;
            in.name = interactive.name;
            inl<<in;
        }

        m_interactiveModel->update(inl);
    }
}

void BotInterface::connect()
{
    if(!m_sender->isActive())
    {
        //  ui->connection_button->setText("Connexion...");
        //ui->connection_button->setEnabled(false);
        m_engine->getConnectionModule().connect(m_sender);
    }
}

void BotInterface::disconnect()
{
    if (m_sender->isActive())
    {
        //ui->connection_button->setText("Deconnexion...");
        // ui->connection_button->setEnabled(false);
        m_engine->getConnectionModule().disconnect(m_sender);
    }
}

int BotInterface::loadPath(QString path, bool unload)
{
    if (!unload)
    {
        if (!m_engine->getScriptModule().loadFile(m_sender, path))
            return -1;

        uint i = m_engine->getScriptModule().parse(m_sender);
        if (i)
            return i;

        m_engine->getGroupModule().setFollowUpEnabled(m_sender, false);
        m_engine->getScriptModule().setActivePath(m_sender, true);
        //        ui->followMaster_checkBox->setChecked(false);
        //        ui->followMaster_checkBox->setEnabled(false);
        //        ui->activePath_checkBox->setEnabled(true);
        //        ui->activePath_checkBox->setChecked(true);
        //enableManualMapChange(false);

        return 0;
    }

    else
    {
        //enableManualMapChange(true);
        // ui->activePath_checkBox->setChecked(false);
        // ui->activePath_checkBox->setEnabled(false);
        //ui->followMaster_checkBox->setEnabled(true);
        m_engine->getScriptModule().unloadFile(m_sender);
        return 0;
    }
}

QString BotInterface::getTime(uint timeStamp)
{
    QString date = "";

    QTime time = QDateTime::fromTime_t(timeStamp).time();
    int hours = time.hour();
    int minutes = time.minute();
    int seconds = time.second();

    if (hours < 10)
        date += "0"+QString::number(hours);
    else
        date += QString::number(hours);

    date += ":";

    if (minutes < 10)
        date += "0"+QString::number(minutes);
    else
        date += QString::number(minutes);

    date += ":";

    if (seconds < 10)
        date += "0"+QString::number(seconds);
    else
        date += QString::number(seconds);

    return date;
}

ConnectionInfos BotInterface::getConnectionInfos() const
{
    return m_infos;
}

SocketIO *BotInterface::getSocket()
{
    return m_sender;
}

void BotInterface::sendChatMessage(QVariant channel, QVariant message)
{
    Channel c;
    switch (channel.toInt())
    {
    default:
        c = CHANNELGLOBAL;
        break;

    case 0:
        c = CHANNELGLOBAL;
        break;

    case 1:
        c = CHANNELPARTY;
        break;

    case 2:
        c = CHANNELGUILD;
        break;

    case 3:
        c = CHANNELSALES;
        break;

    case 4:
        c = CHANNELSEEK;
        break;

    case 5:
        c = CHANNELTEAM;
        break;
    }

    if (!message.toString().isEmpty())
        m_engine->getFloodModule().sendChatMessage(m_sender, message.toString(), c);
}

void BotInterface::changeMapTop()
{
    if (getData().generalData.botState == BotState::INACTIVE_STATE &&
            !getData().scriptData.isActive)
        m_engine->getMapModule().changeMap(m_sender, MapSide::TOP);
}

void BotInterface::changeMapRight()
{
    if (getData().generalData.botState == BotState::INACTIVE_STATE &&
            !getData().scriptData.isActive)
        m_engine->getMapModule().changeMap(m_sender, MapSide::RIGHT);
}

void BotInterface::changeMapLeft()
{
    if (getData().generalData.botState == BotState::INACTIVE_STATE &&
            !getData().scriptData.isActive)
        m_engine->getMapModule().changeMap(m_sender, MapSide::LEFT);
}

void BotInterface::changeMapBottom()
{
    if (getData().generalData.botState == BotState::INACTIVE_STATE &&
            !getData().scriptData.isActive)
        m_engine->getMapModule().changeMap(m_sender, MapSide::BOTTOM);
}

void BotInterface::increaseStat(int index)
{
    switch(index)
    {
    case 0:
        m_engine->getStatsModule().increaseStat(m_sender, PlayerFields::VITALITY);
        break;

    case 1:
        m_engine->getStatsModule().increaseStat(m_sender, PlayerFields::WISDOM);
        break;

    case 2:
        m_engine->getStatsModule().increaseStat(m_sender, PlayerFields::STRENGTH);
        break;

    case 3:
        m_engine->getStatsModule().increaseStat(m_sender, PlayerFields::INTELLIGENCE);
        break;

    case 4:
        m_engine->getStatsModule().increaseStat(m_sender, PlayerFields::CHANCE);
        break;

    case 5:
        m_engine->getStatsModule().increaseStat(m_sender, PlayerFields::AGILITY);
        break;

    default: qDebug()<<"BotInterface - IncreaseStat - Erreur index inconnu"<<index;
    }
}

void BotInterface::increaseSpell(int index)
{
    m_engine->getStatsModule().increaseSpell(m_sender, getData().playerData.spells.keys().at(index));
}

void BotInterface::destroyItem(int index, uint quantity)
{
    qDebug()<<"BOTINTERFACE - DESTROY"<<index<<" - QUANTITY"<<quantity;
    m_engine->getStatsModule().destroyItem(m_sender, getData().playerData.inventoryContent[index].UID, quantity);
}

void BotInterface::equipItem(int index)
{
    qDebug()<<"BOTINTERFACE - EQUIP ITEM"<<index;
    m_engine->getStatsModule().equipItem(m_sender, getData().playerData.inventoryContent[index].UID);
}

void BotInterface::unequipItem(int index)
{
    qDebug()<<"BOTINTERFACE - UNEQUIP ITEM"<<index;
    m_engine->getStatsModule().unequipItem(m_sender, getData().playerData.inventoryContent[index].UID);
}

void BotInterface::useItem(int index)
{
    qDebug()<<"BOTINTERFACE - USE ITEM"<<index;
    m_engine->getStatsModule().useItem(m_sender, getData().playerData.inventoryContent[index].UID);
}

void BotInterface::addMonster(QString s)
{
    int id = m_monstersCompleter.searchWord(s);

    qDebug()<<"BOTINTERFACE - STRING:"<<s<<" - ID:"<<id;
}

void BotInterface::addSpell(QString s)
{
    int id = m_spellsCompleter.searchWord(s);

    if(id != INVALID)
    {
        RequestedSpell r;
        r.spellID = id;
        r.castNb = 1;
        r.useAI = true;
        r.spellCible = SpellCible::ENEMY;
        m_fightSpellsModel->addSpell(r);
    }
}

const BotData &BotInterface::getData() const
{
    return m_engine->getData(m_sender);
}
