#include "SubscriptionUpdateMessage.h"

void SubscriptionUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_SubscriptionUpdateMessage(param1);
}

void SubscriptionUpdateMessage::serializeAs_SubscriptionUpdateMessage(Writer *param1)
{
  if(this->timestamp < -9.007199254740992E15 || this->timestamp > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SubscriptionUpdateMessage -"<<"Forbidden value (" << this->timestamp << ") on element timestamp.";
  }
  else
  {
    param1->writeDouble(this->timestamp);
    return;
  }
}

void SubscriptionUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SubscriptionUpdateMessage(param1);
}

void SubscriptionUpdateMessage::deserializeAs_SubscriptionUpdateMessage(Reader *param1)
{
  this->timestamp = param1->readDouble();
  if(this->timestamp < -9.007199254740992E15 || this->timestamp > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SubscriptionUpdateMessage -"<<"Forbidden value (" << this->timestamp << ") on element of SubscriptionUpdateMessage.timestamp.";
  }
  else
  {
    return;
  }
}

SubscriptionUpdateMessage::SubscriptionUpdateMessage()
{
  m_type = MessageEnum::SUBSCRIPTIONUPDATEMESSAGE;
}

