#include "GameFightFighterCompanionLightInformations.h"

void GameFightFighterCompanionLightInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightFighterCompanionLightInformations(param1);
}

void GameFightFighterCompanionLightInformations::serializeAs_GameFightFighterCompanionLightInformations(Writer *param1)
{
  GameFightFighterLightInformations::serializeAs_GameFightFighterLightInformations(param1);
  if(this->companionId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterCompanionLightInformations -"<<"Forbidden value (" << this->companionId << ") on element companionId.";
  }
  else
  {
    param1->writeByte(this->companionId);
    if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightFighterCompanionLightInformations -"<<"Forbidden value (" << this->masterId << ") on element masterId.";
    }
    else
    {
      param1->writeDouble(this->masterId);
      return;
    }
  }
}

void GameFightFighterCompanionLightInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightFighterCompanionLightInformations(param1);
}

void GameFightFighterCompanionLightInformations::deserializeAs_GameFightFighterCompanionLightInformations(Reader *param1)
{
  GameFightFighterLightInformations::deserialize(param1);
  this->companionId = param1->readByte();
  if(this->companionId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterCompanionLightInformations -"<<"Forbidden value (" << this->companionId << ") on element of GameFightFighterCompanionLightInformations.companionId.";
  }
  else
  {
    this->masterId = param1->readDouble();
    if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightFighterCompanionLightInformations -"<<"Forbidden value (" << this->masterId << ") on element of GameFightFighterCompanionLightInformations.masterId.";
    }
    else
    {
      return;
    }
  }
}

GameFightFighterCompanionLightInformations::GameFightFighterCompanionLightInformations()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERCOMPANIONLIGHTINFORMATIONS;
}

bool GameFightFighterCompanionLightInformations::operator==(const GameFightFighterCompanionLightInformations &compared)
{
  if(companionId == compared.companionId)
  if(masterId == compared.masterId)
  return true;
  
  return false;
}

