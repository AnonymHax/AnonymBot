#include "GameRolePlayDelayedActionMessage.h"

void GameRolePlayDelayedActionMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayDelayedActionMessage(param1);
}

void GameRolePlayDelayedActionMessage::serializeAs_GameRolePlayDelayedActionMessage(Writer *param1)
{
  if(this->delayedCharacterId < -9.007199254740992E15 || this->delayedCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedActionMessage -"<<"Forbidden value (" << this->delayedCharacterId << ") on element delayedCharacterId.";
  }
  else
  {
    param1->writeDouble(this->delayedCharacterId);
    param1->writeByte(this->delayTypeId);
    if(this->delayEndTime < 0 || this->delayEndTime > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameRolePlayDelayedActionMessage -"<<"Forbidden value (" << this->delayEndTime << ") on element delayEndTime.";
    }
    else
    {
      param1->writeDouble(this->delayEndTime);
      return;
    }
  }
}

void GameRolePlayDelayedActionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayDelayedActionMessage(param1);
}

void GameRolePlayDelayedActionMessage::deserializeAs_GameRolePlayDelayedActionMessage(Reader *param1)
{
  this->delayedCharacterId = param1->readDouble();
  if(this->delayedCharacterId < -9.007199254740992E15 || this->delayedCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedActionMessage -"<<"Forbidden value (" << this->delayedCharacterId << ") on element of GameRolePlayDelayedActionMessage.delayedCharacterId.";
  }
  else
  {
    this->delayTypeId = param1->readByte();
    if(this->delayTypeId < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayDelayedActionMessage -"<<"Forbidden value (" << this->delayTypeId << ") on element of GameRolePlayDelayedActionMessage.delayTypeId.";
    }
    else
    {
      this->delayEndTime = param1->readDouble();
      if(this->delayEndTime < 0 || this->delayEndTime > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - GameRolePlayDelayedActionMessage -"<<"Forbidden value (" << this->delayEndTime << ") on element of GameRolePlayDelayedActionMessage.delayEndTime.";
      }
      else
      {
        return;
      }
    }
  }
}

GameRolePlayDelayedActionMessage::GameRolePlayDelayedActionMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYDELAYEDACTIONMESSAGE;
}

