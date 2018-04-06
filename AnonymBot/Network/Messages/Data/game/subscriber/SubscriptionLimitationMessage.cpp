#include "SubscriptionLimitationMessage.h"

void SubscriptionLimitationMessage::serialize(Writer *param1)
{
  this->serializeAs_SubscriptionLimitationMessage(param1);
}

void SubscriptionLimitationMessage::serializeAs_SubscriptionLimitationMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void SubscriptionLimitationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SubscriptionLimitationMessage(param1);
}

void SubscriptionLimitationMessage::deserializeAs_SubscriptionLimitationMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - SubscriptionLimitationMessage -"<<"Forbidden value (" << this->reason << ") on element of SubscriptionLimitationMessage.reason.";
  }
  else
  {
    return;
  }
}

SubscriptionLimitationMessage::SubscriptionLimitationMessage()
{
  m_type = MessageEnum::SUBSCRIPTIONLIMITATIONMESSAGE;
}

