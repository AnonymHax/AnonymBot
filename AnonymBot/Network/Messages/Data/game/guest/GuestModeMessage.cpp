#include "GuestModeMessage.h"

void GuestModeMessage::serialize(Writer *param1)
{
  this->serializeAs_GuestModeMessage(param1);
}

void GuestModeMessage::serializeAs_GuestModeMessage(Writer *param1)
{
  param1->writeBool(this->active);
}

void GuestModeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuestModeMessage(param1);
}

void GuestModeMessage::deserializeAs_GuestModeMessage(Reader *param1)
{
  this->active = param1->readBool();
}

GuestModeMessage::GuestModeMessage()
{
  m_type = MessageEnum::GUESTMODEMESSAGE;
}

