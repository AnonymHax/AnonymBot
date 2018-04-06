#include "ScriptModule.h"

ScriptModule::ScriptModule(QMap<SocketIO *, BotData> *connectionsData,
                           MapModule *mapModule, FightModule *fightModule,
                           FarmModule *farmModule,
                           CraftModule *craftModule,
                           InteractionModule *interactionModule,
                           GroupModule *groupModule,
                           StatsModule *statsModule,
                           ConnectionModule *connectionModule):
    AbstractModule(ModuleType::SCRIPT, connectionsData),
    m_mapModule(mapModule),
    m_fightModule(fightModule),
    m_farmModule(farmModule),
    m_craftModule(craftModule),
    m_interactionModule(interactionModule),
    m_groupModule(groupModule),
    m_statsModule(statsModule),
    m_connectionModule(connectionModule)
{
    connect(m_mapModule, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_farmModule, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_craftModule, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_interactionModule, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_fightModule, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_fightModule, SIGNAL(scriptActionCancel(SocketIO*)), this, SLOT(cancelProcessingAction(SocketIO*)));
    connect(m_fightModule, SIGNAL(scriptActionRepeat(SocketIO*)), this, SLOT(processRepeatAction(SocketIO*)));
    connect(m_statsModule, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
}

void ScriptModule::reset(SocketIO *sender)
{
    m_botData[sender].scriptData.lastActionMapId = INVALID;
    m_botData[sender].scriptData.isIndependent = false;
    m_botData[sender].scriptData.toExecute.clear();
    m_botData[sender].scriptData.activeModule = ModuleType::UNKNOWN;
    m_botData[sender].scriptData.sequence = -10;
    m_botData[sender].scriptData.scriptMaxTime = INVALID;
}

bool ScriptModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::BASICACKMESSAGE:
    {
        if(m_botData[sender].scriptData.scriptMaxTime != INVALID &&
                m_botData[sender].scriptData.scriptMaxTime < m_botData[sender].scriptData.scriptTimer.elapsed() &&
                sender->getLatencyList().last() <= m_botData[sender].scriptData.scriptMaxTime)
        {
            m_botData[sender].scriptData.scriptMaxTime = INVALID;
            alert(sender)<<"Il semblerait que le bot soit bloqué, tentative de relance du script...";
            m_connectionModule->reconnect(sender);
        }
    }
        break;
    }

    return messageFound;
}

ScriptPathMapData ScriptModule::getGhost(SocketIO *sender, uint id)
{
    ScriptPathMapData d;
    if (m_botData[sender].scriptData.ghost.isEmpty())
        return d;

    if (!id)
        id = m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId;

    foreach (ScriptPathMapData m, m_botData[sender].scriptData.ghost)
        if (m.id == id)
            return d;

    return d;
}

ScriptPathMapData ScriptModule::getBank(SocketIO *sender, uint id)
{
    ScriptPathMapData d;
    if (m_botData[sender].scriptData.bank.isEmpty())
        return d;

    if (!id)
        id = m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId;

    foreach (ScriptPathMapData m, m_botData[sender].scriptData.bank)
        if (m.id == id)
            return d;

    return d;
}

ScriptPathMapData ScriptModule::getLost(SocketIO *sender)
{
    ScriptPathMapData d;
    ScriptPathMapData s;

    if (m_botData[sender].scriptData.lost.isEmpty())
        return d;

    int i = 0;
    foreach (ScriptPathMapData m, m_botData[sender].scriptData.lost)
    {
        if (conditionalParser(sender, m.condition))
        {
            if (m.condition.isEmpty())
                d = m;
            else
                s = m;

            i++;
        }
    }

    convertToFunction(d);
    convertToFunction(s);
    if (!m_botData[sender].scriptData.isActive)
        return d;
    else if (i >= 1 || d.id == INVALID)
        return d;
    else
        return s;
}

ScriptPathMapData ScriptModule::getMap(SocketIO *sender, uint id)
{
    ScriptPathMapData d = {};
    ScriptPathMapData s = {};
    if (m_botData[sender].scriptData.data.isEmpty())
        return d;

    if (!id)
        id = m_botData[sender].mapData.map.getMapId();

    QList<ScriptPathMapData> l;
    foreach (ScriptPathMapData m, m_botData[sender].scriptData.data)
        if (m.id == id)
            l << m;

    int i = 0;
    foreach (ScriptPathMapData m, l)
    {
        if (conditionalParser(sender, m.condition))
        {
            if (m.tag == ScriptTag::BANK)
                return m;
            else if (m.defaultCondition)
                return m;
            else if (m.condition.isEmpty())
                d = m;
            else
                d = m;

            i++;
        }
    }

    convertToFunction(d);
    convertToFunction(s);
    if (!m_botData[sender].scriptData.isActive)
        return d;
    else if (i >= 1 || d.id == INVALID)
        return d;
    else
        return s;
}

void ScriptModule::cancelProcessingAction(SocketIO *sender)
{
    if(m_botData[sender].scriptData.lastInstruction.type != ScriptFunctionEnum::UNDEFINED)
    {
        m_botData[sender].scriptData.toExecute<<m_botData[sender].scriptData.lastInstruction;
        m_botData[sender].scriptData.lastInstruction.type = ScriptFunctionEnum::UNDEFINED;
    }
}

void ScriptModule::processRepeatAction(SocketIO *sender)
{
    SocketIO *master = m_groupModule->getMaster(sender);
    QList<SocketIO*> slaves = m_groupModule->getSlaves(sender);

    // Si c'est le master / independent
    if(master == NULL)
    {
        slaves<<sender;

        foreach(SocketIO *slave, slaves)
            m_botData[slave].scriptData.toExecute<<m_botData[slave].scriptData.lastInstruction;

        processNextAction(sender);
    }
}

