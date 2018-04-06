#include "GameFightMonsterInformations.h"

void GameFightMonsterInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightMonsterInformations(param1);
}

void GameFightMonsterInformations::serializeAs_GameFightMonsterInformations(Writer *param1)
{
  GameFightAIInformations::serializeAs_GameFightAIInformations(param1);
  if(this->creatureGenericId < 0)
  {
    qDebug()<<"ERREUR - GameFightMonsterInformations -"<<"Forbidden value (" << this->creatureGenericId << ") on element creatureGenericId.";
  }
  else
  {
    param1->writeVarShort((int)this->creatureGenericId);
    if(this->creatureGrade < 0)
    {
      qDebug()<<"ERREUR - GameFightMonsterInformations -"<<"Forbidden value (" << this->creatureGrade << ") on element creatureGrade.";
    }
    else
    {
      param1->writeByte(this->creatureGrade);
      return;
    }
  }
}

void GameFightMonsterInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightMonsterInformations(param1);
}

void GameFightMonsterInformations::deserializeAs_GameFightMonsterInformations(Reader *param1)
{
  GameFightAIInformations::deserialize(param1);
  this->creatureGenericId = param1->readVarUhShort();
  if(this->creatureGenericId < 0)
  {
    qDebug()<<"ERREUR - GameFightMonsterInformations -"<<"Forbidden value (" << this->creatureGenericId << ") on element of GameFightMonsterInformations.creatureGenericId.";
  }
  else
  {
    this->creatureGrade = param1->readByte();
    if(this->creatureGrade < 0)
    {
      qDebug()<<"ERREUR - GameFightMonsterInformations -"<<"Forbidden value (" << this->creatureGrade << ") on element of GameFightMonsterInformations.creatureGrade.";
    }
    else
    {
      return;
    }
  }
}

GameFightMonsterInformations::GameFightMonsterInformations()
{
  m_types<<ClassEnum::GAMEFIGHTMONSTERINFORMATIONS;
}

bool GameFightMonsterInformations::operator==(const GameFightMonsterInformations &compared)
{
  if(creatureGenericId == compared.creatureGenericId)
  if(creatureGrade == compared.creatureGrade)
  return true;
  
  return false;
}

