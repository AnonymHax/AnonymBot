#include "GameFightResumeWithSlavesMessage.h"

void GameFightResumeWithSlavesMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightResumeWithSlavesMessage(param1);
}

void GameFightResumeWithSlavesMessage::serializeAs_GameFightResumeWithSlavesMessage(Writer *param1)
{
  GameFightResumeMessage::serializeAs_GameFightResumeMessage(param1);
  param1->writeShort((short)this->slavesInfo.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->slavesInfo.size())
  {
    (this->slavesInfo[_loc2_]).serializeAs_GameFightResumeSlaveInfo(param1);
    _loc2_++;
  }
}

void GameFightResumeWithSlavesMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightResumeWithSlavesMessage(param1);
}

void GameFightResumeWithSlavesMessage::deserializeAs_GameFightResumeWithSlavesMessage(Reader *param1)
{
  GameFightResumeSlaveInfo _loc4_ ;
  GameFightResumeMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = GameFightResumeSlaveInfo();
    _loc4_.deserialize(param1);
    this->slavesInfo.append(_loc4_);
    _loc3_++;
  }
}

GameFightResumeWithSlavesMessage::GameFightResumeWithSlavesMessage()
{
  m_type = MessageEnum::GAMEFIGHTRESUMEWITHSLAVESMESSAGE;
}

