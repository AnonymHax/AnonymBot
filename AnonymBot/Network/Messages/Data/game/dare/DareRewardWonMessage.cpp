#include "DareRewardWonMessage.h"

void DareRewardWonMessage::serialize(Writer *param1)
{
  this->serializeAs_DareRewardWonMessage(param1);
}

void DareRewardWonMessage::serializeAs_DareRewardWonMessage(Writer *param1)
{
  this->reward.serializeAs_DareReward(param1);
}

void DareRewardWonMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareRewardWonMessage(param1);
}

void DareRewardWonMessage::deserializeAs_DareRewardWonMessage(Reader *param1)
{
  this->reward = DareReward();
  this->reward.deserialize(param1);
}

DareRewardWonMessage::DareRewardWonMessage()
{
  m_type = MessageEnum::DAREREWARDWONMESSAGE;
}

