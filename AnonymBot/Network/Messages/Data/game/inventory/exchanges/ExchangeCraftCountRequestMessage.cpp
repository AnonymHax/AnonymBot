#include "ExchangeCraftCountRequestMessage.h"

void ExchangeCraftCountRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeCraftCountRequestMessage(param1);
}

void ExchangeCraftCountRequestMessage::serializeAs_ExchangeCraftCountRequestMessage(Writer *param1)
{
  param1->writeVarInt((int)this->count);
}

void ExchangeCraftCountRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeCraftCountRequestMessage(param1);
}

void ExchangeCraftCountRequestMessage::deserializeAs_ExchangeCraftCountRequestMessage(Reader *param1)
{
  this->count = param1->readVarInt();
}

ExchangeCraftCountRequestMessage::ExchangeCraftCountRequestMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTCOUNTREQUESTMESSAGE;
}

