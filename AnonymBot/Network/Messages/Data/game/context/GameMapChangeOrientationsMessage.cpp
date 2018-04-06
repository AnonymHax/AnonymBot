#include "GameMapChangeOrientationsMessage.h"

void GameMapChangeOrientationsMessage::serialize(Writer *param1)
{
  this->serializeAs_GameMapChangeOrientationsMessage(param1);
}

void GameMapChangeOrientationsMessage::serializeAs_GameMapChangeOrientationsMessage(Writer *param1)
{
  param1->writeShort((short)this->orientations.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->orientations.size())
  {
    (this->orientations[_loc2_]).serializeAs_ActorOrientation(param1);
    _loc2_++;
  }
}

void GameMapChangeOrientationsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameMapChangeOrientationsMessage(param1);
}

void GameMapChangeOrientationsMessage::deserializeAs_GameMapChangeOrientationsMessage(Reader *param1)
{
  ActorOrientation _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = ActorOrientation();
    _loc4_.deserialize(param1);
    this->orientations.append(_loc4_);
    _loc3_++;
  }
}

GameMapChangeOrientationsMessage::GameMapChangeOrientationsMessage()
{
  m_type = MessageEnum::GAMEMAPCHANGEORIENTATIONSMESSAGE;
}

