#include "ParamsDecoder.h"

QString ParamsDecoder::decodeParams(QString message, QStringList parameters, QString paramPrefix)
{
    QChar _loc10_;
    bool _loc4_ = false;
    bool _loc5_= false;
    QString _loc6_;
    QString _loc7_;
    QString _loc8_;

    for(int i = 0; i < message.size(); i++)
    {
        _loc10_ = message.at(i);

        if(_loc10_ == '$')
            _loc4_ = true;

        else if(_loc10_ == paramPrefix)
        {
            if(i + 1 < message.size() && message.at(i+1) == paramPrefix)
            {
                _loc5_ = false;
                _loc4_ = false;
                i++;
            }

            else
            {
                _loc4_ = false;
                _loc5_ = true;
            }
        }

        if(_loc4_)
            _loc6_ += _loc10_;

        else if(_loc5_)
        {
            if(_loc10_ == paramPrefix)
            {
                if(!_loc7_.isEmpty())
                {
                    _loc8_ += processReplace(_loc6_,_loc7_,parameters);
                    _loc6_.clear();
                    _loc7_ = _loc10_;
                }

                else
                    _loc7_ = _loc10_;

                _loc7_ = _loc10_;
            }

            else if(_loc10_.isDigit())
            {
                _loc7_ += _loc10_;

                if(i + 1 == message.size())
                {
                    _loc5_ = false;
                    _loc8_ = _loc8_ + processReplace(_loc6_,_loc7_,parameters);
                    _loc6_.clear();
                    _loc7_.clear();
                }
            }

            else
            {
                _loc5_ = false;
                _loc8_ = _loc8_ + processReplace(_loc6_,_loc7_,parameters);
                _loc6_.clear();
                _loc7_.clear();
                _loc8_ += _loc10_;
            }

        }

        else
        {
            if(!_loc7_.isEmpty())
            {   
                _loc8_ = _loc8_ + processReplace(_loc6_,_loc7_,parameters);
                _loc6_.clear();
                _loc7_.clear();
            }

            _loc8_ = _loc8_ + _loc10_;
        }

    }

    return _loc8_;
}

QString ParamsDecoder::processReplace(QString param1, QString paramIdentifier, QStringList param3)
{
    int _loc5_ = 0;
    QString _loc4_;

    _loc5_ = toInt(paramIdentifier.mid(1)) -1;

    if(param1.isEmpty())
        _loc4_ = param3[_loc5_];

    else
    {
        if(param1 == "$item")
        {
            QSharedPointer<ItemData> item = qSharedPointerCast<ItemData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, toInt(param3[_loc5_])));
            _loc4_ =  item->getName();
        }

        else if(param1 == "$itemType")
        {
            QSharedPointer<ItemTypeData> itemType = qSharedPointerCast<ItemTypeData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMTYPES, toInt(param3[_loc5_])));
            _loc4_ = itemType->getName();
        }

        else if(param1 == "$quantity")
            _loc4_ = param3[_loc5_];

        else if(param1 == "$job")
        {
            QSharedPointer<JobData> job = qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, toInt(param3[_loc5_])));
            _loc4_ = job->getName();
        }

        else if(param1 == "$quest")
        {
            QSharedPointer<QuestData> quest = qSharedPointerCast<QuestData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::QUESTS, toInt(param3[_loc5_])));
            _loc4_ = quest->getName();
        }

        else if(param1 == "$achievement")
        {
            QSharedPointer<AchievementData> achievement = qSharedPointerCast<AchievementData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ACHIEVEMENTS, toInt(param3[_loc5_])));
            _loc4_ = achievement->getName();
        }

        else if(param1 == "$title")
        {
            QSharedPointer<TitleData> title = qSharedPointerCast<TitleData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::TITLES, toInt(param3[_loc5_])));
            if(!title->getNameFemale().isEmpty())
                _loc4_ = title->getNameFemale();

            else if(!title->getNameMale().isEmpty())
                _loc4_ = title->getNameMale();
        }

        else if(param1 == "$ornament")
        {
            QSharedPointer<OrnamentData> ornament = qSharedPointerCast<OrnamentData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ORNAMENTS, toInt(param3[_loc5_])));
            _loc4_ = ornament->getName();
        }

        else if(param1 == "$spell")
        {
            QSharedPointer<SpellData> spell = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, toInt(param3[_loc5_])));
            _loc4_ = spell->getName();
        }

        else if(param1 == "$spellState")
        {
            QSharedPointer<SpellStateData> spellState = qSharedPointerCast<SpellStateData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLSTATES, toInt(param3[_loc5_])));
            _loc4_ = spellState->getName();
        }

        else if(param1 == "$breed")
        {
            QSharedPointer<BreedData> breed = qSharedPointerCast<BreedData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::BREEDS, toInt(param3[_loc5_])));
            _loc4_ = breed->getShortName();
        }

        else if(param1 == "$area")
        {
            QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, toInt(param3[_loc5_])));
            _loc4_ = area->getName();
        }

        else if(param1 == "$subarea")
        {
            QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, toInt(param3[_loc5_])));
            _loc4_ = subArea->getName();
        }

        else if(param1 == "$map")
        {
            QSharedPointer<MapPositionData> map = qSharedPointerCast<MapPositionData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MAPPOSITIONS, toInt(param3[_loc5_])));
            _loc4_ = "["+QString::number(map->getPosX())+","+QString::number(map->getPosY())+"]";
        }

        else if(param1 == "$emote")
        {
            QSharedPointer<EmoticonData> emote = qSharedPointerCast<EmoticonData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::EMOTICONS, toInt(param3[_loc5_])));
            _loc4_ = emote->getName();
        }

        else if(param1 == "$monster")
        {
            QSharedPointer<MonsterData> monster = qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, toInt(param3[_loc5_])));
            _loc4_ = monster->getName();
        }

        else if(param1 == "$monsterRace")
        {
            QSharedPointer<MonsterRaceData> monsterRace = qSharedPointerCast<MonsterRaceData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERRACES, toInt(param3[_loc5_])));
            _loc4_ = monsterRace->getName();
        }

        else if(param1 == "$monsterSuperRace")
        {
            QSharedPointer<MonsterSuperRaceData> monsterSuperRace = qSharedPointerCast<MonsterSuperRaceData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERSUPERRACES, toInt(param3[_loc5_])));
            _loc4_ = monsterSuperRace->getName();
        }

        else if(param1 == "$challenge")
        {
            QSharedPointer<ChallengeData> challenge = qSharedPointerCast<ChallengeData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::CHALLENGE, toInt(param3[_loc5_])));
            _loc4_ = challenge->getName();
        }

        else if(param1 == "$alignment")
        {
            QSharedPointer<AlignmentSideData> alignmentSide = qSharedPointerCast<AlignmentSideData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ALIGNMENTSIDES, toInt(param3[_loc5_])));
            _loc4_ = alignmentSide->getName();
        }

        else if(param1 == "$stat")
          _loc4_ = D2OManagerSingleton::get()->m_I18n->getText("ui.item.characteristics").split(",")[param3[_loc5_].toInt()];

        else if(param1 == "$dungeon")
        {
            QSharedPointer<DungeonData> dungeon = qSharedPointerCast<DungeonData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::DUNGEONS, toInt(param3[_loc5_])));
            _loc4_ = dungeon->getName();
        }
    }

    return _loc4_;
}