void ScriptModule::processNextAction(SocketIO *sender)
{
    if(m_botData[sender].scriptData.isActive)
    {
        action(sender) << "P. NEXT ACTION"<<m_botData[sender].mapData.map.getPosition().getX()<<m_botData[sender].mapData.map.getPosition().getY();

        SocketIO *master = m_groupModule->getMaster(sender);

        if(master == NULL && !m_groupModule->getSlaves(sender).isEmpty())
            master = sender;

        if(m_botData[sender].scriptData.toExecute.isEmpty() && groupNeedsHeal(sender))
        {
            action(sender)<<"Regeneration de groupe en cours";

            m_botData[sender].scriptData.activeModule = ModuleType::STATS;

            if(!m_statsModule->healEat(sender))
                m_statsModule->healSit(sender);

            return;
        }

        else if(m_botData[sender].scriptData.toExecute.isEmpty() && m_statsModule->needsToGoToPhoenix(sender))
        {
            m_botData[sender].scriptData.isIndependent = true;

            if(m_botData[sender].scriptData.lastActionMapId == m_botData[sender].mapData.map.getMapId())
                action(sender)<<"Etat fantome, passage au phoenix nécessaire";

            m_botData[sender].scriptData.lastActionMapId = m_botData[sender].mapData.map.getMapId();
            m_botData[sender].scriptData.toExecute = getGhost(sender).functions;

            if(m_botData[sender].scriptData.toExecute.isEmpty())
            {
                action(sender)<<"Erreur, la balise GHOST n'est pas configurée";
                return;
            }
        }

        else if(m_botData[sender].scriptData.toExecute.isEmpty() && groupNeedsToGoToBank(sender))
        {
            if(m_botData[sender].scriptData.lastActionMapId == m_botData[sender].mapData.map.getMapId())
                action(sender)<<"Limite de pods dépassée, retour à la banque nécessaire";

            m_botData[sender].scriptData.lastActionMapId = m_botData[sender].mapData.map.getMapId();
            m_botData[sender].scriptData.toExecute = getBank(sender).functions;

            if(m_botData[sender].scriptData.toExecute.isEmpty())
                action(sender)<<"Erreur, la balise BANK n'est pas configurée";
        }

        else if(m_botData[sender].scriptData.toExecute.isEmpty())
        {
            ScriptPathMapData d = getMap(master, m_botData[sender].mapData.map.getMapId());

            if(master != sender)
                d = arrangeScriptForSlave(d);

            if (d.id != INVALID)
            {
                m_botData[sender].scriptData.lastActionMapId = m_botData[sender].mapData.map.getMapId();
                m_botData[sender].scriptData.toExecute = d.functions;
            }
        }


        if (!m_botData[sender].scriptData.toExecute.isEmpty())
        {
            ScriptFunction f = m_botData[sender].scriptData.toExecute.first();
            m_botData[sender].scriptData.toExecute.removeFirst();
            m_botData[sender].scriptData.lastInstruction = f;

            if(m_botData[sender].playerData.lifeStatus == PlayerLifeStatusEnum::STATUS_TOMBSTONE)
            {
                m_botData[sender].scriptData.toExecute<<m_botData[sender].scriptData.lastInstruction;
                m_statsModule->freeSoul(sender);
                m_botData[sender].scriptData.activeModule = ModuleType::STATS;
            }

            else if (f.type == ScriptFunctionEnum::FIGHT)
            {
                debug(sender)<<"FIGHT";
                m_botData[sender].scriptData.activeModule = ModuleType::FIGHT;

                if (!m_fightModule->processMonsters(sender))
                    processNextAction(sender);
            }

            else if (f.type == ScriptFunctionEnum::COLLECT)
            {
                debug(sender)<<"FARM";
                m_botData[sender].scriptData.activeModule = ModuleType::FARM;

                if (m_farmModule->processFarm(sender))
                    m_botData[sender].scriptData.scriptMaxTime = FARM_MAXTIME;

                else
                    processNextAction(sender);
            }

            else if (f.type == ScriptFunctionEnum::MOVE)
            {
                debug(sender)<<"MOVE";
                QList<QVariant> sides = f.params.first().toList();
                MapSide m = (MapSide)sides[qrand() % sides.size()].toInt();
                m_botData[sender].scriptData.activeModule = ModuleType::MAP;

                if (m_mapModule->changeMap(sender, m))
                    m_botData[sender].scriptData.scriptMaxTime = MOVE_MAXTIME;

                else
                    action(sender) << "Une erreur est survenue, impossible de passer d'une carte à une autre";
            }

            else if (f.type == ScriptFunctionEnum::CELL)
            {
                debug(sender)<<"CELL";
                QList<QVariant> cells = f.params.first().toList();
                uint chosenCell = cells[qrand() % cells.size()].toInt();
                m_botData[sender].scriptData.activeModule = ModuleType::MAP;

                if (m_mapModule->changeCell(sender, chosenCell))
                    m_botData[sender].scriptData.scriptMaxTime = MOVE_MAXTIME;

                else if (chosenCell != m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId)
                    action(sender) << "Une erreur est survenue, impossible de bouger à la cellule"<<chosenCell;
            }

            else if (f.type == ScriptFunctionEnum::USE)
            {
                debug(sender)<<"USE";

                if (m_interactionModule->processUse(sender, f.params.first().toInt(), f.params.at(1).toString()))
                {
                    m_botData[sender].scriptData.scriptMaxTime = INTERACTION_MAXTIME;
                    m_botData[sender].scriptData.activeModule = ModuleType::INTERACTION;
                }

                else
                    action(sender) << "Une erreur est survenue, impossible d'intéragir avec un item";
            }

            else if (f.type == ScriptFunctionEnum::NPC_INTERACT)
            {
                debug(sender) << "NPC INTERACT";

                if (m_interactionModule->processNpcInteraction(sender, f.params.first().toInt()))
                {
                    m_botData[sender].scriptData.scriptMaxTime = INTERACTION_MAXTIME;
                    m_botData[sender].scriptData.activeModule = ModuleType::INTERACTION;
                }

                else
                    action(sender) << "Une erreur est survenue, impossible d'intéragir avec un pnj";
            }

            else if (f.type == ScriptFunctionEnum::NPC_DIALOG)
            {
                debug(sender) << "NPC DIALOG";

                if (m_interactionModule->processNpcDialog(sender, f.params.last().toString()))
                {
                    m_botData[sender].scriptData.scriptMaxTime = INTERACTION_MAXTIME;
                    m_botData[sender].scriptData.activeModule = ModuleType::INTERACTION;
                }

                else
                    action(sender) << "Une erreur est survenue, impossible d'intéragir avec un pnj";
            }

            else if (f.type == ScriptFunctionEnum::NPC_QUIT)
            {
                debug(sender) << "NPC QUIT";

                if (m_interactionModule->leaveNpcDialog(sender))
                {
                    m_botData[sender].scriptData.scriptMaxTime = INTERACTION_MAXTIME;
                    m_botData[sender].scriptData.activeModule = ModuleType::INTERACTION;
                }

                else
                    processNextAction(sender);
            }

            else if (f.type == ScriptFunctionEnum::CRAFT)
            {
                debug(sender) << "CRAFT";

                if (m_craftModule->processCraft(sender))
                {
                    m_botData[sender].scriptData.scriptMaxTime = CRAFT_MAXTIME;
                    m_botData[sender].scriptData.activeModule = ModuleType::CRAFT;
                }

                else
                    processNextAction(sender);
            }

            else if(f.type == ScriptFunctionEnum::UNDEFINED)
            {

            }

            else
            {
                alert(sender) << "Fonction de trajet inconnue";
                processNextAction(sender);
            }

            if(m_botData[sender].scriptData.toExecute.isEmpty() && m_botData[sender].scriptData.isIndependent)
                m_botData[sender].scriptData.isIndependent = false;
        }

        else
        {
            ScriptPathMapData d = getLost(master);

            if (d.id == INVALID)
                action(sender)<<"Carte non repertoriée, pensez à inclure une position de secours";

            else if (m_mapModule->changeMap(sender, d.id))
            {
                m_botData[sender].scriptData.activeModule = ModuleType::MAP;
                action(sender) << "Carte non repertoriée dans le script, tentative de recuperation en position de secours";
            }

            else if(d.id != m_botData[sender].mapData.map.getMapId())
                action(sender) << "Carte non repertoriée dans le script, impossible de récuperer";
        }

        if(m_botData[sender].scriptData.scriptMaxTime != INVALID)
            m_botData[sender].scriptData.scriptTimer.restart();
    }
}

