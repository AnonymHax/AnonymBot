#include "ExchangeObjectModifiedMessage.h"

void ExchangeObjectModifiedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectModifiedMessage(param1);
}

void ExchangeObjectModifiedMessage::serializeAs_ExchangeObjectModifiedMessage(Writer *param1)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(param1);
  this->object->serializeAs_ObjectItem(param1);
}

void ExchangeObjectModifiedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectModifiedMessage(param1);
}

void ExchangeObjectModifiedMessage::deserializeAs_ExchangeObjectModifiedMessage(Reader *param1)
{
  ExchangeObjectMessage::deserialize(param1);
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(param1);
}

ExchangeObjectModifiedMessage::ExchangeObjectModifiedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMODIFIEDMESSAGE;
}

