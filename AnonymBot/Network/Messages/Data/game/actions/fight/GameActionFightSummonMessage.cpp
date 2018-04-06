#include "GameActionFightSummonMessage.h"

void GameActionFightSummonMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightSummonMessage(param1);
}

void GameActionFightSummonMessage::serializeAs_GameActionFightSummonMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  param1->writeShort((short)this->summons.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->summons.size())
  {
    param1->writeShort((short)qSharedPointerCast<GameFightFighterInformations>(this->summons[_loc2_])->getTypes().last());
    qSharedPointerCast<GameFightFighterInformations>(this->summons[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void GameActionFightSummonMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightSummonMessage(param1);
}

void GameActionFightSummonMessage::deserializeAs_GameActionFightSummonMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<GameFightFighterInformations> _loc5_ ;
  AbstractGameActionMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<GameFightFighterInformations>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->summons.append(_loc5_);
    _loc3_++;
  }
}

GameActionFightSummonMessage::GameActionFightSummonMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTSUMMONMESSAGE;
}

