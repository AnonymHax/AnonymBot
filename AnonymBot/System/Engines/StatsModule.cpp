#include "StatsModule.h"

StatsModule::StatsModule(QMap<SocketIO *, BotData> *connectionsData):
    AbstractModule(ModuleType::STATS, connectionsData)
{
    foreach (int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::PETS))
    {
        QSharedPointer<PetData> p = qSharedPointerCast<PetData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::PETS, index));
        m_pets[p->getId()] = qSharedPointerCast<ItemData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, p->getId()))->getName();
    }

    m_inventoryPositions << CharacterInventoryPositionEnum::ACCESSORY_POSITION_HAT << CharacterInventoryPositionEnum::ACCESSORY_POSITION_BELT <<
                            CharacterInventoryPositionEnum::ACCESSORY_POSITION_AMULET << CharacterInventoryPositionEnum::ACCESSORY_POSITION_BOOTS <<
                            CharacterInventoryPositionEnum::ACCESSORY_POSITION_PETS << CharacterInventoryPositionEnum::ACCESSORY_POSITION_SHIELD <<
                            CharacterInventoryPositionEnum::INVENTORY_POSITION_COMPANION << CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_1 <<
                            CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_2 << CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_3 <<
                            CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_4 <<CharacterInventoryPositionEnum::ACCESSORY_POSITION_CAPE <<
                            CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_5 << CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_6 <<
                            CharacterInventoryPositionEnum::INVENTORY_POSITION_RING_LEFT << CharacterInventoryPositionEnum::INVENTORY_POSITION_RING_RIGHT <<
                            CharacterInventoryPositionEnum::ACCESSORY_POSITION_WEAPON;
}

void StatsModule::reset(SocketIO *sender)
{
    m_botData[sender].playerData.isRequestingFreeSoul = false;
    m_botData[sender].playerData.hasSentRequestFreeSoul = false;
    m_botData[sender].generalData.botState = INVALID_STATE;
}

