#include "IgnoredAddedMessage.h"

void IgnoredAddedMessage::serialize(Writer *param1)
{
  this->serializeAs_IgnoredAddedMessage(param1);
}

void IgnoredAddedMessage::serializeAs_IgnoredAddedMessage(Writer *param1)
{
  param1->writeShort((short)this->ignoreAdded->getTypes().last());
  this->ignoreAdded->serialize(param1);
  param1->writeBool(this->session);
}

void IgnoredAddedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IgnoredAddedMessage(param1);
}

void IgnoredAddedMessage::deserializeAs_IgnoredAddedMessage(Reader *param1)
{
  uint _loc2_ = param1->readUShort();
  this->ignoreAdded = qSharedPointerCast<IgnoredInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->ignoreAdded->deserialize(param1);
  this->session = param1->readBool();
}

IgnoredAddedMessage::IgnoredAddedMessage()
{
  m_type = MessageEnum::IGNOREDADDEDMESSAGE;
}