void ScriptModule::processControl(SocketIO *sender)
{
    debug(sender)<<"-----START PROCESS CONTROL-------";

    m_botData[sender].scriptData.scriptMaxTime = INVALID;
    m_botData[sender].scriptData.activeModule = ModuleType::UNKNOWN;

    SocketIO *master = m_groupModule->getMaster(sender);
    if(master == NULL && !m_groupModule->getSlaves(sender).isEmpty())
        master = sender;

    // MODE MULTI-COMPTES
    if(master != NULL)
    {
        // LE GROUPE EST REUNI
        if(m_groupModule->isGroupOnMapAndInactive(master))
        {
            QList<SocketIO*> slaves = m_groupModule->getSlaves(master);

            foreach(SocketIO *slave, slaves)
            {
                if(m_botData[slave].scriptData.activeModule == ModuleType::UNKNOWN)
                {
                    // ON FOURNI LES INSTRUCTIONS AUX ESCLAVES N'AYANT PAS CHARGE DE SCRIPTS
                    if(m_botData[slave].scriptData.toExecute.isEmpty())
                    {
                        m_botData[slave].scriptData.isIndependent = false;
                        m_botData[slave].scriptData.toExecute = arrangeScriptForSlave(getMap(master, m_botData[slave].mapData.map.getMapId())).functions;
                    }

                    m_botData[slave].scriptData.isActive = true;

                    // SYNCHRONISATION A LA MEME SEQUENCE SI NECESSAIRE (DEMARRAGE & BUGS)
                    if ((m_botData[slave].scriptData.sequence > m_botData[master].scriptData.sequence ||
                         m_botData[slave].scriptData.sequence < 0) &&
                            !m_botData[slave].scriptData.isIndependent)
                    {
                        int s = m_botData[master].scriptData.toExecute.size();

                        if(m_botData[master].scriptData.activeModule != ModuleType::UNKNOWN)
                            s++;

                        action(slave)<<"ASYNCHRONE - RECALIBRAGE - Sequence:"<<m_botData[slave].scriptData.sequence<<"- MASTER's Sequence:"<<m_botData[master].scriptData.sequence;

                        // action(slave)<<"CALCUL"<< m_botData[m].scriptData.sequence <<f.functions.size()<<s;
                        m_botData[slave].scriptData.sequence = m_botData[master].scriptData.sequence;
                    }

                    // LES MEMBRES EN PHASE CONTINUENT LEURS ACTIONS
                    if(m_botData[slave].scriptData.sequence < m_botData[master].scriptData.sequence &&
                            !m_botData[slave].scriptData.isIndependent)
                    {
                        action(slave)<<"SYNCHRONE - Sequence :"<<m_botData[slave].scriptData.sequence;
                        processNextAction(slave);

                        if(m_botData[slave].scriptData.sequence >= 0)
                            m_botData[slave].scriptData.sequence = m_botData[slave].scriptData.sequence + 1;
                    }

                    else if(m_botData[slave].scriptData.isIndependent)
                    {
                        action(slave)<<"ISOLEMENT";
                        m_botData[slave].scriptData.sequence = INVALID;
                        processNextAction(slave);
                    }

                    // LES AUTRES AYANT DEJA EXECUTE LEUR ACTION ATTENDENT LES AUTRES
                    else
                        action(slave)<<"EN ATTENTE1 - MAP X:"<<m_botData[slave].mapData.map.getPosition().getX()<<"Y:"<<m_botData[slave].mapData.map.getPosition().getY()<<" - Sequence:"<<m_botData[slave].scriptData.sequence;
                }
            }

            if(isGroupReadyForNextSequence(master))
            {
                if(m_botData[master].scriptData.sequence >= 0)
                    m_botData[master].scriptData.sequence = m_botData[master].scriptData.sequence + 1;

                action(master)<<"NEW ACTION - Sequence:"<<m_botData[master].scriptData.sequence;
                processNextAction(master);
            }

            else
                action(master)<<"EN ATTENTE2 - MAP X:"<<m_botData[master].mapData.map.getPosition().getX()<<"Y:"<<m_botData[master].mapData.map.getPosition().getY()<<" - Sequence:"<<m_botData[master].scriptData.sequence;
        }


        // LE GROUPE EST DISPERE SUR DIFFERENTES CARTES
        else
        {
            QList<SocketIO*> members = m_groupModule->getSlaves(master);
            members << master;

            bool lost = false;

            // ON CHERCHE UN MEMBRE DU GROUPE QUI EST PERDU (DEMARRAGE & BUGS)
            foreach(SocketIO *member, members)
            {
                if(m_botData[master].mapData.map.getMapId() != m_botData[member].mapData.map.getMapId() &&
                        m_botData[member].scriptData.activeModule == ModuleType::UNKNOWN &&
                        m_botData[member].scriptData.toExecute.isEmpty() &&
                        m_botData[member].scriptData.sequence != m_botData[master].scriptData.sequence &&
                        m_botData[member].scriptData.sequence+1 != m_botData[master].scriptData.sequence &&
                        !m_botData[member].scriptData.isIndependent)
                {
                    lost = true;
                    break;
                }
            }

            // SI UN MEMBRE DU GROUPE EST PERDU, RETOUR A LA POSITION LOST (DEMARRAGE & BUGS)
            if(lost)
            {
                int lostId = getLost(master).id;

                foreach(SocketIO *member, members)
                {
                    if(m_botData[member].mapData.map.getMapId() != lostId &&
                            m_botData[member].scriptData.activeModule == ModuleType::UNKNOWN)
                    {
                        m_botData[member].scriptData.toExecute.clear();
                        m_botData[member].scriptData.isActive = true;

                        action(member)<<"REGROUPEMENT - MAP X:"<<m_botData[member].mapData.map.getPosition().getX()<<"Y:"<<m_botData[member].mapData.map.getPosition().getY()<<" - Sequence:"<<m_botData[member].scriptData.sequence;
                        processNextAction(member);
                    }
                }
            }

            // LES MEMBRES EN PHASE CONTINUENT LEURS ACTIONS
            else
            {
                foreach(SocketIO *member, members)
                {
                    if(m_botData[master].mapData.map.getMapId() != m_botData[member].mapData.map.getMapId() &&
                            m_botData[member].scriptData.activeModule == ModuleType::UNKNOWN &&
                            m_botData[member].scriptData.sequence+1 == m_botData[master].scriptData.sequence)
                    {
                        action(member)<<"SYNCHRONE2 - Sequence:"<<m_botData[member].scriptData.sequence;

                        m_botData[member].scriptData.isActive = true;

                        //if(m_botData[member].scriptData.toExecute.isEmpty())
                        //   m_botData[member].scriptData.toExecute = arrangeScriptForSlave(getMap(master, m_botData[member].mapData.map.getMapId())).functions;

                        processNextAction(member);

                        if(m_botData[member].scriptData.sequence >= 0)
                            m_botData[member].scriptData.sequence = m_botData[member].scriptData.sequence + 1;
                    }

                    else
                        action(member)<<"EN ATTENTE3 - MAP X:"<<m_botData[member].mapData.map.getPosition().getX()<<"Y:"<<m_botData[member].mapData.map.getPosition().getY()<<" - Sequence :"<<m_botData[member].scriptData.sequence<<" - MASTER's Sequence:"<<m_botData[master].scriptData.sequence ;
                }
            }
        }
    }

    // MODE SOLO
    else
    {
        debug(sender)<<"INDEPENDENT";
        processNextAction(sender);
    }

    debug(sender)<<"-----END PROCESS CONTROL--------";
}

