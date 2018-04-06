#include "CharacterCharacteristicsInformations.h"

void CharacterCharacteristicsInformations::serialize(Writer *param1)
{
  this->serializeAs_CharacterCharacteristicsInformations(param1);
}

void CharacterCharacteristicsInformations::serializeAs_CharacterCharacteristicsInformations(Writer *param1)
{
  if(this->experience < 0 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experience << ") on element experience.";
  }
  else
  {
    param1->writeVarLong((double)this->experience);
    if(this->experienceLevelFloor < 0 || this->experienceLevelFloor > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceLevelFloor << ") on element experienceLevelFloor.";
    }
    else
    {
      param1->writeVarLong((double)this->experienceLevelFloor);
      if(this->experienceNextLevelFloor < 0 || this->experienceNextLevelFloor > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceNextLevelFloor << ") on element experienceNextLevelFloor.";
      }
      else
      {
        param1->writeVarLong((double)this->experienceNextLevelFloor);
        if(this->experienceBonusLimit < 0 || this->experienceBonusLimit > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceBonusLimit << ") on element experienceBonusLimit.";
        }
        else
        {
          param1->writeVarLong((double)this->experienceBonusLimit);
          if(this->kamas < 0)
          {
            qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
          }
          else
          {
            param1->writeInt((int)this->kamas);
            if(this->statsPoints < 0)
            {
              qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->statsPoints << ") on element statsPoints.";
            }
            else
            {
              param1->writeVarShort((int)this->statsPoints);
              if(this->additionnalPoints < 0)
              {
                qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->additionnalPoints << ") on element additionnalPoints.";
              }
              else
              {
                param1->writeVarShort((int)this->additionnalPoints);
                if(this->spellsPoints < 0)
                {
                  qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->spellsPoints << ") on element spellsPoints.";
                }
                else
                {
                  param1->writeVarShort((int)this->spellsPoints);
                  this->alignmentInfos.serializeAs_ActorExtendedAlignmentInformations(param1);
                  if(this->lifePoints < 0)
                  {
                    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->lifePoints << ") on element lifePoints.";
                  }
                  else
                  {
                    param1->writeVarInt((int)this->lifePoints);
                    if(this->maxLifePoints < 0)
                    {
                      qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->maxLifePoints << ") on element maxLifePoints.";
                    }
                    else
                    {
                      param1->writeVarInt((int)this->maxLifePoints);
                      if(this->energyPoints < 0)
                      {
                        qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->energyPoints << ") on element energyPoints.";
                      }
                      else
                      {
                        param1->writeVarShort((int)this->energyPoints);
                        if(this->maxEnergyPoints < 0)
                        {
                          qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->maxEnergyPoints << ") on element maxEnergyPoints.";
                        }
                        else
                        {
                          param1->writeVarShort((int)this->maxEnergyPoints);
                          param1->writeVarShort((int)this->actionPointsCurrent);
                          param1->writeVarShort((int)this->movementPointsCurrent);
                          this->initiative.serializeAs_CharacterBaseCharacteristic(param1);
                          this->prospecting.serializeAs_CharacterBaseCharacteristic(param1);
                          this->actionPoints.serializeAs_CharacterBaseCharacteristic(param1);
                          this->movementPoints.serializeAs_CharacterBaseCharacteristic(param1);
                          this->strength.serializeAs_CharacterBaseCharacteristic(param1);
                          this->vitality.serializeAs_CharacterBaseCharacteristic(param1);
                          this->wisdom.serializeAs_CharacterBaseCharacteristic(param1);
                          this->chance.serializeAs_CharacterBaseCharacteristic(param1);
                          this->agility.serializeAs_CharacterBaseCharacteristic(param1);
                          this->intelligence.serializeAs_CharacterBaseCharacteristic(param1);
                          this->range.serializeAs_CharacterBaseCharacteristic(param1);
                          this->summonableCreaturesBoost.serializeAs_CharacterBaseCharacteristic(param1);
                          this->reflect.serializeAs_CharacterBaseCharacteristic(param1);
                          this->criticalHit.serializeAs_CharacterBaseCharacteristic(param1);
                          if(this->criticalHitWeapon < 0)
                          {
                            qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->criticalHitWeapon << ") on element criticalHitWeapon.";
                          }
                          else
                          {
                            param1->writeVarShort((int)this->criticalHitWeapon);
                            this->criticalMiss.serializeAs_CharacterBaseCharacteristic(param1);
                            this->healBonus.serializeAs_CharacterBaseCharacteristic(param1);
                            this->allDamagesBonus.serializeAs_CharacterBaseCharacteristic(param1);
                            this->weaponDamagesBonusPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->damagesBonusPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->trapBonus.serializeAs_CharacterBaseCharacteristic(param1);
                            this->trapBonusPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->glyphBonusPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->runeBonusPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->permanentDamagePercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->tackleBlock.serializeAs_CharacterBaseCharacteristic(param1);
                            this->tackleEvade.serializeAs_CharacterBaseCharacteristic(param1);
                            this->PAAttack.serializeAs_CharacterBaseCharacteristic(param1);
                            this->PMAttack.serializeAs_CharacterBaseCharacteristic(param1);
                            this->pushDamageBonus.serializeAs_CharacterBaseCharacteristic(param1);
                            this->criticalDamageBonus.serializeAs_CharacterBaseCharacteristic(param1);
                            this->neutralDamageBonus.serializeAs_CharacterBaseCharacteristic(param1);
                            this->earthDamageBonus.serializeAs_CharacterBaseCharacteristic(param1);
                            this->waterDamageBonus.serializeAs_CharacterBaseCharacteristic(param1);
                            this->airDamageBonus.serializeAs_CharacterBaseCharacteristic(param1);
                            this->fireDamageBonus.serializeAs_CharacterBaseCharacteristic(param1);
                            this->dodgePALostProbability.serializeAs_CharacterBaseCharacteristic(param1);
                            this->dodgePMLostProbability.serializeAs_CharacterBaseCharacteristic(param1);
                            this->neutralElementResistPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->earthElementResistPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->waterElementResistPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->airElementResistPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->fireElementResistPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->neutralElementReduction.serializeAs_CharacterBaseCharacteristic(param1);
                            this->earthElementReduction.serializeAs_CharacterBaseCharacteristic(param1);
                            this->waterElementReduction.serializeAs_CharacterBaseCharacteristic(param1);
                            this->airElementReduction.serializeAs_CharacterBaseCharacteristic(param1);
                            this->fireElementReduction.serializeAs_CharacterBaseCharacteristic(param1);
                            this->pushDamageReduction.serializeAs_CharacterBaseCharacteristic(param1);
                            this->criticalDamageReduction.serializeAs_CharacterBaseCharacteristic(param1);
                            this->pvpNeutralElementResistPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->pvpEarthElementResistPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->pvpWaterElementResistPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->pvpAirElementResistPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->pvpFireElementResistPercent.serializeAs_CharacterBaseCharacteristic(param1);
                            this->pvpNeutralElementReduction.serializeAs_CharacterBaseCharacteristic(param1);
                            this->pvpEarthElementReduction.serializeAs_CharacterBaseCharacteristic(param1);
                            this->pvpWaterElementReduction.serializeAs_CharacterBaseCharacteristic(param1);
                            this->pvpAirElementReduction.serializeAs_CharacterBaseCharacteristic(param1);
                            this->pvpFireElementReduction.serializeAs_CharacterBaseCharacteristic(param1);
                            param1->writeShort((short)this->spellModifications.size());
                            uint _loc2_ = 0;
                            while(_loc2_ < this->spellModifications.size())
                            {
                              (this->spellModifications[_loc2_]).serializeAs_CharacterSpellModification(param1);
                              _loc2_++;
                            }
                            if(this->probationTime < 0)
                            {
                              qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->probationTime << ") on element probationTime.";
                            }
                            else
                            {
                              param1->writeInt((int)this->probationTime);
                              return;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void CharacterCharacteristicsInformations::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterCharacteristicsInformations(param1);
}

void CharacterCharacteristicsInformations::deserializeAs_CharacterCharacteristicsInformations(Reader *param1)
{
  CharacterSpellModification _loc4_ ;
  this->experience = param1->readVarUhLong();
  if(this->experience < 0 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experience << ") on element of CharacterCharacteristicsInformations.experience.";
  }
  else
  {
    this->experienceLevelFloor = param1->readVarUhLong();
    if(this->experienceLevelFloor < 0 || this->experienceLevelFloor > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceLevelFloor << ") on element of CharacterCharacteristicsInformations.experienceLevelFloor.";
    }
    else
    {
      this->experienceNextLevelFloor = param1->readVarUhLong();
      if(this->experienceNextLevelFloor < 0 || this->experienceNextLevelFloor > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceNextLevelFloor << ") on element of CharacterCharacteristicsInformations.experienceNextLevelFloor.";
      }
      else
      {
        this->experienceBonusLimit = param1->readVarUhLong();
        if(this->experienceBonusLimit < 0 || this->experienceBonusLimit > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceBonusLimit << ") on element of CharacterCharacteristicsInformations.experienceBonusLimit.";
        }
        else
        {
          this->kamas = param1->readInt();
          if(this->kamas < 0)
          {
            qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->kamas << ") on element of CharacterCharacteristicsInformations.kamas.";
          }
          else
          {
            this->statsPoints = param1->readVarUhShort();
            if(this->statsPoints < 0)
            {
              qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->statsPoints << ") on element of CharacterCharacteristicsInformations.statsPoints.";
            }
            else
            {
              this->additionnalPoints = param1->readVarUhShort();
              if(this->additionnalPoints < 0)
              {
                qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->additionnalPoints << ") on element of CharacterCharacteristicsInformations.additionnalPoints.";
              }
              else
              {
                this->spellsPoints = param1->readVarUhShort();
                if(this->spellsPoints < 0)
                {
                  qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->spellsPoints << ") on element of CharacterCharacteristicsInformations.spellsPoints.";
                }
                else
                {
                  this->alignmentInfos = ActorExtendedAlignmentInformations();
                  this->alignmentInfos.deserialize(param1);
                  this->lifePoints = param1->readVarUhInt();
                  if(this->lifePoints < 0)
                  {
                    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->lifePoints << ") on element of CharacterCharacteristicsInformations.lifePoints.";
                  }
                  else
                  {
                    this->maxLifePoints = param1->readVarUhInt();
                    if(this->maxLifePoints < 0)
                    {
                      qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->maxLifePoints << ") on element of CharacterCharacteristicsInformations.maxLifePoints.";
                    }
                    else
                    {
                      this->energyPoints = param1->readVarUhShort();
                      if(this->energyPoints < 0)
                      {
                        qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->energyPoints << ") on element of CharacterCharacteristicsInformations.energyPoints.";
                      }
                      else
                      {
                        this->maxEnergyPoints = param1->readVarUhShort();
                        if(this->maxEnergyPoints < 0)
                        {
                          qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->maxEnergyPoints << ") on element of CharacterCharacteristicsInformations.maxEnergyPoints.";
                        }
                        else
                        {
                          this->actionPointsCurrent = param1->readVarShort();
                          this->movementPointsCurrent = param1->readVarShort();
                          this->initiative = CharacterBaseCharacteristic();
                          this->initiative.deserialize(param1);
                          this->prospecting = CharacterBaseCharacteristic();
                          this->prospecting.deserialize(param1);
                          this->actionPoints = CharacterBaseCharacteristic();
                          this->actionPoints.deserialize(param1);
                          this->movementPoints = CharacterBaseCharacteristic();
                          this->movementPoints.deserialize(param1);
                          this->strength = CharacterBaseCharacteristic();
                          this->strength.deserialize(param1);
                          this->vitality = CharacterBaseCharacteristic();
                          this->vitality.deserialize(param1);
                          this->wisdom = CharacterBaseCharacteristic();
                          this->wisdom.deserialize(param1);
                          this->chance = CharacterBaseCharacteristic();
                          this->chance.deserialize(param1);
                          this->agility = CharacterBaseCharacteristic();
                          this->agility.deserialize(param1);
                          this->intelligence = CharacterBaseCharacteristic();
                          this->intelligence.deserialize(param1);
                          this->range = CharacterBaseCharacteristic();
                          this->range.deserialize(param1);
                          this->summonableCreaturesBoost = CharacterBaseCharacteristic();
                          this->summonableCreaturesBoost.deserialize(param1);
                          this->reflect = CharacterBaseCharacteristic();
                          this->reflect.deserialize(param1);
                          this->criticalHit = CharacterBaseCharacteristic();
                          this->criticalHit.deserialize(param1);
                          this->criticalHitWeapon = param1->readVarUhShort();
                          if(this->criticalHitWeapon < 0)
                          {
                            qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->criticalHitWeapon << ") on element of CharacterCharacteristicsInformations.criticalHitWeapon.";
                          }
                          else
                          {
                            this->criticalMiss = CharacterBaseCharacteristic();
                            this->criticalMiss.deserialize(param1);
                            this->healBonus = CharacterBaseCharacteristic();
                            this->healBonus.deserialize(param1);
                            this->allDamagesBonus = CharacterBaseCharacteristic();
                            this->allDamagesBonus.deserialize(param1);
                            this->weaponDamagesBonusPercent = CharacterBaseCharacteristic();
                            this->weaponDamagesBonusPercent.deserialize(param1);
                            this->damagesBonusPercent = CharacterBaseCharacteristic();
                            this->damagesBonusPercent.deserialize(param1);
                            this->trapBonus = CharacterBaseCharacteristic();
                            this->trapBonus.deserialize(param1);
                            this->trapBonusPercent = CharacterBaseCharacteristic();
                            this->trapBonusPercent.deserialize(param1);
                            this->glyphBonusPercent = CharacterBaseCharacteristic();
                            this->glyphBonusPercent.deserialize(param1);
                            this->runeBonusPercent = CharacterBaseCharacteristic();
                            this->runeBonusPercent.deserialize(param1);
                            this->permanentDamagePercent = CharacterBaseCharacteristic();
                            this->permanentDamagePercent.deserialize(param1);
                            this->tackleBlock = CharacterBaseCharacteristic();
                            this->tackleBlock.deserialize(param1);
                            this->tackleEvade = CharacterBaseCharacteristic();
                            this->tackleEvade.deserialize(param1);
                            this->PAAttack = CharacterBaseCharacteristic();
                            this->PAAttack.deserialize(param1);
                            this->PMAttack = CharacterBaseCharacteristic();
                            this->PMAttack.deserialize(param1);
                            this->pushDamageBonus = CharacterBaseCharacteristic();
                            this->pushDamageBonus.deserialize(param1);
                            this->criticalDamageBonus = CharacterBaseCharacteristic();
                            this->criticalDamageBonus.deserialize(param1);
                            this->neutralDamageBonus = CharacterBaseCharacteristic();
                            this->neutralDamageBonus.deserialize(param1);
                            this->earthDamageBonus = CharacterBaseCharacteristic();
                            this->earthDamageBonus.deserialize(param1);
                            this->waterDamageBonus = CharacterBaseCharacteristic();
                            this->waterDamageBonus.deserialize(param1);
                            this->airDamageBonus = CharacterBaseCharacteristic();
                            this->airDamageBonus.deserialize(param1);
                            this->fireDamageBonus = CharacterBaseCharacteristic();
                            this->fireDamageBonus.deserialize(param1);
                            this->dodgePALostProbability = CharacterBaseCharacteristic();
                            this->dodgePALostProbability.deserialize(param1);
                            this->dodgePMLostProbability = CharacterBaseCharacteristic();
                            this->dodgePMLostProbability.deserialize(param1);
                            this->neutralElementResistPercent = CharacterBaseCharacteristic();
                            this->neutralElementResistPercent.deserialize(param1);
                            this->earthElementResistPercent = CharacterBaseCharacteristic();
                            this->earthElementResistPercent.deserialize(param1);
                            this->waterElementResistPercent = CharacterBaseCharacteristic();
                            this->waterElementResistPercent.deserialize(param1);
                            this->airElementResistPercent = CharacterBaseCharacteristic();
                            this->airElementResistPercent.deserialize(param1);
                            this->fireElementResistPercent = CharacterBaseCharacteristic();
                            this->fireElementResistPercent.deserialize(param1);
                            this->neutralElementReduction = CharacterBaseCharacteristic();
                            this->neutralElementReduction.deserialize(param1);
                            this->earthElementReduction = CharacterBaseCharacteristic();
                            this->earthElementReduction.deserialize(param1);
                            this->waterElementReduction = CharacterBaseCharacteristic();
                            this->waterElementReduction.deserialize(param1);
                            this->airElementReduction = CharacterBaseCharacteristic();
                            this->airElementReduction.deserialize(param1);
                            this->fireElementReduction = CharacterBaseCharacteristic();
                            this->fireElementReduction.deserialize(param1);
                            this->pushDamageReduction = CharacterBaseCharacteristic();
                            this->pushDamageReduction.deserialize(param1);
                            this->criticalDamageReduction = CharacterBaseCharacteristic();
                            this->criticalDamageReduction.deserialize(param1);
                            this->pvpNeutralElementResistPercent = CharacterBaseCharacteristic();
                            this->pvpNeutralElementResistPercent.deserialize(param1);
                            this->pvpEarthElementResistPercent = CharacterBaseCharacteristic();
                            this->pvpEarthElementResistPercent.deserialize(param1);
                            this->pvpWaterElementResistPercent = CharacterBaseCharacteristic();
                            this->pvpWaterElementResistPercent.deserialize(param1);
                            this->pvpAirElementResistPercent = CharacterBaseCharacteristic();
                            this->pvpAirElementResistPercent.deserialize(param1);
                            this->pvpFireElementResistPercent = CharacterBaseCharacteristic();
                            this->pvpFireElementResistPercent.deserialize(param1);
                            this->pvpNeutralElementReduction = CharacterBaseCharacteristic();
                            this->pvpNeutralElementReduction.deserialize(param1);
                            this->pvpEarthElementReduction = CharacterBaseCharacteristic();
                            this->pvpEarthElementReduction.deserialize(param1);
                            this->pvpWaterElementReduction = CharacterBaseCharacteristic();
                            this->pvpWaterElementReduction.deserialize(param1);
                            this->pvpAirElementReduction = CharacterBaseCharacteristic();
                            this->pvpAirElementReduction.deserialize(param1);
                            this->pvpFireElementReduction = CharacterBaseCharacteristic();
                            this->pvpFireElementReduction.deserialize(param1);
                            uint _loc2_ = param1->readUShort();
                            uint _loc3_ = 0;
                            while(_loc3_ < _loc2_)
                            {
                              _loc4_ = CharacterSpellModification();
                              _loc4_.deserialize(param1);
                              this->spellModifications.append(_loc4_);
                              _loc3_++;
                            }
                            this->probationTime = param1->readInt();
                            if(this->probationTime < 0)
                            {
                              qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->probationTime << ") on element of CharacterCharacteristicsInformations.probationTime.";
                            }
                            else
                            {
                              return;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

CharacterCharacteristicsInformations::CharacterCharacteristicsInformations()
{
  m_types<<ClassEnum::CHARACTERCHARACTERISTICSINFORMATIONS;
}

bool CharacterCharacteristicsInformations::operator==(const CharacterCharacteristicsInformations &compared)
{
  if(experience == compared.experience)
  if(experienceLevelFloor == compared.experienceLevelFloor)
  if(experienceNextLevelFloor == compared.experienceNextLevelFloor)
  if(experienceBonusLimit == compared.experienceBonusLimit)
  if(kamas == compared.kamas)
  if(statsPoints == compared.statsPoints)
  if(additionnalPoints == compared.additionnalPoints)
  if(spellsPoints == compared.spellsPoints)
  if(alignmentInfos == compared.alignmentInfos)
  if(lifePoints == compared.lifePoints)
  if(maxLifePoints == compared.maxLifePoints)
  if(energyPoints == compared.energyPoints)
  if(maxEnergyPoints == compared.maxEnergyPoints)
  if(actionPointsCurrent == compared.actionPointsCurrent)
  if(movementPointsCurrent == compared.movementPointsCurrent)
  if(initiative == compared.initiative)
  if(prospecting == compared.prospecting)
  if(actionPoints == compared.actionPoints)
  if(movementPoints == compared.movementPoints)
  if(strength == compared.strength)
  if(vitality == compared.vitality)
  if(wisdom == compared.wisdom)
  if(chance == compared.chance)
  if(agility == compared.agility)
  if(intelligence == compared.intelligence)
  if(range == compared.range)
  if(summonableCreaturesBoost == compared.summonableCreaturesBoost)
  if(reflect == compared.reflect)
  if(criticalHit == compared.criticalHit)
  if(criticalHitWeapon == compared.criticalHitWeapon)
  if(criticalMiss == compared.criticalMiss)
  if(healBonus == compared.healBonus)
  if(allDamagesBonus == compared.allDamagesBonus)
  if(weaponDamagesBonusPercent == compared.weaponDamagesBonusPercent)
  if(damagesBonusPercent == compared.damagesBonusPercent)
  if(trapBonus == compared.trapBonus)
  if(trapBonusPercent == compared.trapBonusPercent)
  if(glyphBonusPercent == compared.glyphBonusPercent)
  if(runeBonusPercent == compared.runeBonusPercent)
  if(permanentDamagePercent == compared.permanentDamagePercent)
  if(tackleBlock == compared.tackleBlock)
  if(tackleEvade == compared.tackleEvade)
  if(PAAttack == compared.PAAttack)
  if(PMAttack == compared.PMAttack)
  if(pushDamageBonus == compared.pushDamageBonus)
  if(criticalDamageBonus == compared.criticalDamageBonus)
  if(neutralDamageBonus == compared.neutralDamageBonus)
  if(earthDamageBonus == compared.earthDamageBonus)
  if(waterDamageBonus == compared.waterDamageBonus)
  if(airDamageBonus == compared.airDamageBonus)
  if(fireDamageBonus == compared.fireDamageBonus)
  if(dodgePALostProbability == compared.dodgePALostProbability)
  if(dodgePMLostProbability == compared.dodgePMLostProbability)
  if(neutralElementResistPercent == compared.neutralElementResistPercent)
  if(earthElementResistPercent == compared.earthElementResistPercent)
  if(waterElementResistPercent == compared.waterElementResistPercent)
  if(airElementResistPercent == compared.airElementResistPercent)
  if(fireElementResistPercent == compared.fireElementResistPercent)
  if(neutralElementReduction == compared.neutralElementReduction)
  if(earthElementReduction == compared.earthElementReduction)
  if(waterElementReduction == compared.waterElementReduction)
  if(airElementReduction == compared.airElementReduction)
  if(fireElementReduction == compared.fireElementReduction)
  if(pushDamageReduction == compared.pushDamageReduction)
  if(criticalDamageReduction == compared.criticalDamageReduction)
  if(pvpNeutralElementResistPercent == compared.pvpNeutralElementResistPercent)
  if(pvpEarthElementResistPercent == compared.pvpEarthElementResistPercent)
  if(pvpWaterElementResistPercent == compared.pvpWaterElementResistPercent)
  if(pvpAirElementResistPercent == compared.pvpAirElementResistPercent)
  if(pvpFireElementResistPercent == compared.pvpFireElementResistPercent)
  if(pvpNeutralElementReduction == compared.pvpNeutralElementReduction)
  if(pvpEarthElementReduction == compared.pvpEarthElementReduction)
  if(pvpWaterElementReduction == compared.pvpWaterElementReduction)
  if(pvpAirElementReduction == compared.pvpAirElementReduction)
  if(pvpFireElementReduction == compared.pvpFireElementReduction)
  if(spellModifications == compared.spellModifications)
  if(probationTime == compared.probationTime)
  return true;
  
  return false;
}

