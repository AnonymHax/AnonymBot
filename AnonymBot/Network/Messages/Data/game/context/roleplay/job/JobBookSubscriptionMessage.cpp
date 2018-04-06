#include "JobBookSubscriptionMessage.h"

void JobBookSubscriptionMessage::serialize(Writer *param1)
{
  this->serializeAs_JobBookSubscriptionMessage(param1);
}

void JobBookSubscriptionMessage::serializeAs_JobBookSubscriptionMessage(Writer *param1)
{
  param1->writeShort((short)this->subscriptions.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->subscriptions.size())
  {
    (this->subscriptions[_loc2_]).serializeAs_JobBookSubscription(param1);
    _loc2_++;
  }
}

void JobBookSubscriptionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobBookSubscriptionMessage(param1);
}

void JobBookSubscriptionMessage::deserializeAs_JobBookSubscriptionMessage(Reader *param1)
{
  JobBookSubscription _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = JobBookSubscription();
    _loc4_.deserialize(param1);
    this->subscriptions.append(_loc4_);
    _loc3_++;
  }
}

JobBookSubscriptionMessage::JobBookSubscriptionMessage()
{
  m_type = MessageEnum::JOBBOOKSUBSCRIPTIONMESSAGE;
}

