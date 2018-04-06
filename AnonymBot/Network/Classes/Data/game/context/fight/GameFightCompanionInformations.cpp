#include "GameFightCompanionInformations.h"

void GameFightCompanionInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightCompanionInformations(param1);
}

void GameFightCompanionInformations::serializeAs_GameFightCompanionInformations(Writer *param1)
{
  GameFightFighterInformations::serializeAs_GameFightFighterInformations(param1);
  if(this->companionGenericId < 0)
  {
    qDebug()<<"ERREUR - GameFightCompanionInformations -"<<"Forbidden value (" << this->companionGenericId << ") on element companionGenericId.";
  }
  else
  {
    param1->writeByte(this->companionGenericId);
    if(this->level < 0 || this->level > 255)
    {
      qDebug()<<"ERREUR - GameFightCompanionInformations -"<<"Forbidden value (" << this->level << ") on element level.";
    }
    else
    {
      param1->writeByte(this->level);
      if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - GameFightCompanionInformations -"<<"Forbidden value (" << this->masterId << ") on element masterId.";
      }
      else
      {
        param1->writeDouble(this->masterId);
        return;
      }
    }
  }
}

void GameFightCompanionInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightCompanionInformations(param1);
}

void GameFightCompanionInformations::deserializeAs_GameFightCompanionInformations(Reader *param1)
{
  GameFightFighterInformations::deserialize(param1);
  this->companionGenericId = param1->readByte();
  if(this->companionGenericId < 0)
  {
    qDebug()<<"ERREUR - GameFightCompanionInformations -"<<"Forbidden value (" << this->companionGenericId << ") on element of GameFightCompanionInformations.companionGenericId.";
  }
  else
  {
    this->level = param1->readUByte();
    if(this->level < 0 || this->level > 255)
    {
      qDebug()<<"ERREUR - GameFightCompanionInformations -"<<"Forbidden value (" << this->level << ") on element of GameFightCompanionInformations.level.";
    }
    else
    {
      this->masterId = param1->readDouble();
      if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - GameFightCompanionInformations -"<<"Forbidden value (" << this->masterId << ") on element of GameFightCompanionInformations.masterId.";
      }
      else
      {
        return;
      }
    }
  }
}

GameFightCompanionInformations::GameFightCompanionInformations()
{
  m_types<<ClassEnum::GAMEFIGHTCOMPANIONINFORMATIONS;
}

bool GameFightCompanionInformations::operator==(const GameFightCompanionInformations &compared)
{
  if(companionGenericId == compared.companionGenericId)
  if(level == compared.level)
  if(masterId == compared.masterId)
  return true;
  
  return false;
}

