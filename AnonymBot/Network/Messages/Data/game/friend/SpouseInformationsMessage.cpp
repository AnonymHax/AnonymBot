#include "SpouseInformationsMessage.h"

void SpouseInformationsMessage::serialize(Writer *param1)
{
  this->serializeAs_SpouseInformationsMessage(param1);
}

void SpouseInformationsMessage::serializeAs_SpouseInformationsMessage(Writer *param1)
{
  param1->writeShort((short)this->spouse->getTypes().last());
  this->spouse->serialize(param1);
}

void SpouseInformationsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SpouseInformationsMessage(param1);
}

void SpouseInformationsMessage::deserializeAs_SpouseInformationsMessage(Reader *param1)
{
  uint _loc2_ = param1->readUShort();
  this->spouse = qSharedPointerCast<FriendSpouseInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->spouse->deserialize(param1);
}

SpouseInformationsMessage::SpouseInformationsMessage()
{
  m_type = MessageEnum::SPOUSEINFORMATIONSMESSAGE;
}

