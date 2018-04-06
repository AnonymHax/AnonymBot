#include "GameRolePlayMountInformations.h"

void GameRolePlayMountInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayMountInformations(param1);
}

void GameRolePlayMountInformations::serializeAs_GameRolePlayMountInformations(Writer *param1)
{
  GameRolePlayNamedActorInformations::serializeAs_GameRolePlayNamedActorInformations(param1);
  param1->writeUTF(this->ownerName);
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - GameRolePlayMountInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  else
  {
    param1->writeByte(this->level);
    return;
  }
}

void GameRolePlayMountInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayMountInformations(param1);
}

void GameRolePlayMountInformations::deserializeAs_GameRolePlayMountInformations(Reader *param1)
{
  GameRolePlayNamedActorInformations::deserialize(param1);
  this->ownerName = param1->readUTF();
  this->level = param1->readUByte();
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - GameRolePlayMountInformations -"<<"Forbidden value (" << this->level << ") on element of GameRolePlayMountInformations.level.";
  }
  else
  {
    return;
  }
}

GameRolePlayMountInformations::GameRolePlayMountInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYMOUNTINFORMATIONS;
}

bool GameRolePlayMountInformations::operator==(const GameRolePlayMountInformations &compared)
{
  if(ownerName == compared.ownerName)
  if(level == compared.level)
  return true;
  
  return false;
}

