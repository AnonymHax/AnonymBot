#include "GameRolePlayArenaFightPropositionMessage.h"

void GameRolePlayArenaFightPropositionMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayArenaFightPropositionMessage(param1);
}

void GameRolePlayArenaFightPropositionMessage::serializeAs_GameRolePlayArenaFightPropositionMessage(Writer *param1)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaFightPropositionMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  else
  {
    param1->writeInt((int)this->fightId);
    param1->writeShort((short)this->alliesId.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->alliesId.size())
    {
      if(this->alliesId[_loc2_] < -9.007199254740992E15 || this->alliesId[_loc2_] > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - GameRolePlayArenaFightPropositionMessage -"<<"Forbidden value (" << this->alliesId[_loc2_] << ") on element 2 (starting at 1) of alliesId.";
      }
      else
      {
        param1->writeDouble(this->alliesId[_loc2_]);
        _loc2_++;
        continue;
      }
    }
    if(this->duration < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayArenaFightPropositionMessage -"<<"Forbidden value (" << this->duration << ") on element duration.";
    }
    else
    {
      param1->writeVarShort((int)this->duration);
      return;
    }
  }
}

void GameRolePlayArenaFightPropositionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayArenaFightPropositionMessage(param1);
}

void GameRolePlayArenaFightPropositionMessage::deserializeAs_GameRolePlayArenaFightPropositionMessage(Reader *param1)
{
  auto _loc4_ = NULL;
  this->fightId = param1->readInt();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaFightPropositionMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameRolePlayArenaFightPropositionMessage.fightId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readDouble();
      if(_loc4_ < -9.007199254740992E15 || _loc4_ > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - GameRolePlayArenaFightPropositionMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of alliesId.";
      }
      else
      {
        this->alliesId.append(_loc4_);
        _loc3_++;
        continue;
      }
    }
    this->duration = param1->readVarUhShort();
    if(this->duration < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayArenaFightPropositionMessage -"<<"Forbidden value (" << this->duration << ") on element of GameRolePlayArenaFightPropositionMessage.duration.";
    }
    else
    {
      return;
    }
  }
}

GameRolePlayArenaFightPropositionMessage::GameRolePlayArenaFightPropositionMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAFIGHTPROPOSITIONMESSAGE;
}

