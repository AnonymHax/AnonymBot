#include "GameRolePlayPlayerFightFriendlyAnsweredMessage.h"

void GameRolePlayPlayerFightFriendlyAnsweredMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(param1);
}

void GameRolePlayPlayerFightFriendlyAnsweredMessage::serializeAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(Writer *param1)
{
  param1->writeInt((int)this->fightId);
  if(this->sourceId < 0 || this->sourceId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyAnsweredMessage -"<<"Forbidden value (" << this->sourceId << ") on element sourceId.";
  }
  else
  {
    param1->writeVarLong((double)this->sourceId);
    if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyAnsweredMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
    }
    else
    {
      param1->writeVarLong((double)this->targetId);
      param1->writeBool(this->accept);
      return;
    }
  }
}

void GameRolePlayPlayerFightFriendlyAnsweredMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(param1);
}

void GameRolePlayPlayerFightFriendlyAnsweredMessage::deserializeAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(Reader *param1)
{
  this->fightId = param1->readInt();
  this->sourceId = param1->readVarUhLong();
  if(this->sourceId < 0 || this->sourceId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyAnsweredMessage -"<<"Forbidden value (" << this->sourceId << ") on element of GameRolePlayPlayerFightFriendlyAnsweredMessage.sourceId.";
  }
  else
  {
    this->targetId = param1->readVarUhLong();
    if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyAnsweredMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameRolePlayPlayerFightFriendlyAnsweredMessage.targetId.";
    }
    else
    {
      this->accept = param1->readBool();
      return;
    }
  }
}

GameRolePlayPlayerFightFriendlyAnsweredMessage::GameRolePlayPlayerFightFriendlyAnsweredMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWEREDMESSAGE;
}

