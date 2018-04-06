#include "GameRolePlayNpcQuestFlag.h"

void GameRolePlayNpcQuestFlag::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayNpcQuestFlag(param1);
}

void GameRolePlayNpcQuestFlag::serializeAs_GameRolePlayNpcQuestFlag(Writer *param1)
{
  param1->writeShort((short)this->questsToValidId.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->questsToValidId.size())
  {
    if(this->questsToValidId[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayNpcQuestFlag -"<<"Forbidden value (" << this->questsToValidId[_loc2_] << ") on element 1 (starting at 1) of questsToValidId.";
    }
    else
    {
      param1->writeVarShort((int)this->questsToValidId[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->questsToStartId.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->questsToStartId.size())
  {
    if(this->questsToStartId[_loc3_] < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayNpcQuestFlag -"<<"Forbidden value (" << this->questsToStartId[_loc3_] << ") on element 2 (starting at 1) of questsToStartId.";
    }
    else
    {
      param1->writeVarShort((int)this->questsToStartId[_loc3_]);
      _loc3_++;
      continue;
    }
  }
}

void GameRolePlayNpcQuestFlag::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayNpcQuestFlag(param1);
}

void GameRolePlayNpcQuestFlag::deserializeAs_GameRolePlayNpcQuestFlag(Reader *param1)
{
  uint _loc6_ = 0;
  uint _loc7_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readVarUhShort();
    if(_loc6_ < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayNpcQuestFlag -"<<"Forbidden value (" << _loc6_ << ") on elements of questsToValidId.";
    }
    else
    {
      this->questsToValidId.append(_loc6_);
      _loc3_++;
      continue;
    }
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = param1->readVarUhShort();
    if(_loc7_ < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayNpcQuestFlag -"<<"Forbidden value (" << _loc7_ << ") on elements of questsToStartId.";
    }
    else
    {
      this->questsToStartId.append(_loc7_);
      _loc5_++;
      continue;
    }
  }
}

GameRolePlayNpcQuestFlag::GameRolePlayNpcQuestFlag()
{
  m_types<<ClassEnum::GAMEROLEPLAYNPCQUESTFLAG;
}

bool GameRolePlayNpcQuestFlag::operator==(const GameRolePlayNpcQuestFlag &compared)
{
  if(questsToValidId == compared.questsToValidId)
  if(questsToStartId == compared.questsToStartId)
  return true;
  
  return false;
}

