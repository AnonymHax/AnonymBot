#include "ExchangeObjectMoveKamaMessage.h"

void ExchangeObjectMoveKamaMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectMoveKamaMessage(param1);
}

void ExchangeObjectMoveKamaMessage::serializeAs_ExchangeObjectMoveKamaMessage(Writer *param1)
{
  param1->writeVarInt((int)this->quantity);
}

void ExchangeObjectMoveKamaMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectMoveKamaMessage(param1);
}

void ExchangeObjectMoveKamaMessage::deserializeAs_ExchangeObjectMoveKamaMessage(Reader *param1)
{
  this->quantity = param1->readVarInt();
}

ExchangeObjectMoveKamaMessage::ExchangeObjectMoveKamaMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMOVEKAMAMESSAGE;
}