bool StatsModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    if(m_botData[sender].mapData.map.isInit() &&
            m_botData[sender].generalData.botState == INACTIVE_STATE &&
            m_botData[sender].playerData.isRequestingFreeSoul &&
            !m_botData[sender].playerData.hasSentRequestFreeSoul)
    {
        m_botData[sender].playerData.hasSentRequestFreeSoul = true;

        GameRolePlayFreeSoulRequestMessage request;
        sender->send(request);
    }

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::MOUNTSETMESSAGE:
    {
        MountSetMessage message;
        message.deserialize(&reader);
        m_botData[sender].playerData.isRiding = true;

        QStringList effects;
        for (int i = 0; i < message.mountData->effectList.size(); i++)
            effects.append(QString::number(message.mountData->effectList[i]->value) + QString(" ") +  qSharedPointerCast<CharacteristicData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::CHARACTERISTICS, qSharedPointerCast<EffectData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::EFFECTS, message.mountData->effectList[i]->actionId))->getCharacteristic()))->getName());

        m_botData[sender].playerData.mountData.levelRatio = message.mountData->level == 100 ? 100 : (message.mountData->experience / message.mountData->experienceForNextLevel) * 100.0;
        m_botData[sender].playerData.mountData.breed = qSharedPointerCast<MountData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MOUNTS, message.mountData->model))->getName();
        m_botData[sender].playerData.mountData.energyMax = message.mountData->energyMax - 1;
        m_botData[sender].playerData.mountData.energy = message.mountData->energy;
        m_botData[sender].playerData.mountData.level = message.mountData->level;
        m_botData[sender].playerData.mountData.name = message.mountData->name;
        m_botData[sender].playerData.mountData.effects = effects;
    }
        break;

    case MessageEnum::MOUNTXPRATIOMESSAGE:
    {
        MountXpRatioMessage message;
        message.deserialize(&reader);

        m_botData[sender].playerData.mountData.xpRatio = message.ratio;
    }
        break;

    case MessageEnum::SPELLLISTMESSAGE:
    {
        SpellListMessage message;
        message.deserialize(&reader);

        m_botData[sender].playerData.spells.clear();
        foreach(SpellItem spell, message.spells)
        {
            Spell spellData;
            spellData.spellID = spell.spellId;
            spellData.spellLevel = spell.spellLevel;
            m_botData[sender].playerData.spells[spell.spellId] = spellData;
        }
    }
        break;

    case MessageEnum::SPELLMODIFYSUCCESSMESSAGE:
    {
        SpellModifySuccessMessage message;
        message.deserialize(&reader);

        Spell spellData;
        spellData.spellID = message.spellId;
        spellData.spellLevel = message.spellLevel;

        m_botData[sender].playerData.spells[message.spellId] = spellData;
    }
        break;

    case MessageEnum::KAMASUPDATEMESSAGE:
    {
        KamasUpdateMessage message;
        message.deserialize(&reader);
        m_botData[sender].playerData.kamas = message.kamasTotal;
    }
        break;

    case MessageEnum::INVENTORYWEIGHTMESSAGE:
    {
        InventoryWeightMessage message;
        message.deserialize(&reader);
        m_botData[sender].playerData.stats.pods.current = message.weight;
        m_botData[sender].playerData.stats.pods.max = message.weightMax;
    }
        break;

    case MessageEnum::INVENTORYCONTENTMESSAGE:
    {
        InventoryContentMessage message;
        message.deserialize(&reader);

        m_botData[sender].playerData.kamas = message.kamas;

        if (!message.objects.isEmpty())
        {
            m_botData[sender].playerData.inventoryContent.clear();

            for(int i = 0; i < message.objects.size(); i++)
            {
                InventoryObject item;
                item.GID = message.objects[i]->objectGID;
                item.UID = message.objects[i]->objectUID;
                item.quantity = message.objects[i]->quantity;
                item.position = (CharacterInventoryPositionEnum)message.objects[i]->position;
                if (m_inventoryPositions.contains(item.position))
                    item.isEquipped = true;

                for (int j = 0; j < message.objects[i]->effects.size(); j++)
                    for (int k = 0; k < message.objects[i]->effects[j]->getTypes().size(); k++)
                        if ((int)message.objects[i]->effects[j]->getTypes()[k] == 70 &&
                                qSharedPointerCast<EffectData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::EFFECTS, message.objects[i]->effects[j]->actionId))->getCharacteristic() == 0)
                            item.regenLife = qSharedPointerCast<ObjectEffectInteger>(message.objects[i]->effects[j])->value;

                m_botData[sender].playerData.inventoryContent<<item;

                PetFeedInfos pet;
                pet.GID = message.objects[i]->objectGID;

                if (m_pets.keys().contains(message.objects[i]->objectGID) && !m_botData[sender].interactionData.petData.petInfos.contains(pet))
                {
                    PetFeedInfos p;
                    p.GID = message.objects[i]->objectGID;
                    p.UID = message.objects[i]->objectUID;
                    p.name = m_pets[message.objects[i]->objectGID];
                    m_botData[sender].interactionData.petData.petInfos << p;
                }
            }

            healEat(sender);
        }

        else
            qDebug()<<"StatsModule - Le personnage ne possède pas d'objets dans son inventaire.";
    }
        break;

    case MessageEnum::INVENTORYCONTENTANDPRESETMESSAGE:
    {
        InventoryContentAndPresetMessage message;
        message.deserialize(&reader);

        m_botData[sender].playerData.kamas = message.kamas;
        m_botData[sender].playerData.inventoryContent.clear();

        for(int i = 0; i < message.objects.size(); i++)
        {
            InventoryObject item;
            item.GID = message.objects[i]->objectGID;
            item.UID = message.objects[i]->objectUID;
            item.quantity = message.objects[i]->quantity;
            if (m_inventoryPositions.contains(item.position))
                item.isEquipped = true;

            for (int j = 0; j < message.objects[i]->effects.size(); j++)
                for (int k = 0; k < message.objects[i]->effects[j]->getTypes().size(); k++)
                    if ((int)message.objects[i]->effects[j]->getTypes()[k] == 70 &&
                            qSharedPointerCast<EffectData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::EFFECTS, message.objects[i]->effects[j]->actionId))->getCharacteristic() == 0)
                        item.regenLife = qSharedPointerCast<ObjectEffectInteger>(message.objects[i]->effects[j])->value;

            m_botData[sender].playerData.inventoryContent<<item;

            if (m_pets.contains(message.objects[i]->objectGID))
                qDebug() << "pet" << qSharedPointerCast<ItemData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, message.objects[i]->objectGID))->getName();

            PetFeedInfos pet;
            pet.GID = message.objects[i]->objectGID;

            if (m_pets.keys().contains(message.objects[i]->objectGID) && !m_botData[sender].interactionData.petData.petInfos.contains(pet))
            {
                PetFeedInfos p;
                p.GID = message.objects[i]->objectGID;
                p.UID = message.objects[i]->objectUID;
                p.name = m_pets[message.objects[i]->objectGID];
                m_botData[sender].interactionData.petData.petInfos << p;
            }
        }

        healEat(sender);
    }
        break;

    case MessageEnum::OBJECTMOVEMENTMESSAGE:
    {
        ObjectMovementMessage message;
        message.deserialize(&reader);

        for (int i = 0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if (m_botData[sender].playerData.inventoryContent[i].UID == message.objectUID)
            {
                m_botData[sender].playerData.inventoryContent[i].position = (CharacterInventoryPositionEnum)message.position;
                if (m_inventoryPositions.contains((CharacterInventoryPositionEnum)message.position))
                    m_botData[sender].playerData.inventoryContent[i].isEquipped = true;
                else
                    m_botData[sender].playerData.inventoryContent[i].isEquipped = false;

                qDebug() << "Equip test:" << m_botData[sender].playerData.inventoryContent[i].isEquipped << message.position
                         << m_inventoryPositions.contains((CharacterInventoryPositionEnum)message.position);
            }
        }
    }
        break;

    case MessageEnum::ACHIEVEMENTFINISHEDMESSAGE:
    {
        qDebug() << "New achievement!";
        AchievementFinishedMessage message;
        message.deserialize(&reader);

        AchievementRewardRequestMessage answer;
        answer.achievementId = qSharedPointerCast<AchievementRewardData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ACHIEVEMENTREWARDS, message.id))->getAchievementId();
        sender->send(answer);
    }
        break;

    case MessageEnum::GAMEROLEPLAYPLAYERLIFESTATUSMESSAGE:
    {
        GameRolePlayPlayerLifeStatusMessage message;
        message.deserialize(&reader);

        m_botData[sender].playerData.lifeStatus = (PlayerLifeStatusEnum)message.state;

        if(m_botData[sender].playerData.lifeStatus == PlayerLifeStatusEnum::STATUS_TOMBSTONE)
            freeSoul(sender);

        else if(m_botData[sender].playerData.isRequestingFreeSoul &&
                m_botData[sender].playerData.hasSentRequestFreeSoul)
        {
            m_botData[sender].playerData.isRequestingFreeSoul = false;
            m_botData[sender].playerData.hasSentRequestFreeSoul = false;
        }

        if(m_botData[sender].scriptData.activeModule == getType())
            emit scriptActionDone(sender);
    }
        break;

    case MessageEnum::CHARACTERSTATSLISTMESSAGE:
    {
        CharacterStatsListMessage message;
        message.deserialize(&reader);
        Stats temp;
        temp.spellsPoints = message.stats.spellsPoints;
        temp.lifePoints = message.stats.lifePoints;
        temp.maxLifePoints = message.stats.maxLifePoints;
        temp.energyPoints = message.stats.energyPoints;
        temp.maxEnergyPoints = message.stats.maxEnergyPoints;
        temp.actionPointsCurrent = message.stats.actionPointsCurrent;
        temp.movementPointsCurrent = message.stats.movementPointsCurrent;
        temp.initiative = message.stats.initiative;
        temp.prospecting = message.stats.prospecting;
        temp.actionPoints = message.stats.actionPoints;
        temp.movementPoints = message.stats.movementPoints;
        temp.strength = message.stats.strength;
        temp.vitality = message.stats.vitality;
        temp.wisdom = message.stats.wisdom;
        temp.chance = message.stats.chance;
        temp.agility = message.stats.agility;
        temp.intelligence = message.stats.intelligence;
        temp.range = message.stats.range;
        temp.summonableCreaturesBoost = message.stats.summonableCreaturesBoost;
        temp.reflect = message.stats.reflect;
        temp.criticalHit = message.stats.criticalHit;
        temp.criticalHitWeapon = message.stats.criticalHitWeapon;
        temp.criticalMiss = message.stats.criticalMiss;
        temp.healBonus = message.stats.healBonus;
        temp.allDamagesBonus = message.stats.allDamagesBonus;
        temp.weaponDamagesBonusPercent = message.stats.weaponDamagesBonusPercent;
        temp.damagesBonusPercent = message.stats.damagesBonusPercent;
        temp.trapBonus = message.stats.trapBonus;
        temp.glyphBonusPercent = message.stats.glyphBonusPercent;
        temp.trapBonusPercent = message.stats.trapBonusPercent;
        temp.permanentDamagePercent = message.stats.permanentDamagePercent;
        temp.tackleBlock = message.stats.tackleBlock;
        temp.tackleEvade = message.stats.tackleEvade;
        temp.PAAttack = message.stats.PAAttack;
        temp.PMAttack = message.stats.PMAttack;
        temp.pushDamageBonus = message.stats.pushDamageBonus;
        temp.criticalDamageBonus = message.stats.criticalDamageBonus;
        temp.neutralDamageBonus = message.stats.neutralDamageBonus;
        temp.earthDamageBonus = message.stats.earthDamageBonus;
        temp.waterDamageBonus = message.stats.waterDamageBonus;
        temp.airDamageBonus = message.stats.airDamageBonus;
        temp.fireDamageBonus = message.stats.fireDamageBonus;
        temp.dodgePALostProbability = message.stats.dodgePALostProbability;
        temp.dodgePMLostProbability = message.stats.dodgePMLostProbability;
        temp.neutralElementResistPercent = message.stats.neutralElementResistPercent;
        temp.earthElementResistPercent = message.stats.earthElementResistPercent;
        temp.waterElementResistPercent = message.stats.waterElementResistPercent;
        temp.airElementResistPercent = message.stats.airElementResistPercent;
        temp.fireElementResistPercent = message.stats.fireElementResistPercent;
        temp.neutralElementReduction = message.stats.neutralElementReduction;
        temp.earthElementReduction = message.stats.earthElementReduction;
        temp.waterElementReduction = message.stats.waterElementReduction;
        temp.airElementReduction = message.stats.airElementReduction;
        temp.fireElementReduction = message.stats.fireElementReduction;
        temp.pushDamageReduction = message.stats.pushDamageReduction;
        temp.criticalDamageReduction = message.stats.criticalDamageReduction;
        temp.pvpNeutralElementResistPercent = message.stats.pvpNeutralElementResistPercent;
        temp.pvpEarthElementResistPercent = message.stats.pvpEarthElementResistPercent;
        temp.pvpWaterElementResistPercent = message.stats.pvpWaterElementResistPercent;
        temp.pvpAirElementResistPercent = message.stats.pvpAirElementResistPercent;
        temp.pvpFireElementResistPercent = message.stats.pvpFireElementResistPercent;
        temp.pvpNeutralElementReduction = message.stats.pvpNeutralElementReduction;
        temp.pvpEarthElementReduction = message.stats.pvpEarthElementReduction;
        temp.pvpWaterElementReduction = message.stats.pvpWaterElementReduction;
        temp.pvpAirElementReduction = message.stats.pvpAirElementReduction;
        temp.pvpFireElementReduction = message.stats.pvpFireElementReduction;
        temp.experience = message.stats.experience;
        temp.experienceLevelFloor = message.stats.experienceLevelFloor;
        temp.experienceNextLevelFloor = message.stats.experienceNextLevelFloor;
        temp.spellsPoints = message.stats.spellsPoints;
        temp.statsPoints = message.stats.statsPoints;

        if (temp.pods.max == 0)
            temp.pods = m_botData[sender].playerData.stats.pods;

        m_botData[sender].playerData.stats = temp;
        m_botData[sender].playerData.kamas = message.stats.kamas;

        updateRequiredStats(sender);

        if (m_botData[sender].generalData.botState == BotState::REGENERATING_STATE)
            regenOptimizer(sender);
    }
        break;

    case MessageEnum::UPDATELIFEPOINTSMESSAGE:
    {
        UpdateLifePointsMessage message;
        message.deserialize(&reader);
        m_botData[sender].playerData.stats.lifePoints = message.lifePoints;
        m_botData[sender].playerData.stats.maxLifePoints = message.maxLifePoints;
    }
        break;

    case MessageEnum::STATSUPGRADERESULTMESSAGE:
        updateRequiredStats(sender);
        break;

    case MessageEnum::OBJECTQUANTITYMESSAGE:
    {
        ObjectQuantityMessage message;
        message.deserialize(&reader);

        int size = m_botData[sender].playerData.inventoryContent.size();
        for (int i = 0; i < size; i++)
        {
            if (m_botData[sender].playerData.inventoryContent[i].UID == message.objectUID)
            {
                m_botData[sender].playerData.inventoryContent[i].quantity = message.quantity;
                if (m_botData[sender].farmData.resourcesToDelete.contains(m_botData[sender].playerData.inventoryContent[i].GID))
                {
                    ObjectDeleteMessage reply;
                    reply.objectUID = m_botData[sender].playerData.inventoryContent[i].UID;
                    reply.quantity = m_botData[sender].playerData.inventoryContent[i].quantity;
                    sender->send(reply);
                }

                break;
            }
        }
    }
        break;

    case MessageEnum::OBJECTDELETEDMESSAGE:
    {
        ObjectDeletedMessage message;
        message.deserialize(&reader);

        int size = m_botData[sender].playerData.inventoryContent.size();

        for(int i = 0; i < size; i++)
        {
            if(m_botData[sender].playerData.inventoryContent[i].UID == message.objectUID)
            {
                m_botData[sender].playerData.inventoryContent.removeAt(i);
                break;
            }
        }
    }
        break;

    case MessageEnum::OBJECTADDEDMESSAGE:
    {
        ObjectAddedMessage message;
        message.deserialize(&reader);

        InventoryObject item;
        item.GID = message.object->objectGID;
        item.UID = message.object->objectUID;
        item.quantity = message.object->quantity;

        for (int i = 0; i < message.object->effects.size(); i++)
            for (int j = 0; j < message.object->effects[i]->getTypes().size(); j++)
                if ((int)message.object->effects[i]->getTypes()[j] == 70 &&
                        qSharedPointerCast<EffectData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::EFFECTS, message.object->effects[i]->actionId))->getCharacteristic() == 0)
                    item.regenLife = qSharedPointerCast<ObjectEffectInteger>(message.object->effects[i])->value;

        m_botData[sender].playerData.inventoryContent<<item;
        if (m_botData[sender].playerData.resourceMonitor.keys().contains(message.object->objectGID))
            m_botData[sender].playerData.resourceMonitor[message.object->objectGID] += message.object->quantity;

        if (m_botData[sender].farmData.resourcesToDelete.contains(item.GID))
        {
            ObjectDeleteMessage reply;
            reply.objectUID = item.UID;
            reply.quantity = item.quantity;
            sender->send(reply);
        }
    }
        break;

    case MessageEnum::MOUNTRIDINGMESSAGE:
    {
        MountRidingMessage message;
        message.deserialize(&reader);

        m_botData[sender].playerData.isRiding = message.isRiding;
    }
        break;

    case MessageEnum::LIFEPOINTSREGENBEGINMESSAGE:
    {
        LifePointsRegenBeginMessage message;
        message.deserialize(&reader);

        QMutableListIterator<LifeRegenQueue> i(m_passiveRegen);
        while (i.hasNext())
            if (i.next().sender == sender)
                i.remove();

        LifeRegenQueue queue;
        queue.sender = sender;
        queue.timer = new QTimer(this);
        m_botData[sender].playerData.regenRate = message.regenRate/10;

        QObject::connect(queue.timer, SIGNAL(timeout()), this, SLOT(passiveHealing()));
        queue.timer->setSingleShot(false);
        queue.timer->setInterval(1000);
        queue.timer->start();
        m_passiveRegen << queue;

        if (m_botData[sender].generalData.botState == BotState::REGENERATING_STATE)
        {
            double p = (double)m_botData[sender].playerData.healPercentage/100.0;
            int max = m_botData[sender].playerData.stats.maxLifePoints;
            int life = m_botData[sender].playerData.stats.lifePoints;

            if (p*max >= life)
            {
                m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;

                emit healed(sender);

                if(m_botData[sender].scriptData.activeModule == getType())
                    emit scriptActionDone(sender);
            }

            else
            {
                LifeRegenQueue q;
                q.interval = ((p*max - life)/message.regenRate)*100;
                q.sender = sender;
                q.time.start();

                m_regenQueue << q;
                QTimer::singleShot(q.interval*1000, this, SLOT(healFinished()));
            }
        }
    }
        break;

    case MessageEnum::LIFEPOINTSREGENENDMESSAGE:
    {
        LifePointsRegenEndMessage message;
        message.deserialize(&reader);

        QMutableListIterator<LifeRegenQueue> i(m_passiveRegen);
        while (i.hasNext())
        {
            LifeRegenQueue q = i.next();
            if (q.sender == sender)
            {
                QObject::disconnect(q.timer, SIGNAL(timeout()), this, SLOT(passiveHealing()));
                q.timer->stop();
                delete q.timer;
                i.remove();
            }
        }

        info(sender) << "Vous avez récupéré" << message.lifePointsGained << "points de vie.";
    }
        break;
    }

    return messageFound;
}

