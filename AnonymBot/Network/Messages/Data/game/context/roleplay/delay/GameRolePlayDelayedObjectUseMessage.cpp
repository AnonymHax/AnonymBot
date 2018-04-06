#include "GameRolePlayDelayedObjectUseMessage.h"

void GameRolePlayDelayedObjectUseMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayDelayedObjectUseMessage(param1);
}

void GameRolePlayDelayedObjectUseMessage::serializeAs_GameRolePlayDelayedObjectUseMessage(Writer *param1)
{
  GameRolePlayDelayedActionMessage::serializeAs_GameRolePlayDelayedActionMessage(param1);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedObjectUseMessage -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  else
  {
    param1->writeVarShort((int)this->objectGID);
    return;
  }
}

void GameRolePlayDelayedObjectUseMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayDelayedObjectUseMessage(param1);
}

void GameRolePlayDelayedObjectUseMessage::deserializeAs_GameRolePlayDelayedObjectUseMessage(Reader *param1)
{
  GameRolePlayDelayedActionMessage::deserialize(param1);
  this->objectGID = param1->readVarUhShort();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedObjectUseMessage -"<<"Forbidden value (" << this->objectGID << ") on element of GameRolePlayDelayedObjectUseMessage.objectGID.";
  }
  else
  {
    return;
  }
}

GameRolePlayDelayedObjectUseMessage::GameRolePlayDelayedObjectUseMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYDELAYEDOBJECTUSEMESSAGE;
}

