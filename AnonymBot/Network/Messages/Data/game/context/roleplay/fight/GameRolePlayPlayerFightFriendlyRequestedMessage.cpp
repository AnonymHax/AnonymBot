#include "GameRolePlayPlayerFightFriendlyRequestedMessage.h"

void GameRolePlayPlayerFightFriendlyRequestedMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayPlayerFightFriendlyRequestedMessage(param1);
}

void GameRolePlayPlayerFightFriendlyRequestedMessage::serializeAs_GameRolePlayPlayerFightFriendlyRequestedMessage(Writer *param1)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyRequestedMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  else
  {
    param1->writeInt((int)this->fightId);
    if(this->sourceId < 0 || this->sourceId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyRequestedMessage -"<<"Forbidden value (" << this->sourceId << ") on element sourceId.";
    }
    else
    {
      param1->writeVarLong((double)this->sourceId);
      if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyRequestedMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
      }
      else
      {
        param1->writeVarLong((double)this->targetId);
        return;
      }
    }
  }
}

void GameRolePlayPlayerFightFriendlyRequestedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayPlayerFightFriendlyRequestedMessage(param1);
}

void GameRolePlayPlayerFightFriendlyRequestedMessage::deserializeAs_GameRolePlayPlayerFightFriendlyRequestedMessage(Reader *param1)
{
  this->fightId = param1->readInt();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyRequestedMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameRolePlayPlayerFightFriendlyRequestedMessage.fightId.";
  }
  else
  {
    this->sourceId = param1->readVarUhLong();
    if(this->sourceId < 0 || this->sourceId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyRequestedMessage -"<<"Forbidden value (" << this->sourceId << ") on element of GameRolePlayPlayerFightFriendlyRequestedMessage.sourceId.";
    }
    else
    {
      this->targetId = param1->readVarUhLong();
      if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyRequestedMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameRolePlayPlayerFightFriendlyRequestedMessage.targetId.";
      }
      else
      {
        return;
      }
    }
  }
}

GameRolePlayPlayerFightFriendlyRequestedMessage::GameRolePlayPlayerFightFriendlyRequestedMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE;
}

