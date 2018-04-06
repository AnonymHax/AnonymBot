#include "MountRenameRequestMessage.h"

void MountRenameRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_MountRenameRequestMessage(param1);
}

void MountRenameRequestMessage::serializeAs_MountRenameRequestMessage(Writer *param1)
{
  param1->writeUTF(this->name);
  param1->writeVarInt((int)this->mountId);
}

void MountRenameRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountRenameRequestMessage(param1);
}

void MountRenameRequestMessage::deserializeAs_MountRenameRequestMessage(Reader *param1)
{
  this->name = param1->readUTF();
  this->mountId = param1->readVarInt();
}

MountRenameRequestMessage::MountRenameRequestMessage()
{
  m_type = MessageEnum::MOUNTRENAMEREQUESTMESSAGE;
}

