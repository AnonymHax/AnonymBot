#include "GameFightFighterTaxCollectorLightInformations.h"

void GameFightFighterTaxCollectorLightInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightFighterTaxCollectorLightInformations(param1);
}

void GameFightFighterTaxCollectorLightInformations::serializeAs_GameFightFighterTaxCollectorLightInformations(Writer *param1)
{
  GameFightFighterLightInformations::serializeAs_GameFightFighterLightInformations(param1);
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterTaxCollectorLightInformations -"<<"Forbidden value (" << this->firstNameId << ") on element firstNameId.";
  }
  else
  {
    param1->writeVarShort((int)this->firstNameId);
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - GameFightFighterTaxCollectorLightInformations -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
    }
    else
    {
      param1->writeVarShort((int)this->lastNameId);
      return;
    }
  }
}

void GameFightFighterTaxCollectorLightInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightFighterTaxCollectorLightInformations(param1);
}

void GameFightFighterTaxCollectorLightInformations::deserializeAs_GameFightFighterTaxCollectorLightInformations(Reader *param1)
{
  GameFightFighterLightInformations::deserialize(param1);
  this->firstNameId = param1->readVarUhShort();
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterTaxCollectorLightInformations -"<<"Forbidden value (" << this->firstNameId << ") on element of GameFightFighterTaxCollectorLightInformations.firstNameId.";
  }
  else
  {
    this->lastNameId = param1->readVarUhShort();
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - GameFightFighterTaxCollectorLightInformations -"<<"Forbidden value (" << this->lastNameId << ") on element of GameFightFighterTaxCollectorLightInformations.lastNameId.";
    }
    else
    {
      return;
    }
  }
}

GameFightFighterTaxCollectorLightInformations::GameFightFighterTaxCollectorLightInformations()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERTAXCOLLECTORLIGHTINFORMATIONS;
}

bool GameFightFighterTaxCollectorLightInformations::operator==(const GameFightFighterTaxCollectorLightInformations &compared)
{
  if(firstNameId == compared.firstNameId)
  if(lastNameId == compared.lastNameId)
  return true;
  
  return false;
}

