#include "DareRewardsListMessage.h"

void DareRewardsListMessage::serialize(Writer *param1)
{
  this->serializeAs_DareRewardsListMessage(param1);
}

void DareRewardsListMessage::serializeAs_DareRewardsListMessage(Writer *param1)
{
  param1->writeShort((short)this->rewards.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->rewards.size())
  {
    (this->rewards[_loc2_]).serializeAs_DareReward(param1);
    _loc2_++;
  }
}

void DareRewardsListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareRewardsListMessage(param1);
}

void DareRewardsListMessage::deserializeAs_DareRewardsListMessage(Reader *param1)
{
  DareReward _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = DareReward();
    _loc4_.deserialize(param1);
    this->rewards.append(_loc4_);
    _loc3_++;
  }
}

DareRewardsListMessage::DareRewardsListMessage()
{
  m_type = MessageEnum::DAREREWARDSLISTMESSAGE;
}

