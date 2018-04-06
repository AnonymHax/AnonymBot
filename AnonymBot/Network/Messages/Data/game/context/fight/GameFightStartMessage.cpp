#include "GameFightStartMessage.h"

void GameFightStartMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightStartMessage(param1);
}

void GameFightStartMessage::serializeAs_GameFightStartMessage(Writer *param1)
{
  param1->writeShort((short)this->idols.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->idols.size())
  {
    qSharedPointerCast<Idol>(this->idols[_loc2_])->serializeAs_Idol(param1);
    _loc2_++;
  }
}

void GameFightStartMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightStartMessage(param1);
}

void GameFightStartMessage::deserializeAs_GameFightStartMessage(Reader *param1)
{
  QSharedPointer<Idol> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<Idol>(new Idol() );
    _loc4_->deserialize(param1);
    this->idols.append(_loc4_);
    _loc3_++;
  }
}

GameFightStartMessage::GameFightStartMessage()
{
  m_type = MessageEnum::GAMEFIGHTSTARTMESSAGE;
}

