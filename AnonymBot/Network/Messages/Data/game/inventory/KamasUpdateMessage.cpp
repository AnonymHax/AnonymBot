#include "KamasUpdateMessage.h"

void KamasUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_KamasUpdateMessage(param1);
}

void KamasUpdateMessage::serializeAs_KamasUpdateMessage(Writer *param1)
{
  param1->writeVarInt((int)this->kamasTotal);
}

void KamasUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_KamasUpdateMessage(param1);
}

void KamasUpdateMessage::deserializeAs_KamasUpdateMessage(Reader *param1)
{
  this->kamasTotal = param1->readVarInt();
}

KamasUpdateMessage::KamasUpdateMessage()
{
  m_type = MessageEnum::KAMASUPDATEMESSAGE;
}