void StatsModule::increaseStat(SocketIO *sender, PlayerFields stat)
{
    StatsUpgradeRequestMessage message;
    message.useAdditionnal = false;
    message.statId = (uint)stat;

    switch(stat)
    {
    case PlayerFields::AGILITY:
        message.boostPoint = m_botData[sender].playerData.stats.statsRequiredAgility;
        break;

    case PlayerFields::STRENGTH:
        message.boostPoint = m_botData[sender].playerData.stats.statsRequiredStrength;
        break;

    case PlayerFields::INTELLIGENCE:
        message.boostPoint = m_botData[sender].playerData.stats.statsRequiredIntelligence;
        break;

    case PlayerFields::CHANCE:
        message.boostPoint = m_botData[sender].playerData.stats.statsRequiredChance;
        break;

    case PlayerFields::WISDOM:
        message.boostPoint = m_botData[sender].playerData.stats.statsRequiredWisdom;
        break;

    case PlayerFields::VITALITY:
        message.boostPoint = m_botData[sender].playerData.stats.statsRequiredVitality;
        break;
    }

    m_botData[sender].playerData.increaseStatId = (uint)stat;
    sender->send(message);
}

void StatsModule::increaseSpell(SocketIO *sender, int spellID)
{
    SpellModifyRequestMessage answer;
    answer.spellId = spellID;
    answer.spellLevel = m_botData[sender].playerData.spells[spellID].spellLevel+1;

    sender->send(answer);
}

