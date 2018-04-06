#include "GameFightSynchronizeMessage.h"

void GameFightSynchronizeMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightSynchronizeMessage(param1);
}

void GameFightSynchronizeMessage::serializeAs_GameFightSynchronizeMessage(Writer *param1)
{
  param1->writeShort((short)this->fighters.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->fighters.size())
  {
    param1->writeShort((short)qSharedPointerCast<GameFightFighterInformations>(this->fighters[_loc2_])->getTypes().last());
    qSharedPointerCast<GameFightFighterInformations>(this->fighters[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void GameFightSynchronizeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightSynchronizeMessage(param1);
}

void GameFightSynchronizeMessage::deserializeAs_GameFightSynchronizeMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<GameFightFighterInformations> _loc5_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<GameFightFighterInformations>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->fighters.append(_loc5_);
    _loc3_++;
  }
}

GameFightSynchronizeMessage::GameFightSynchronizeMessage()
{
  m_type = MessageEnum::GAMEFIGHTSYNCHRONIZEMESSAGE;
}

