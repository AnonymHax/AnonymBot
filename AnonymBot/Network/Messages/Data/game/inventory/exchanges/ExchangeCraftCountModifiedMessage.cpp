#include "ExchangeCraftCountModifiedMessage.h"

void ExchangeCraftCountModifiedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeCraftCountModifiedMessage(param1);
}

void ExchangeCraftCountModifiedMessage::serializeAs_ExchangeCraftCountModifiedMessage(Writer *param1)
{
  param1->writeVarInt((int)this->count);
}

void ExchangeCraftCountModifiedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeCraftCountModifiedMessage(param1);
}

void ExchangeCraftCountModifiedMessage::deserializeAs_ExchangeCraftCountModifiedMessage(Reader *param1)
{
  this->count = param1->readVarInt();
}

ExchangeCraftCountModifiedMessage::ExchangeCraftCountModifiedMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTCOUNTMODIFIEDMESSAGE;
}

