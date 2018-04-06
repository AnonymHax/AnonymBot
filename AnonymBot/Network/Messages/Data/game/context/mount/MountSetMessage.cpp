#include "MountSetMessage.h"

void MountSetMessage::serialize(Writer *param1)
{
  this->serializeAs_MountSetMessage(param1);
}

void MountSetMessage::serializeAs_MountSetMessage(Writer *param1)
{
  this->mountData->serializeAs_MountClientData(param1);
}

void MountSetMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountSetMessage(param1);
}

void MountSetMessage::deserializeAs_MountSetMessage(Reader *param1)
{
  this->mountData = QSharedPointer<MountClientData>(new MountClientData() );
  this->mountData->deserialize(param1);
}

MountSetMessage::MountSetMessage()
{
  m_type = MessageEnum::MOUNTSETMESSAGE;
}

