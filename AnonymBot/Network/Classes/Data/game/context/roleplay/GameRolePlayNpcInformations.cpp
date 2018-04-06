#include "GameRolePlayNpcInformations.h"

void GameRolePlayNpcInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayNpcInformations(param1);
}

void GameRolePlayNpcInformations::serializeAs_GameRolePlayNpcInformations(Writer *param1)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(param1);
  if(this->npcId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayNpcInformations -"<<"Forbidden value (" << this->npcId << ") on element npcId.";
  }
  else
  {
    param1->writeVarShort((int)this->npcId);
    param1->writeBool(this->sex);
    if(this->specialArtworkId < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayNpcInformations -"<<"Forbidden value (" << this->specialArtworkId << ") on element specialArtworkId.";
    }
    else
    {
      param1->writeVarShort((int)this->specialArtworkId);
      return;
    }
  }
}

void GameRolePlayNpcInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayNpcInformations(param1);
}

void GameRolePlayNpcInformations::deserializeAs_GameRolePlayNpcInformations(Reader *param1)
{
  GameRolePlayActorInformations::deserialize(param1);
  this->npcId = param1->readVarUhShort();
  if(this->npcId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayNpcInformations -"<<"Forbidden value (" << this->npcId << ") on element of GameRolePlayNpcInformations.npcId.";
  }
  else
  {
    this->sex = param1->readBool();
    this->specialArtworkId = param1->readVarUhShort();
    if(this->specialArtworkId < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayNpcInformations -"<<"Forbidden value (" << this->specialArtworkId << ") on element of GameRolePlayNpcInformations.specialArtworkId.";
    }
    else
    {
      return;
    }
  }
}

GameRolePlayNpcInformations::GameRolePlayNpcInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYNPCINFORMATIONS;
}

bool GameRolePlayNpcInformations::operator==(const GameRolePlayNpcInformations &compared)
{
  if(npcId == compared.npcId)
  if(sex == compared.sex)
  if(specialArtworkId == compared.specialArtworkId)
  return true;
  
  return false;
}

