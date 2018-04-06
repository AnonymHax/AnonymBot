#include "GameFightTaxCollectorInformations.h"

void GameFightTaxCollectorInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightTaxCollectorInformations(param1);
}

void GameFightTaxCollectorInformations::serializeAs_GameFightTaxCollectorInformations(Writer *param1)
{
  GameFightAIInformations::serializeAs_GameFightAIInformations(param1);
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - GameFightTaxCollectorInformations -"<<"Forbidden value (" << this->firstNameId << ") on element firstNameId.";
  }
  else
  {
    param1->writeVarShort((int)this->firstNameId);
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - GameFightTaxCollectorInformations -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
    }
    else
    {
      param1->writeVarShort((int)this->lastNameId);
      if(this->level < 0 || this->level > 255)
      {
        qDebug()<<"ERREUR - GameFightTaxCollectorInformations -"<<"Forbidden value (" << this->level << ") on element level.";
      }
      else
      {
        param1->writeByte(this->level);
        return;
      }
    }
  }
}

void GameFightTaxCollectorInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightTaxCollectorInformations(param1);
}

void GameFightTaxCollectorInformations::deserializeAs_GameFightTaxCollectorInformations(Reader *param1)
{
  GameFightAIInformations::deserialize(param1);
  this->firstNameId = param1->readVarUhShort();
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - GameFightTaxCollectorInformations -"<<"Forbidden value (" << this->firstNameId << ") on element of GameFightTaxCollectorInformations.firstNameId.";
  }
  else
  {
    this->lastNameId = param1->readVarUhShort();
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - GameFightTaxCollectorInformations -"<<"Forbidden value (" << this->lastNameId << ") on element of GameFightTaxCollectorInformations.lastNameId.";
    }
    else
    {
      this->level = param1->readUByte();
      if(this->level < 0 || this->level > 255)
      {
        qDebug()<<"ERREUR - GameFightTaxCollectorInformations -"<<"Forbidden value (" << this->level << ") on element of GameFightTaxCollectorInformations.level.";
      }
      else
      {
        return;
      }
    }
  }
}

GameFightTaxCollectorInformations::GameFightTaxCollectorInformations()
{
  m_types<<ClassEnum::GAMEFIGHTTAXCOLLECTORINFORMATIONS;
}

bool GameFightTaxCollectorInformations::operator==(const GameFightTaxCollectorInformations &compared)
{
  if(firstNameId == compared.firstNameId)
  if(lastNameId == compared.lastNameId)
  if(level == compared.level)
  return true;
  
  return false;
}