void ScriptModule::waitForInactivity()
{
    SocketIO *sender = m_waitingList.first();
    m_waitingList.removeFirst();
    processNextAction(sender);
}

bool ScriptModule::groupNeedsHeal(SocketIO *sender)
{
    SocketIO *master = m_groupModule->getMaster(sender);

    QList<SocketIO*> slaves = m_groupModule->getSlaves(sender);

    slaves<<master;

    foreach(SocketIO* player, slaves)
    {
        if(m_statsModule->needsHeal(player))
            return true;
    }

    return false;
}

bool ScriptModule::groupNeedsToGoToBank(SocketIO *sender)
{
    SocketIO *master = m_groupModule->getMaster(sender);

    QList<SocketIO*> slaves = m_groupModule->getSlaves(sender);

    slaves<<master;

    foreach(SocketIO* player, slaves)
    {  
        if(m_statsModule->needsToGoToBank(player))
            return true;
    }

    return false;
}

bool ScriptModule::isGroupReadyForNextSequence(SocketIO *master)
{
    QList<SocketIO*> slaves = m_groupModule->getSlaves(master);
    int sequence = m_botData[master].scriptData.sequence;
    int mapId = m_botData[master].mapData.map.getMapId();


    if(sequence < 0 || m_botData[master].scriptData.isIndependent || m_botData[master].scriptData.activeModule != ModuleType::UNKNOWN)
        return false;

    for(int i = 0; i < slaves.size(); i++)
    {
        if(sequence != m_botData[slaves[i]].scriptData.sequence ||
                mapId != m_botData[slaves[i]].mapData.map.getMapId() ||
                m_botData[slaves[i]].scriptData.isIndependent ||
                m_botData[slaves[i]].scriptData.activeModule != ModuleType::UNKNOWN)
            return false;
    }

    return true;
}

ScriptPathMapData ScriptModule::arrangeScriptForSlave(ScriptPathMapData s)
{
    for(int i = 0; i < s.functions.size(); i++)
    {
        if(s.functions[i].type == ScriptFunctionEnum::FIGHT)
            s.functions[i].type = ScriptFunctionEnum::UNDEFINED;
    }

    return s;
}

