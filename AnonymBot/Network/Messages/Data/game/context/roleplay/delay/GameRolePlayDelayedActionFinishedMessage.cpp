#include "GameRolePlayDelayedActionFinishedMessage.h"

void GameRolePlayDelayedActionFinishedMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayDelayedActionFinishedMessage(param1);
}

void GameRolePlayDelayedActionFinishedMessage::serializeAs_GameRolePlayDelayedActionFinishedMessage(Writer *param1)
{
  if(this->delayedCharacterId < -9.007199254740992E15 || this->delayedCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedActionFinishedMessage -"<<"Forbidden value (" << this->delayedCharacterId << ") on element delayedCharacterId.";
  }
  else
  {
    param1->writeDouble(this->delayedCharacterId);
    param1->writeByte(this->delayTypeId);
    return;
  }
}

void GameRolePlayDelayedActionFinishedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayDelayedActionFinishedMessage(param1);
}

void GameRolePlayDelayedActionFinishedMessage::deserializeAs_GameRolePlayDelayedActionFinishedMessage(Reader *param1)
{
  this->delayedCharacterId = param1->readDouble();
  if(this->delayedCharacterId < -9.007199254740992E15 || this->delayedCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedActionFinishedMessage -"<<"Forbidden value (" << this->delayedCharacterId << ") on element of GameRolePlayDelayedActionFinishedMessage.delayedCharacterId.";
  }
  else
  {
    this->delayTypeId = param1->readByte();
    if(this->delayTypeId < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayDelayedActionFinishedMessage -"<<"Forbidden value (" << this->delayTypeId << ") on element of GameRolePlayDelayedActionFinishedMessage.delayTypeId.";
    }
    else
    {
      return;
    }
  }
}

GameRolePlayDelayedActionFinishedMessage::GameRolePlayDelayedActionFinishedMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYDELAYEDACTIONFINISHEDMESSAGE;
}

