#include "MountReleasedMessage.h"

void MountReleasedMessage::serialize(Writer *param1)
{
  this->serializeAs_MountReleasedMessage(param1);
}

void MountReleasedMessage::serializeAs_MountReleasedMessage(Writer *param1)
{
  param1->writeVarInt((int)this->mountId);
}

void MountReleasedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountReleasedMessage(param1);
}

void MountReleasedMessage::deserializeAs_MountReleasedMessage(Reader *param1)
{
  this->mountId = param1->readVarInt();
}

MountReleasedMessage::MountReleasedMessage()
{
  m_type = MessageEnum::MOUNTRELEASEDMESSAGE;
}

