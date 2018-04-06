#include "MountSterilizedMessage.h"

void MountSterilizedMessage::serialize(Writer *param1)
{
  this->serializeAs_MountSterilizedMessage(param1);
}

void MountSterilizedMessage::serializeAs_MountSterilizedMessage(Writer *param1)
{
  param1->writeVarInt((int)this->mountId);
}

void MountSterilizedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountSterilizedMessage(param1);
}

void MountSterilizedMessage::deserializeAs_MountSterilizedMessage(Reader *param1)
{
  this->mountId = param1->readVarInt();
}

MountSterilizedMessage::MountSterilizedMessage()
{
  m_type = MessageEnum::MOUNTSTERILIZEDMESSAGE;
}

