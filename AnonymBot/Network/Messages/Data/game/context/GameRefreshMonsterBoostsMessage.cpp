#include "GameRefreshMonsterBoostsMessage.h"

void GameRefreshMonsterBoostsMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRefreshMonsterBoostsMessage(param1);
}

void GameRefreshMonsterBoostsMessage::serializeAs_GameRefreshMonsterBoostsMessage(Writer *param1)
{
  param1->writeShort((short)this->monsterBoosts.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->monsterBoosts.size())
  {
    (this->monsterBoosts[_loc2_]).serializeAs_MonsterBoosts(param1);
    _loc2_++;
  }
  param1->writeShort((short)this->familyBoosts.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->familyBoosts.size())
  {
    (this->familyBoosts[_loc3_]).serializeAs_MonsterBoosts(param1);
    _loc3_++;
  }
}

void GameRefreshMonsterBoostsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRefreshMonsterBoostsMessage(param1);
}

void GameRefreshMonsterBoostsMessage::deserializeAs_GameRefreshMonsterBoostsMessage(Reader *param1)
{
  MonsterBoosts _loc6_ ;
  MonsterBoosts _loc7_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = MonsterBoosts();
    _loc6_.deserialize(param1);
    this->monsterBoosts.append(_loc6_);
    _loc3_++;
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = MonsterBoosts();
    _loc7_.deserialize(param1);
    this->familyBoosts.append(_loc7_);
    _loc5_++;
  }
}

GameRefreshMonsterBoostsMessage::GameRefreshMonsterBoostsMessage()
{
  m_type = MessageEnum::GAMEREFRESHMONSTERBOOSTSMESSAGE;
}