void ScriptModule::unloadFile(SocketIO *sender)
{
    m_botData[sender].scriptData.headers = 0;
    m_botData[sender].scriptData.data.clear();
    m_botData[sender].scriptData.lost.clear();
    m_botData[sender].scriptData.condition.clear();
    m_botData[sender].scriptData.fileContent.clear();
    m_botData[sender].scriptData.defaultCondition = false;
    m_botData[sender].scriptData.tag = ScriptTag::UNDEFINED;
    m_botData[sender].scriptData.isActive = false;
    m_botData[sender].scriptData.scriptMaxTime = INVALID;

    if(m_botData[sender].scriptData.activeModule == ModuleType::MAP)
        m_mapModule->stopMoving(sender);

    else if(m_botData[sender].scriptData.activeModule == ModuleType::INTERACTION)
        m_interactionModule->leaveNpcDialog(sender);
}

bool ScriptModule::loadFile(SocketIO *sender, QString p)
{
    QFile file(p);
    if (file.open(QIODevice::ReadOnly) && file.size())
    {
        m_botData[sender].scriptData.fileContent = file.readAll();
        return true;
    }

    return false;
}

int ScriptModule::parse(SocketIO *sender)
{
    int i = 1;
    m_botData[sender].scriptData.headers = 0;
    m_botData[sender].scriptData.tag = ScriptTag::UNDEFINED;
    m_botData[sender].scriptData.data.clear();
    m_botData[sender].scriptData.condition = "";
    m_botData[sender].scriptData.sequence = 0;

    QStringList lines = m_botData[sender].scriptData.fileContent.split('\n');

    foreach(QString line, lines)
    {
        line.replace("\r", "");
        line.replace("\n", "");

        if (!line.isEmpty() && line.mid(0, 2) != "//")
            if (!check(sender, line.split("//").first()))
                return i;

        i++;
    }

    if (m_botData[sender].scriptData.tag != ScriptTag::UNDEFINED)
        return i;

    else
    {
        m_botData[sender].scriptData.isActive = true;
        processControl(sender);
        return 0;
    }
}

bool ScriptModule::check(SocketIO *sender, QString d)
{
    if (!isMap(sender, d))
        if (!isHeader(sender, d))
            if (!isCondition(sender, d))
                if (!isOpenTag(sender, d))
                    if (!isCloseTag(sender, d))
                        return false;
    return true;
}

bool ScriptModule::isMap(SocketIO *sender, QString d)
{
    QRegularExpression r("[\[](?<x>[-]*[0-9][0-9]*),[ ]*(?<y>[-]*[0-9][0-9]*)[\]](?<p>.*)");
    QRegularExpression re("^(?<id>[0-9]+)[ ]*(?<p>.*)");
    QRegularExpressionMatch me = re.match(d);
    QRegularExpressionMatch m = r.match(d);

    if (!((m.hasMatch() || me.hasMatch()) && (m_botData[sender].scriptData.tag != ScriptTag::UNDEFINED)))
        return false;

    QString p;
    int id = INVALID;
    if (m.hasMatch())
    {
        p = m.captured("p");
        QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
        QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

        id = PathfindingMap::coordsToMapId(m.captured("x").toInt(), m.captured("y").toInt(), area->getSuperAreaId());
    }
    else if (me.hasMatch())
    {
        p = me.captured("p");
        id = me.captured("id").toInt();
    }
    else
        return false;

    QList<MapSide> s;
    QList<ScriptFunction> f;
    QStringList sp = p.split("+");
    foreach (QString str, sp)
    {
        QList<MapSide> side = getSides(str);
        ScriptFunction func = getFunction(str);

        if (m_botData[sender].scriptData.tag != ScriptTag::LOST && func.type == ScriptFunctionEnum::UNDEFINED && side.isEmpty())
            return false;
        else if ((func.type != ScriptFunctionEnum::UNDEFINED) && (func.type != ScriptFunctionEnum::MOVE))
            f.append(func);
        else if (!side.isEmpty())
            s = side;
    }

    ScriptPathMapData a;
    a.id = id;
    a.sides = s;
    a.functions = f;
    a.tag = m_botData[sender].scriptData.tag;
    a.condition = m_botData[sender].scriptData.condition;
    a.defaultCondition = m_botData[sender].scriptData.defaultCondition;

    if (m_botData[sender].scriptData.tag == ScriptTag::BANK)
        m_botData[sender].scriptData.bank << a;
    else if (m_botData[sender].scriptData.tag == ScriptTag::LOST)
        m_botData[sender].scriptData.lost << a;
    else if (m_botData[sender].scriptData.tag == ScriptTag::GHOST)
        m_botData[sender].scriptData.ghost << a;
    else if ((m_botData[sender].scriptData.tag != ScriptTag::LOST) && (m_botData[sender].scriptData.tag != ScriptTag::UNDEFINED))
        m_botData[sender].scriptData.data << a;
    else
        return false;

    return true;
}

bool ScriptModule::isHeader(SocketIO *sender, QString d)
{
    if (d.at(0) != '@')
        return false;

    m_botData[sender].scriptData.headers++;
    return true;
}

bool ScriptModule::isOpenTag(SocketIO *sender, QString d)
{
    QRegularExpression r("[<](?<tag>[^/#]*)[>]");
    QRegularExpressionMatch m = r.match(d);

    if (!m.hasMatch())
        return false;

    ScriptTag t;
    QString c = m.captured("tag");
    QRegularExpression bank("[bB][aA][nN][kK]");
    QRegularExpression lost("[lL][oO][sS][tT]");
    QRegularExpression move("[mM][oO][vV][eE]");
    QRegularExpression ghost("[gG][oO][sS][tT]");
    QRegularExpression craft("[cC][rR][aA][fF][tT]");
    QRegularExpression fight("[fF][iI][gG][hH][tT]");
    QRegularExpression collect("[cC][oO][lL][lL][eE][cC][tT]");
    QRegularExpression noAggro("[nN][oO][aA][gG][gG][rR][oO]");

    QRegularExpressionMatch matchBank = bank.match(c);
    QRegularExpressionMatch matchLost = lost.match(c);
    QRegularExpressionMatch matchMove = move.match(c);
    QRegularExpressionMatch matchGhost = ghost.match(c);
    QRegularExpressionMatch matchCraft = craft.match(c);
    QRegularExpressionMatch matchFight = fight.match(c);
    QRegularExpressionMatch matchCollect = collect.match(c);
    QRegularExpressionMatch matchNoAggro = noAggro.match(c);

    if (matchBank.hasMatch())
        t = ScriptTag::BANK;
    else if (matchLost.hasMatch())
        t = ScriptTag::LOST;
    else if (matchMove.hasMatch())
        t = ScriptTag::MOVE;
    else if (matchGhost.hasMatch())
        t = ScriptTag::GHOST;
    else if (matchCraft.hasMatch())
        t = ScriptTag::CRAFT;
    else if (matchFight.hasMatch())
        t = ScriptTag::FIGHT;
    else if (matchCollect.hasMatch())
        t = ScriptTag::COLLECT;
    else if (matchNoAggro.hasMatch())
        t = ScriptTag::NO_AGGRO;
    else
        return false;

    m_botData[sender].scriptData.tag = t;
    return true;
}