void StatsModule::updateRequiredStats(SocketIO *sender)
{
    QSharedPointer<BreedData> breed = qSharedPointerCast<BreedData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::BREEDS, (int)m_botData[sender].playerData.breed));

    for(int i = 0; i < breed->getStatsPointsForVitality().size(); i++)
    {
        if(m_botData[sender].playerData.stats.vitality.base < breed->getStatsPointsForVitality()[i][0])
        {
            m_botData[sender].playerData.stats.statsRequiredVitality = breed->getStatsPointsForVitality()[i - 1][1];
            break;
        }

        else
            m_botData[sender].playerData.stats.statsRequiredVitality = breed->getStatsPointsForVitality()[i][1];
    }

    for(int i = 0; i < breed->getStatsPointsForWisdom().size(); i++)
    {
        if(m_botData[sender].playerData.stats.wisdom.base < breed->getStatsPointsForWisdom()[i][0])
        {
            m_botData[sender].playerData.stats.statsRequiredWisdom = breed->getStatsPointsForWisdom()[i - 1][1];
            break;
        }

        else
            m_botData[sender].playerData.stats.statsRequiredWisdom = breed->getStatsPointsForWisdom()[i][1];
    }

    for(int i = 0; i < breed->getStatsPointsForStrength().size(); i++)
    {
        if(m_botData[sender].playerData.stats.strength.base < breed->getStatsPointsForStrength()[i][0])
        {
            m_botData[sender].playerData.stats.statsRequiredStrength = breed->getStatsPointsForStrength()[i - 1][1];
            break;
        }

        else
            m_botData[sender].playerData.stats.statsRequiredStrength = breed->getStatsPointsForStrength()[i][1];
    }

    for(int i = 0; i < breed->getStatsPointsForIntelligence().size(); i++)
    {
        if(m_botData[sender].playerData.stats.intelligence.base < breed->getStatsPointsForIntelligence()[i][0])
        {
            m_botData[sender].playerData.stats.statsRequiredIntelligence = breed->getStatsPointsForIntelligence()[i - 1][1];
            break;
        }

        else
            m_botData[sender].playerData.stats.statsRequiredIntelligence = breed->getStatsPointsForIntelligence()[i][1];
    }

    for(int i = 0; i < breed->getStatsPointsForChance().size(); i++)
    {
        if(m_botData[sender].playerData.stats.chance.base < breed->getStatsPointsForChance()[i][0])
        {
            m_botData[sender].playerData.stats.statsRequiredChance = breed->getStatsPointsForChance()[i - 1][1];
            break;
        }

        else
            m_botData[sender].playerData.stats.statsRequiredChance = breed->getStatsPointsForChance()[i][1];
    }

    for(int i = 0; i < breed->getStatsPointsForAgility().size(); i++)
    {
        if(m_botData[sender].playerData.stats.agility.base < breed->getStatsPointsForAgility()[i][0])
        {
            m_botData[sender].playerData.stats.statsRequiredAgility = breed->getStatsPointsForAgility()[i - 1][1];
            break;
        }

        else
            m_botData[sender].playerData.stats.statsRequiredAgility = breed->getStatsPointsForAgility()[i][1];
    }
}

