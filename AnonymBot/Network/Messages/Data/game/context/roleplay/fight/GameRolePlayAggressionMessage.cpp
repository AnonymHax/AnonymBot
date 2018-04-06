#include "GameRolePlayAggressionMessage.h"

void GameRolePlayAggressionMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayAggressionMessage(param1);
}

void GameRolePlayAggressionMessage::serializeAs_GameRolePlayAggressionMessage(Writer *param1)
{
  if(this->attackerId < 0 || this->attackerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayAggressionMessage -"<<"Forbidden value (" << this->attackerId << ") on element attackerId.";
  }
  else
  {
    param1->writeVarLong((double)this->attackerId);
    if(this->defenderId < 0 || this->defenderId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameRolePlayAggressionMessage -"<<"Forbidden value (" << this->defenderId << ") on element defenderId.";
    }
    else
    {
      param1->writeVarLong((double)this->defenderId);
      return;
    }
  }
}

void GameRolePlayAggressionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayAggressionMessage(param1);
}

void GameRolePlayAggressionMessage::deserializeAs_GameRolePlayAggressionMessage(Reader *param1)
{
  this->attackerId = param1->readVarUhLong();
  if(this->attackerId < 0 || this->attackerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayAggressionMessage -"<<"Forbidden value (" << this->attackerId << ") on element of GameRolePlayAggressionMessage.attackerId.";
  }
  else
  {
    this->defenderId = param1->readVarUhLong();
    if(this->defenderId < 0 || this->defenderId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameRolePlayAggressionMessage -"<<"Forbidden value (" << this->defenderId << ") on element of GameRolePlayAggressionMessage.defenderId.";
    }
    else
    {
      return;
    }
  }
}

GameRolePlayAggressionMessage::GameRolePlayAggressionMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYAGGRESSIONMESSAGE;
}