bool ScriptModule::isCloseTag(SocketIO *sender, QString d)
{
    QRegularExpression r("[<][/](?<tag>[^#]*)[>]");
    QRegularExpressionMatch m = r.match(d);

    if (!m.hasMatch())
        return false;

    ScriptTag t;
    QString c = m.captured("tag");
    QRegularExpression bank("[bB][aA][nN][kK]");
    QRegularExpression lost("[lL][oO][sS][tT]");
    QRegularExpression move("[mM][oO][vV][eE]");
    QRegularExpression ghost("[gG][oO][sS][tT]");
    QRegularExpression craft("[cC][rR][aA][fF][tT]");
    QRegularExpression fight("[fF][iI][gG][hH][tT]");
    QRegularExpression collect("[cC][oO][lL][lL][eE][cC][tT]");
    QRegularExpression noAggro("[nN][oO][aA][gG][gG][rR][oO]");

    QRegularExpressionMatch matchBank = bank.match(c);
    QRegularExpressionMatch matchLost = lost.match(c);
    QRegularExpressionMatch matchMove = move.match(c);
    QRegularExpressionMatch matchGhost = ghost.match(c);
    QRegularExpressionMatch matchCraft = craft.match(c);
    QRegularExpressionMatch matchFight = fight.match(c);
    QRegularExpressionMatch matchCollect = collect.match(c);
    QRegularExpressionMatch matchNoAggro = noAggro.match(c);

    if (matchBank.hasMatch())
        t = ScriptTag::BANK;
    else if (matchLost.hasMatch())
        t = ScriptTag::LOST;
    else if (matchMove.hasMatch())
        t = ScriptTag::MOVE;
    else if (matchGhost.hasMatch())
        t = ScriptTag::GHOST;
    else if (matchCraft.hasMatch())
        t = ScriptTag::CRAFT;
    else if (matchFight.hasMatch())
        t = ScriptTag::FIGHT;
    else if (matchCollect.hasMatch())
        t = ScriptTag::COLLECT;
    else if (matchNoAggro.hasMatch())
        t = ScriptTag::NO_AGGRO;
    else
        return false;

    if (m_botData[sender].scriptData.tag != t || m_botData[sender].scriptData.tag == ScriptTag::UNDEFINED)
        return false;

    m_botData[sender].scriptData.tag = ScriptTag::UNDEFINED;
    return true;
}

bool ScriptModule::isCondition(SocketIO *sender, QString d)
{
    QRegularExpression r("#[iI][fF][ ]*[\[](?<c>.*)[\]]");
    QRegularExpressionMatch mr = r.match(d);

    QRegularExpression e("#[eE][nN][dD][iI][fF]");
    QRegularExpressionMatch me = e.match(d);

    QRegularExpression de("[dD][eE][fF][aA][uU][lL][tT]");
    QRegularExpressionMatch md = de.match(mr.captured("d"));

    if (mr.hasMatch())
    {
        QString c = mr.captured("c");
        c.replace("\r", "");
        c.replace("\n", "");

        if (md.hasMatch())
            m_botData[sender].scriptData.defaultCondition = true;
        else
            m_botData[sender].scriptData.defaultCondition = false;

        if (ScriptModule::checkConditionalSyntax(c))
            m_botData[sender].scriptData.condition = c;
        else
            return false;
    }

    else if (me.hasMatch())
    {
        if (!m_botData[sender].scriptData.condition.isEmpty())
            m_botData[sender].scriptData.condition = "";
        else
            return false;
    }

    else
        return false;

    return true;
}

QList<MapSide> ScriptModule::getSides(QString side)
{
    QList<MapSide> q;
    QStringList sides = side.split("|");
    foreach (QString s, sides)
    {
        s.replace(" ", "");

        QRegularExpression t("[tT][oO][pP]");
        QRegularExpression l("[lL][eE][fF][tT]");
        QRegularExpression r("[rR][iI][gG][hH][tT]");
        QRegularExpression b("[bB][oO][tT][tT][oO][mM]");

        QRegularExpressionMatch mt = t.match(s);
        QRegularExpressionMatch ml = l.match(s);
        QRegularExpressionMatch mr = r.match(s);
        QRegularExpressionMatch mb = b.match(s);

        if (mt.hasMatch())
            q.append(MapSide::TOP);
        else if (ml.hasMatch())
            q.append(MapSide::LEFT);
        else if (mr.hasMatch())
            q.append(MapSide::RIGHT);
        else if (mb.hasMatch())
            q.append(MapSide::BOTTOM);
        else
            return QList<MapSide>();
    }

    return q;
}