void StatsModule::destroyItem(SocketIO *sender, uint uid, uint quantity)
{
    ObjectDeleteMessage message;
    foreach (InventoryObject item, m_botData[sender].playerData.inventoryContent)
    {
        if (item.UID == uid)
        {
            message.objectUID = item.UID;
            message.quantity = std::min(quantity, (uint)item.quantity);

            sender->send(message);
            return;
        }
    }
}

void StatsModule::useItem(SocketIO *sender, uint uid)
{
    ObjectUseMessage message;
    message.objectUID = uid;
    sender->send(message);

    qDebug() << "USE ITEM" << uid;
}

void StatsModule::freeSoul(SocketIO *sender)
{
    if(m_botData[sender].playerData.lifeStatus == PlayerLifeStatusEnum::STATUS_TOMBSTONE)
    {
        m_botData[sender].playerData.isRequestingFreeSoul = true;
        m_botData[sender].playerData.hasSentRequestFreeSoul = false;

        if(m_botData[sender].mapData.map.isInit() && m_botData[sender].generalData.botState == INACTIVE_STATE && !m_botData[sender].playerData.hasSentRequestFreeSoul)
        {
            m_botData[sender].playerData.hasSentRequestFreeSoul = true;

            GameRolePlayFreeSoulRequestMessage request;
            sender->send(request);
        }
    }
}

