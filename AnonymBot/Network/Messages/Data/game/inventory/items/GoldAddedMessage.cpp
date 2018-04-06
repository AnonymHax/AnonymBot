#include "GoldAddedMessage.h"

void GoldAddedMessage::serialize(Writer *param1)
{
  this->serializeAs_GoldAddedMessage(param1);
}

void GoldAddedMessage::serializeAs_GoldAddedMessage(Writer *param1)
{
  this->gold.serializeAs_GoldItem(param1);
}

void GoldAddedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GoldAddedMessage(param1);
}

void GoldAddedMessage::deserializeAs_GoldAddedMessage(Reader *param1)
{
  this->gold = GoldItem();
  this->gold.deserialize(param1);
}

GoldAddedMessage::GoldAddedMessage()
{
  m_type = MessageEnum::GOLDADDEDMESSAGE;
}