ScriptFunction ScriptModule::getFunction(QString f)
{
    ScriptFunction r;
    r.type = ScriptFunctionEnum::UNDEFINED;

    QRegularExpression npc("npc[ ]*[(](?<f>.*)[ ]*[)]");
    QRegularExpression use("use[ ]*[(](?<f>.*)[ ]*[)]");
    QRegularExpression cell("cell[ ]*[(](?<f>.*)[ ]*[)]");
    QRegularExpression move("move[ ]*[(](?<f>.*)[ ]*[)]");
    QRegularExpression zaap("zaap[ ]*[(](?<f>.*)[ ]*[)]");
    QRegularExpression craft("craft[ ]*[(](?<f>.*)[ ]*[)]");
    QRegularExpression zaapi("zaapi[ ]*[(](?<f>.*)[ ]*[)]");
    QRegularExpression trade("trade[ ]*[(](?<f>.*)[ ]*[)]");
    QRegularExpression weapon("weapon[ ]*[(](?<f>.*)[ ]*[)]");
    QRegularExpression useItem("useItem[ ]*[(](?<f>.*)[ ]*[)]");
    QRegularExpression autoPath("autoPath[ ]*[(](?<f>.*)[ ]*[)]");

    QRegularExpressionMatch npcMatch = npc.match(f);
    QRegularExpressionMatch useMatch = use.match(f);
    QRegularExpressionMatch cellMatch = cell.match(f);
    QRegularExpressionMatch moveMatch = move.match(f);
    QRegularExpressionMatch zaapMatch = zaap.match(f);
    QRegularExpressionMatch craftMatch = craft.match(f);
    QRegularExpressionMatch zaapiMatch = zaapi.match(f);
    QRegularExpressionMatch tradeMatch = trade.match(f);
    QRegularExpressionMatch weaponMatch = weapon.match(f);
    QRegularExpressionMatch useItemMatch = useItem.match(f);
    QRegularExpressionMatch autoPathMatch = autoPath.match(f);

    QString d;
    if (npcMatch.hasMatch())
    {
        r.type = ScriptFunctionEnum::NPC_INTERACT;
        d = npcMatch.captured("f");
    }

    else if (useMatch.hasMatch())
    {
        r.type = ScriptFunctionEnum::USE;
        d = useMatch.captured("f");
    }

    else if (cellMatch.hasMatch())
    {
        r.type = ScriptFunctionEnum::CELL;
        d = cellMatch.captured("f");
    }

    else if (moveMatch.hasMatch())
    {
        r.type = ScriptFunctionEnum::MOVE;
        d = moveMatch.captured("f");
    }

    else if (zaapMatch.hasMatch())
    {
        r.type = ScriptFunctionEnum::ZAAP;
        d = zaapMatch.captured("f");
    }

    else if (craftMatch.hasMatch())
    {
        r.type = ScriptFunctionEnum::CRAFT;
        d = craftMatch.captured("f");
    }

    else if (zaapiMatch.hasMatch())
    {
        r.type = ScriptFunctionEnum::ZAAPI;
        d = zaapiMatch.captured("f");
    }

    else if (tradeMatch.hasMatch())
    {
        r.type = ScriptFunctionEnum::TRADE;
        d = tradeMatch.captured("f");
    }

    else if (weaponMatch.hasMatch())
    {
        r.type = ScriptFunctionEnum::WEAPON;
        d = weaponMatch.captured("f");
    }

    else if (useItemMatch.hasMatch())
    {
        r.type = ScriptFunctionEnum::USE_ITEM;
    }

    else if (autoPathMatch.hasMatch())
    {
        r.type = ScriptFunctionEnum::AUTOPATH;
        d = autoPathMatch.captured("f");
    }

    else
        return r;

    QVariantList p;
    switch (r.type)
    {
    default:
        return r;
        break;

    case ScriptFunctionEnum::NPC_INTERACT:
    {
        QVariantList t = parseInt(d);
        if (t.isEmpty())
            r.type = ScriptFunctionEnum::UNDEFINED;

        if (r.type != ScriptFunctionEnum::UNDEFINED)
        {
            QVariantList u = parseStringArray(t.last().toString());
            if (u.isEmpty())
                r.type = ScriptFunctionEnum::UNDEFINED;

            if (r.type != ScriptFunctionEnum::UNDEFINED)
            {
                p.insert(p.end(), t.first());
                p.insert(p.end(), u.first());
            }
        }
    }
        break;

    case ScriptFunctionEnum::USE:
    {
        QVariantList t = parseInt(d);
        if (t.isEmpty())
            r.type = ScriptFunctionEnum::UNDEFINED;

        if (r.type != ScriptFunctionEnum::UNDEFINED)
        {
            QVariantList u = parseString(t.last().toString());
            if (t.isEmpty())
                r.type = ScriptFunctionEnum::UNDEFINED;

            if (r.type != ScriptFunctionEnum::UNDEFINED)
            {
                p.insert(p.end(), t.first());
                p.insert(p.end(), u.first());
            }
        }
    }
        break;

    case ScriptFunctionEnum::TRADE:
    {
        QVariantList t = parseInt(d);
        if (t.isEmpty())
            r.type = ScriptFunctionEnum::UNDEFINED;

        if (r.type != ScriptFunctionEnum::UNDEFINED)
            p.insert(p.end(), t.first());
    }
        break;

    case ScriptFunctionEnum::USE_ITEM:
    {
        QVariantList t = parseInt(d);
        if (t.isEmpty())
            r.type = ScriptFunctionEnum::UNDEFINED;

        if (r.type != ScriptFunctionEnum::UNDEFINED)
        {
            QVariantList u = parseInt(t.last().toString());
            if (t.isEmpty() || u.isEmpty())
                r.type = ScriptFunctionEnum::UNDEFINED;

            if (r.type != ScriptFunctionEnum::UNDEFINED)
            {
                p.insert(p.end(), t.first());
                p.insert(p.end(), u.first());
            }
        }
    }
        break;

    case ScriptFunctionEnum::MOVE:
    {
        QVariantList t = parseStringArray(d);
        if (t.isEmpty())
            r.type = ScriptFunctionEnum::UNDEFINED;

        if (r.type != ScriptFunctionEnum::UNDEFINED)
            p.insert(p.end(), t.first());
    }
        break;

    case ScriptFunctionEnum::AUTOPATH:
    {
        QVariantList t = parseInt(d);
        if (t.isEmpty())
            r.type = ScriptFunctionEnum::UNDEFINED;

        if (r.type != ScriptFunctionEnum::UNDEFINED)
            p.insert(p.end(), t.first());
    }
        break;

    case ScriptFunctionEnum::WEAPON:
    {
        QVariantList t = parseInt(d);
        if (t.isEmpty())
            r.type = ScriptFunctionEnum::UNDEFINED;

        if (r.type != ScriptFunctionEnum::UNDEFINED)
            p << t.first();
    }
        break;

    case ScriptFunctionEnum::ZAAP:
    {
        QVariantList t = parseInt(d);
        if (t.isEmpty())
            r.type = ScriptFunctionEnum::UNDEFINED;

        if (r.type != ScriptFunctionEnum::UNDEFINED)
            p.insert(p.end(), t.first());
    }
        break;

    case ScriptFunctionEnum::ZAAPI:
    {
        QVariantList t = parseInt(d);
        if (t.isEmpty())
            r.type = ScriptFunctionEnum::UNDEFINED;

        if (r.type != ScriptFunctionEnum::UNDEFINED)
            p.insert(p.end(), t.first());
    }
        break;

    case ScriptFunctionEnum::CELL:
    {
        QVariantList t = parseIntArray(d);
        if (t.isEmpty())
            r.type = ScriptFunctionEnum::UNDEFINED;

        if (r.type != ScriptFunctionEnum::UNDEFINED)
            p.insert(p.end(), t.first());
    }
        break;
    }

    r.params = p;
    return r;
}