QString StatsModule::getMountEffects(SocketIO *sender)
{
    QString t;
    for (int i = 0; i < m_botData[sender].playerData.mountData.effects.size(); i++)
        t.append(m_botData[sender].playerData.mountData.effects.at(i) + QString('\n'));

    t.remove(t.size() - 1);
    return t;
}

void StatsModule::updateMountXpRatio(SocketIO *sender, uint ratio)
{
    MountSetXpRatioRequestMessage message;
    message.xpRatio = ratio;

    sender->send(message);
}

bool StatsModule::healSit(SocketIO* sender)
{
    if (m_botData[sender].generalData.botState != BotState::INACTIVE_STATE &&
            m_botData[sender].generalData.botState != BotState::REGENERATING_STATE)
        return false;

    EmotePlayRequestMessage message;
    message.emoteId = 1;
    sender->send(message);

    m_botData[sender].generalData.botState = BotState::REGENERATING_STATE;
    return true;
}

bool StatsModule::healEat(SocketIO* sender)
{   
    if (m_botData[sender].generalData.botState != BotState::INACTIVE_STATE)
        return false;

    QList<InventoryObject> regenItems;
    foreach (InventoryObject o, m_botData[sender].playerData.inventoryContent)
        if (o.regenLife &&
                qSharedPointerCast<ItemData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, o.GID))->getUsable() &&
                qSharedPointerCast<ItemData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, o.GID))->getTargetable())
            regenItems << o;

    if (regenItems.isEmpty())
    {
        info(sender) << "Le bot n'a plus d'objets consommables pour se régénérer: début de la régénération assise";
        return false;
    }

    std::sort(regenItems.begin(), regenItems.end());
    std::reverse(regenItems.begin(), regenItems.end());
    m_botData[sender].playerData.healInventory.clear();
    m_botData[sender].playerData.healInventory = regenItems;

    return true;
}

bool StatsModule::needsHeal(SocketIO *sender)
{
    float ratio = (float)m_botData[sender].playerData.stats.lifePoints/(float)m_botData[sender].playerData.stats.maxLifePoints;

    if(ratio <= m_botData[sender].playerData.minRegenRatio)
        return true;

    return false;
}

bool StatsModule::needsToGoToPhoenix(SocketIO *sender)
{
    if(m_botData[sender].playerData.lifeStatus == PlayerLifeStatusEnum::STATUS_ALIVE_AND_KICKING)
        return false;

    return true;
}

