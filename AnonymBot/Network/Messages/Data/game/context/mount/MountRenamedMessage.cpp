#include "MountRenamedMessage.h"

void MountRenamedMessage::serialize(Writer *param1)
{
  this->serializeAs_MountRenamedMessage(param1);
}

void MountRenamedMessage::serializeAs_MountRenamedMessage(Writer *param1)
{
  param1->writeVarInt((int)this->mountId);
  param1->writeUTF(this->name);
}

void MountRenamedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountRenamedMessage(param1);
}

void MountRenamedMessage::deserializeAs_MountRenamedMessage(Reader *param1)
{
  this->mountId = param1->readVarInt();
  this->name = param1->readUTF();
}

MountRenamedMessage::MountRenamedMessage()
{
  m_type = MessageEnum::MOUNTRENAMEDMESSAGE;
}

