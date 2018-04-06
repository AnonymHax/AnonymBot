#include "MountDataMessage.h"

void MountDataMessage::serialize(Writer *param1)
{
  this->serializeAs_MountDataMessage(param1);
}

void MountDataMessage::serializeAs_MountDataMessage(Writer *param1)
{
  this->mountData->serializeAs_MountClientData(param1);
}

void MountDataMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountDataMessage(param1);
}

void MountDataMessage::deserializeAs_MountDataMessage(Reader *param1)
{
  this->mountData = QSharedPointer<MountClientData>(new MountClientData() );
  this->mountData->deserialize(param1);
}

MountDataMessage::MountDataMessage()
{
  m_type = MessageEnum::MOUNTDATAMESSAGE;
}

