#include "MountRidingMessage.h"

void MountRidingMessage::serialize(Writer *param1)
{
  this->serializeAs_MountRidingMessage(param1);
}

void MountRidingMessage::serializeAs_MountRidingMessage(Writer *param1)
{
  param1->writeBool(this->isRiding);
}

void MountRidingMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountRidingMessage(param1);
}

void MountRidingMessage::deserializeAs_MountRidingMessage(Reader *param1)
{
  this->isRiding = param1->readBool();
}

MountRidingMessage::MountRidingMessage()
{
  m_type = MessageEnum::MOUNTRIDINGMESSAGE;
}