bool StatsModule::needsToGoToBank(SocketIO *sender)
{
    float ratio = (float)m_botData[sender].playerData.stats.pods.current/(float)m_botData[sender].playerData.stats.pods.max*100;

    if(ratio >= m_botData[sender].scriptData.podsLimitRatio)
        return true;

    return false;
}

void StatsModule::setRegenerationRatio(SocketIO *sender, uint min, uint max)
{
    m_botData[sender].playerData.minRegenRatio = min;
    m_botData[sender].playerData.maxRegenRatio = max;
}

void StatsModule::setRegenUseObjectsEnabled(SocketIO *sender, bool enabled)
{
    m_botData[sender].playerData.regenUseObjects = enabled;
}

void StatsModule::regenOptimizer(SocketIO *sender)
{
    int life = m_botData[sender].playerData.stats.lifePoints;
    int maxLife = m_botData[sender].playerData.stats.maxLifePoints;
    double p = (double)m_botData[sender].playerData.healPercentage/100.0;

    int wanted = p*maxLife;
    int diff = maxLife - life;

    QMutableListIterator<LifeRegenQueue> i(m_preventRegenBlocked);
    while (i.hasNext())
        if (i.next().sender == sender)
            i.remove();

    if (life >= wanted ||
            !(m_botData[sender].generalData.botState == BotState::INACTIVE_STATE ||
              m_botData[sender].generalData.botState == BotState::REGENERATING_STATE))
    {
        m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
        m_botData[sender].playerData.healInventory.clear();

        emit healed(sender);

        if(m_botData[sender].scriptData.activeModule == getType())
            emit scriptActionDone(sender);

        return;
    }

    if (m_botData[sender].playerData.healInventory.isEmpty())
    {
        info(sender) << "Le bot n'a plus d'objets consommables pour se régénérer: début de la régénération assise";
        m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
        m_botData[sender].playerData.healInventory.clear();
        healSit(sender);
        return;
    }

    bool hasEaten = false;
    m_botData[sender].generalData.botState = BotState::REGENERATING_STATE;
    for (int i = 0; i < m_botData[sender].playerData.healInventory.size(); i++)
    {
        if (diff >= m_botData[sender].playerData.healInventory[i].regenLife)
        {
            hasEaten = true;
            ObjectUseMessage message;
            message.objectUID = m_botData[sender].playerData.healInventory[i].UID;

            m_botData[sender].playerData.healInventory[i].quantity -= 1;
            if (m_botData[sender].playerData.healInventory[i].quantity <= 0)
                m_botData[sender].playerData.healInventory.removeAt(i);

            break;
        }
    }

    if (!hasEaten && (diff > 50))
    {
        ObjectUseMessage message;
        message.objectUID = m_botData[sender].playerData.healInventory.last().UID;

        m_botData[sender].playerData.healInventory.last().quantity -= 1;
        if (m_botData[sender].playerData.healInventory.last().quantity <= 0)
            m_botData[sender].playerData.healInventory.removeLast();
    }
    else if (!hasEaten && (diff <= 50))
    {
        healSit(sender);
        return;
    }

    LifeRegenQueue queue;
    queue.time.start();
    queue.sender = sender;
    queue.interval = 30000;

    m_preventRegenBlocked << queue;
    QTimer::singleShot(30000, this, SLOT(preventRegenBlocked()));
}

void StatsModule::healFinished()
{
    int index;
    int min = 1000000;
    SocketIO* sender = NULL;
    for (int i = 0; i < m_regenQueue.size(); i++)
    {
        if ((m_regenQueue[i].time.elapsed() - m_regenQueue[i].interval) < min)
        {
            min = m_regenQueue[i].time.elapsed() - m_regenQueue[i].interval;
            sender = m_regenQueue[i].sender;
            index = i;
        }
    }

    if (!sender)
        return;

    m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
    m_botData[sender].playerData.healInventory.clear();
    m_regenQueue.removeAt(index);

    emit healed(sender);

    if(m_botData[sender].scriptData.activeModule == getType())
        emit scriptActionDone(sender);
}

void StatsModule::preventRegenBlocked()
{
    QMutableListIterator<LifeRegenQueue> i(m_preventRegenBlocked);
    while (i.hasNext())
    {
        LifeRegenQueue q = i.next();
        if (q.time.elapsed() >= 30000)
        {
            alert(q.sender) << "La régénération du bot était bloquée, reset du module des caractéristiques";
            m_botData[q.sender].generalData.botState = BotState::INACTIVE_STATE;
            m_botData[q.sender].playerData.healInventory.clear();

            emit healed(q.sender);

            if(m_botData[q.sender].scriptData.activeModule == getType())
                emit scriptActionDone(q.sender);

            i.remove();
        }
    }
}

void StatsModule::passiveHealing()
{
    int index;
    SocketIO *sender;
    QTimer *timer = static_cast<QTimer*>(QObject::sender());
    for (int i = 0; i < m_passiveRegen.size(); i++)
    {
        if (m_passiveRegen[i].timer == timer)
        {
            index = i;
            sender = m_passiveRegen[i].sender;
        }
    }

    if (m_passiveRegen.isEmpty() || (m_botData[sender].connectionData.connectionState == ConnectionState::DISCONNECTED))
    {
        QObject::disconnect(timer, SIGNAL(timeout()), this, SLOT(passiveHealing()));
        delete m_passiveRegen[index].timer;
        m_passiveRegen.removeAt(index);
    }

    int life = m_botData[sender].playerData.stats.lifePoints + m_botData[sender].playerData.regenRate;
    m_botData[sender].playerData.stats.lifePoints = (life >= m_botData[sender].playerData.stats.maxLifePoints) ? m_botData[sender].playerData.stats.maxLifePoints : life;
}

