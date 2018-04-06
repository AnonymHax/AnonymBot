#include "PrismsListUpdateMessage.h"

void PrismsListUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismsListUpdateMessage(param1);
}

void PrismsListUpdateMessage::serializeAs_PrismsListUpdateMessage(Writer *param1)
{
  PrismsListMessage::serializeAs_PrismsListMessage(param1);
}

void PrismsListUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismsListUpdateMessage(param1);
}

void PrismsListUpdateMessage::deserializeAs_PrismsListUpdateMessage(Reader *param1)
{
  PrismsListMessage::deserialize(param1);
}

PrismsListUpdateMessage::PrismsListUpdateMessage()
{
  m_type = MessageEnum::PRISMSLISTUPDATEMESSAGE;
}

