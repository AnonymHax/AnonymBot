#include "GameRolePlayArenaRegistrationStatusMessage.h"

void GameRolePlayArenaRegistrationStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayArenaRegistrationStatusMessage(param1);
}

void GameRolePlayArenaRegistrationStatusMessage::serializeAs_GameRolePlayArenaRegistrationStatusMessage(Writer *param1)
{
  param1->writeBool(this->registered);
  param1->writeByte(this->step);
  param1->writeInt((int)this->battleMode);
}

void GameRolePlayArenaRegistrationStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayArenaRegistrationStatusMessage(param1);
}

void GameRolePlayArenaRegistrationStatusMessage::deserializeAs_GameRolePlayArenaRegistrationStatusMessage(Reader *param1)
{
  this->registered = param1->readBool();
  this->step = param1->readByte();
  if(this->step < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaRegistrationStatusMessage -"<<"Forbidden value (" << this->step << ") on element of GameRolePlayArenaRegistrationStatusMessage.step.";
  }
  else
  {
    this->battleMode = param1->readInt();
    if(this->battleMode < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayArenaRegistrationStatusMessage -"<<"Forbidden value (" << this->battleMode << ") on element of GameRolePlayArenaRegistrationStatusMessage.battleMode.";
    }
    else
    {
      return;
    }
  }
}

GameRolePlayArenaRegistrationStatusMessage::GameRolePlayArenaRegistrationStatusMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAREGISTRATIONSTATUSMESSAGE;
}