bool StatsModule::canEquipItem(uint gid)
{
    QList<SuperTypeId> l;
    l << SuperTypeId::AMULET << SuperTypeId::BELT << SuperTypeId::BOOTS
      << SuperTypeId::COMPANION << SuperTypeId::DOFUS << SuperTypeId::HAT
      << SuperTypeId::PETS_OR_MOUNT << SuperTypeId::RING << SuperTypeId::SHIELD
      << SuperTypeId::WEAPON;

    SuperTypeId s = (SuperTypeId)qSharedPointerCast<ItemTypeData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMTYPES,
                                                                                                        D2OManagerSingleton::get()->getItem(gid)->getTypeId()))->getSuperTypeId();

    if (l.contains(s))
        return true;
    return false;
}

void StatsModule::equipItem(SocketIO *sender, uint uid)
{
    InventoryObject e;
    foreach (InventoryObject o, m_botData[sender].playerData.inventoryContent)
        if (o.UID == uid)
            e = o;

    qDebug() << "Equip Item" << uid << e.GID << e.isEquipped;
    if (e.isEquipped)
        return;

    SuperTypeId s = (SuperTypeId)qSharedPointerCast<ItemTypeData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMTYPES,
                                                                                                        D2OManagerSingleton::get()->getItem(e.GID)->getTypeId()))->getSuperTypeId();
    CharacterInventoryPositionEnum p = CharacterInventoryPositionEnum::INVENTORY_POSITION_NOT_EQUIPED;

    switch (s)
    {
    case SuperTypeId::AMULET:
        p = CharacterInventoryPositionEnum::ACCESSORY_POSITION_AMULET;
        break;

    case SuperTypeId::BELT:
        p = CharacterInventoryPositionEnum::ACCESSORY_POSITION_BELT;
        break;

    case SuperTypeId::BOOTS:
        p = CharacterInventoryPositionEnum::ACCESSORY_POSITION_BOOTS;
        break;

    case SuperTypeId::COMPANION:
        p = CharacterInventoryPositionEnum::INVENTORY_POSITION_COMPANION;
        break;

    case SuperTypeId::HAT:
        p = CharacterInventoryPositionEnum::ACCESSORY_POSITION_HAT;
        break;

    case SuperTypeId::PETS_OR_MOUNT:
        p = CharacterInventoryPositionEnum::ACCESSORY_POSITION_PETS;
        break;

    case SuperTypeId::SHIELD:
        p = CharacterInventoryPositionEnum::ACCESSORY_POSITION_SHIELD;
        break;

    case SuperTypeId::WEAPON:
        p = CharacterInventoryPositionEnum::ACCESSORY_POSITION_WEAPON;
        break;

    case SuperTypeId::RING:
    {
        if (m_botData[sender].playerData.ring)
            p = CharacterInventoryPositionEnum::INVENTORY_POSITION_RING_LEFT;
        else
            p = CharacterInventoryPositionEnum::INVENTORY_POSITION_RING_RIGHT;

        m_botData[sender].playerData.ring = !m_botData[sender].playerData.ring;
    }
        break;

    case SuperTypeId::DOFUS:
    {
        if (m_botData[sender].playerData.dofus == 0)
            p = CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_1;
        else if (m_botData[sender].playerData.dofus == 1)
            p = CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_2;
        else if (m_botData[sender].playerData.dofus == 2)
            p = CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_3;
        else if (m_botData[sender].playerData.dofus == 3)
            p = CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_4;
        else if (m_botData[sender].playerData.dofus == 4)
            p = CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_5;
        else if (m_botData[sender].playerData.dofus == 5)
            p = CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_6;
        else
            p = CharacterInventoryPositionEnum::INVENTORY_POSITION_NOT_EQUIPED;

        m_botData[sender].playerData.dofus = (m_botData[sender].playerData.dofus + 1) % 6;
    }
        break;

    default:
        p = CharacterInventoryPositionEnum::INVENTORY_POSITION_NOT_EQUIPED;
        break;

    }

    ObjectSetPositionMessage m;
    m.objectUID = uid;
    m.quantity = 1;
    m.position = (int)p;
    sender->send(m);
}

void StatsModule::unequipItem(SocketIO *sender, uint uid)
{
    InventoryObject e;
    foreach (InventoryObject o, m_botData[sender].playerData.inventoryContent)
        if (o.UID == uid)
            e = o;

    if (e.isEquipped)
    {
        ObjectSetPositionMessage m;
        m.objectUID = uid;
        m.quantity = 1;
        m.position = (int)CharacterInventoryPositionEnum::INVENTORY_POSITION_NOT_EQUIPED;
        sender->send(m);
    }
}