QList<MapSide> ScriptModule::getSideFromMove(ScriptFunction f)
{
    QStringList l;
    QVariantList p = f.params;
    for (int i = 0; i < p.first().toList().size(); i++)
        l << p.first().toList().at(i).toString();

    QString c = l.join("|");
    QList<MapSide> r = getSides(c);

    return r;
}

QVariantList ScriptModule::parseInt(QString d)
{
    QRegularExpression r("(?<i>[0-9]+)[ ]*,*[ ]*(?<r>.*)");
    QRegularExpressionMatch m = r.match(d);

    QVariantList l;
    if (!m.hasMatch())
        return l;

    int i = m.captured("i").toInt();
    QString rest = m.captured("r");

    l.insert(l.end(), i);
    l.insert(l.end(), rest);
    return l;
}

QVariantList ScriptModule::parseIntArray(QString d)
{
    QRegularExpression r("(?<a>[\[]([ ]*[0-9,]+[ ]*)+[\]])[ ]*(?<r>.*)");
    QRegularExpressionMatch m = r.match(d);

    QVariantList l;
    if (!m.hasMatch())
        return l;

    QString a = m.captured("a");
    a.replace(" ", "");
    a.replace("[", "");
    a.replace("]", "");
    QStringList array = a.split(",");

    QVariantList s;
    foreach (QString str, array)
    {
        QRegularExpression re("[ ]*(?<d>[0-9]+)[ ]*");
        QRegularExpressionMatch me = re.match(str);
        s.append(me.captured("d").toInt());
    }

    l.insert(l.end(), s);
    l.insert(l.end(), m.captured("r"));
    return l;
}

QVariantList ScriptModule::parseStringArray(QString d)
{
    QRegularExpression r("(?<a>[\[]([ ]*[\"].+[\"][ ]*)+[\]])[ ]*(?<r>.*)");
    QRegularExpressionMatch m = r.match(d);

    QVariantList l;
    if (!m.hasMatch())
        return l;

    QString a = m.captured("a");
    a.replace("[", "");
    a.replace("]", "");
    QStringList array = a.split(",");

    QStringList s;
    foreach (QString str, array)
    {
        QRegularExpression re("[ ]*[\"]+[ ]*(?<d>[^\"]+)[ ]*[\"]+");
        QRegularExpressionMatch me = re.match(str);
        s.append(me.captured("d"));
    }

    l.insert(l.end(), s);
    l.insert(l.end(), m.captured("r"));
    return l;
}

QVariantList ScriptModule::parseString(QString d)
{
    QRegularExpression r("[\"]+(?<s>[^\"]*)[\"]+[ ]*,*[ ]*(?<r>.*)");
    QRegularExpressionMatch m = r.match(d);

    QVariantList l;
    if (!m.hasMatch())
        return l;

    l.insert(l.end(), m.captured("s"));
    l.insert(l.end(), m.captured("r"));
    return l;
}

bool ScriptModule::checkConditionalSyntax(QString d)
{
    return true;
}

bool ScriptModule::conditionalParser(SocketIO *sender, QString d)
{
    return true;
}

void ScriptModule::convertToFunction(ScriptPathMapData &s)
{
    ScriptFunction func1;
    ScriptFunction func2;

    switch (s.tag)
    {
    default:
        break;

    case ScriptTag::COLLECT:
    {
        func1.type = ScriptFunctionEnum::COLLECT;
        s.functions.append(func1);
    }
        break;

    case ScriptTag::FIGHT:
    {
        func1.type = ScriptFunctionEnum::FIGHT;
        s.functions.append(func1);
    }
        break;
    }

    QVariantList l;
    QVariantList p;
    foreach (MapSide side, s.sides)
        l << (int)side;

    p.insert(p.end(), l);

    for (int i = 0; i < s.functions.size(); i++)
    {
        if (s.functions[i].type == ScriptFunctionEnum::NPC_INTERACT)
        {
            QStringList dialogs = s.functions[i].params.last().toStringList();
            s.functions[i].params.removeLast();

            int count = 0;
            foreach (QString str, dialogs)
            {
                if (str.isEmpty())
                    break;

                ScriptFunction func3;
                func3.type = ScriptFunctionEnum::NPC_DIALOG;

                func3.params.insert(func3.params.end(), s.functions[i].params.first().toInt());
                func3.params.insert(func3.params.end(), str);

                s.functions.insert(i+1, func3);
                count++;
            }

            ScriptFunction end;
            end.type = ScriptFunctionEnum::NPC_QUIT;

            s.functions.insert(i+count+1, end);
        }
    }

    if (s.tag == ScriptTag::NO_AGGRO)
        p.insert(p.end(), true);
    else
        p.insert(p.end(), false);

    func2.params = p;
    func2.type = ScriptFunctionEnum::MOVE;

    if (!s.sides.isEmpty())
        s.functions.append(func2);
}

void ScriptModule::setActivePath(SocketIO *sender, bool active)
{
    m_botData[sender].scriptData.isActive = active;
}

void ScriptModule::setPodsLimit(SocketIO *sender, ushort ratio)
{
    if(ratio >= 0 && ratio <= 100)
        m_botData[sender].scriptData.podsLimitRatio = ratio;
}
