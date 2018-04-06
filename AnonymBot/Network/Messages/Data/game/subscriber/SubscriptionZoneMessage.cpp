#include "SubscriptionZoneMessage.h"

void SubscriptionZoneMessage::serialize(Writer *param1)
{
  this->serializeAs_SubscriptionZoneMessage(param1);
}

void SubscriptionZoneMessage::serializeAs_SubscriptionZoneMessage(Writer *param1)
{
  param1->writeBool(this->active);
}

void SubscriptionZoneMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SubscriptionZoneMessage(param1);
}

void SubscriptionZoneMessage::deserializeAs_SubscriptionZoneMessage(Reader *param1)
{
  this->active = param1->readBool();
}

SubscriptionZoneMessage::SubscriptionZoneMessage()
{
  m_type = MessageEnum::SUBSCRIPTIONZONEMESSAGE;
}

