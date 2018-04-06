#include "MountInformationInPaddockRequestMessage.h"

void MountInformationInPaddockRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_MountInformationInPaddockRequestMessage(param1);
}

void MountInformationInPaddockRequestMessage::serializeAs_MountInformationInPaddockRequestMessage(Writer *param1)
{
  param1->writeVarInt((int)this->mapRideId);
}

void MountInformationInPaddockRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountInformationInPaddockRequestMessage(param1);
}

void MountInformationInPaddockRequestMessage::deserializeAs_MountInformationInPaddockRequestMessage(Reader *param1)
{
  this->mapRideId = param1->readVarInt();
}

MountInformationInPaddockRequestMessage::MountInformationInPaddockRequestMessage()
{
  m_type = MessageEnum::MOUNTINFORMATIONINPADDOCKREQUESTMESSAGE;
}

