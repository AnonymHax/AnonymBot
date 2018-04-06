#include "GameFightMinimalStats.h"

void GameFightMinimalStats::serialize(Writer *param1)
{
  this->serializeAs_GameFightMinimalStats(param1);
}

void GameFightMinimalStats::serializeAs_GameFightMinimalStats(Writer *param1)
{
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->lifePoints << ") on element lifePoints.";
  }
  else
  {
    param1->writeVarInt((int)this->lifePoints);
    if(this->maxLifePoints < 0)
    {
      qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->maxLifePoints << ") on element maxLifePoints.";
    }
    else
    {
      param1->writeVarInt((int)this->maxLifePoints);
      if(this->baseMaxLifePoints < 0)
      {
        qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->baseMaxLifePoints << ") on element baseMaxLifePoints.";
      }
      else
      {
        param1->writeVarInt((int)this->baseMaxLifePoints);
        if(this->permanentDamagePercent < 0)
        {
          qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->permanentDamagePercent << ") on element permanentDamagePercent.";
        }
        else
        {
          param1->writeVarInt((int)this->permanentDamagePercent);
          if(this->shieldPoints < 0)
          {
            qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->shieldPoints << ") on element shieldPoints.";
          }
          else
          {
            param1->writeVarInt((int)this->shieldPoints);
            param1->writeVarShort((int)this->actionPoints);
            param1->writeVarShort((int)this->maxActionPoints);
            param1->writeVarShort((int)this->movementPoints);
            param1->writeVarShort((int)this->maxMovementPoints);
            if(this->summoner < -9.007199254740992E15 || this->summoner > 9.007199254740992E15)
            {
              qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->summoner << ") on element summoner.";
            }
            else
            {
              param1->writeDouble(this->summoner);
              param1->writeBool(this->summoned);
              param1->writeVarShort((int)this->neutralElementResistPercent);
              param1->writeVarShort((int)this->earthElementResistPercent);
              param1->writeVarShort((int)this->waterElementResistPercent);
              param1->writeVarShort((int)this->airElementResistPercent);
              param1->writeVarShort((int)this->fireElementResistPercent);
              param1->writeVarShort((int)this->neutralElementReduction);
              param1->writeVarShort((int)this->earthElementReduction);
              param1->writeVarShort((int)this->waterElementReduction);
              param1->writeVarShort((int)this->airElementReduction);
              param1->writeVarShort((int)this->fireElementReduction);
              param1->writeVarShort((int)this->criticalDamageFixedResist);
              param1->writeVarShort((int)this->pushDamageFixedResist);
              param1->writeVarShort((int)this->pvpNeutralElementResistPercent);
              param1->writeVarShort((int)this->pvpEarthElementResistPercent);
              param1->writeVarShort((int)this->pvpWaterElementResistPercent);
              param1->writeVarShort((int)this->pvpAirElementResistPercent);
              param1->writeVarShort((int)this->pvpFireElementResistPercent);
              param1->writeVarShort((int)this->pvpNeutralElementReduction);
              param1->writeVarShort((int)this->pvpEarthElementReduction);
              param1->writeVarShort((int)this->pvpWaterElementReduction);
              param1->writeVarShort((int)this->pvpAirElementReduction);
              param1->writeVarShort((int)this->pvpFireElementReduction);
              if(this->dodgePALostProbability < 0)
              {
                qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->dodgePALostProbability << ") on element dodgePALostProbability.";
              }
              else
              {
                param1->writeVarShort((int)this->dodgePALostProbability);
                if(this->dodgePMLostProbability < 0)
                {
                  qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->dodgePMLostProbability << ") on element dodgePMLostProbability.";
                }
                else
                {
                  param1->writeVarShort((int)this->dodgePMLostProbability);
                  param1->writeVarShort((int)this->tackleBlock);
                  param1->writeVarShort((int)this->tackleEvade);
                  param1->writeVarShort((int)this->fixedDamageReflection);
                  param1->writeByte(this->invisibilityState);
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

void GameFightMinimalStats::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightMinimalStats(param1);
}

void GameFightMinimalStats::deserializeAs_GameFightMinimalStats(Reader *param1)
{
  this->lifePoints = param1->readVarUhInt();
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->lifePoints << ") on element of GameFightMinimalStats.lifePoints.";
  }
  else
  {
    this->maxLifePoints = param1->readVarUhInt();
    if(this->maxLifePoints < 0)
    {
      qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->maxLifePoints << ") on element of GameFightMinimalStats.maxLifePoints.";
    }
    else
    {
      this->baseMaxLifePoints = param1->readVarUhInt();
      if(this->baseMaxLifePoints < 0)
      {
        qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->baseMaxLifePoints << ") on element of GameFightMinimalStats.baseMaxLifePoints.";
      }
      else
      {
        this->permanentDamagePercent = param1->readVarUhInt();
        if(this->permanentDamagePercent < 0)
        {
          qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->permanentDamagePercent << ") on element of GameFightMinimalStats.permanentDamagePercent.";
        }
        else
        {
          this->shieldPoints = param1->readVarUhInt();
          if(this->shieldPoints < 0)
          {
            qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->shieldPoints << ") on element of GameFightMinimalStats.shieldPoints.";
          }
          else
          {
            this->actionPoints = param1->readVarShort();
            this->maxActionPoints = param1->readVarShort();
            this->movementPoints = param1->readVarShort();
            this->maxMovementPoints = param1->readVarShort();
            this->summoner = param1->readDouble();
            if(this->summoner < -9.007199254740992E15 || this->summoner > 9.007199254740992E15)
            {
              qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->summoner << ") on element of GameFightMinimalStats.summoner.";
            }
            else
            {
              this->summoned = param1->readBool();
              this->neutralElementResistPercent = param1->readVarShort();
              this->earthElementResistPercent = param1->readVarShort();
              this->waterElementResistPercent = param1->readVarShort();
              this->airElementResistPercent = param1->readVarShort();
              this->fireElementResistPercent = param1->readVarShort();
              this->neutralElementReduction = param1->readVarShort();
              this->earthElementReduction = param1->readVarShort();
              this->waterElementReduction = param1->readVarShort();
              this->airElementReduction = param1->readVarShort();
              this->fireElementReduction = param1->readVarShort();
              this->criticalDamageFixedResist = param1->readVarShort();
              this->pushDamageFixedResist = param1->readVarShort();
              this->pvpNeutralElementResistPercent = param1->readVarShort();
              this->pvpEarthElementResistPercent = param1->readVarShort();
              this->pvpWaterElementResistPercent = param1->readVarShort();
              this->pvpAirElementResistPercent = param1->readVarShort();
              this->pvpFireElementResistPercent = param1->readVarShort();
              this->pvpNeutralElementReduction = param1->readVarShort();
              this->pvpEarthElementReduction = param1->readVarShort();
              this->pvpWaterElementReduction = param1->readVarShort();
              this->pvpAirElementReduction = param1->readVarShort();
              this->pvpFireElementReduction = param1->readVarShort();
              this->dodgePALostProbability = param1->readVarUhShort();
              if(this->dodgePALostProbability < 0)
              {
                qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->dodgePALostProbability << ") on element of GameFightMinimalStats.dodgePALostProbability.";
              }
              else
              {
                this->dodgePMLostProbability = param1->readVarUhShort();
                if(this->dodgePMLostProbability < 0)
                {
                  qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->dodgePMLostProbability << ") on element of GameFightMinimalStats.dodgePMLostProbability.";
                }
                else
                {
                  this->tackleBlock = param1->readVarShort();
                  this->tackleEvade = param1->readVarShort();
                  this->fixedDamageReflection = param1->readVarShort();
                  this->invisibilityState = param1->readByte();
                  if(this->invisibilityState < 0)
                  {
                    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->invisibilityState << ") on element of GameFightMinimalStats.invisibilityState.";
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

GameFightMinimalStats::GameFightMinimalStats()
{
  m_types<<ClassEnum::GAMEFIGHTMINIMALSTATS;
}

bool GameFightMinimalStats::operator==(const GameFightMinimalStats &compared)
{
  if(lifePoints == compared.lifePoints)
  if(maxLifePoints == compared.maxLifePoints)
  if(baseMaxLifePoints == compared.baseMaxLifePoints)
  if(permanentDamagePercent == compared.permanentDamagePercent)
  if(shieldPoints == compared.shieldPoints)
  if(actionPoints == compared.actionPoints)
  if(maxActionPoints == compared.maxActionPoints)
  if(movementPoints == compared.movementPoints)
  if(maxMovementPoints == compared.maxMovementPoints)
  if(summoner == compared.summoner)
  if(summoned == compared.summoned)
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
  if(criticalDamageFixedResist == compared.criticalDamageFixedResist)
  if(pushDamageFixedResist == compared.pushDamageFixedResist)
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
  if(dodgePALostProbability == compared.dodgePALostProbability)
  if(dodgePMLostProbability == compared.dodgePMLostProbability)
  if(tackleBlock == compared.tackleBlock)
  if(tackleEvade == compared.tackleEvade)
  if(fixedDamageReflection == compared.fixedDamageReflection)
  if(invisibilityState == compared.invisibilityState)
  return true;
  
  return false;
}

