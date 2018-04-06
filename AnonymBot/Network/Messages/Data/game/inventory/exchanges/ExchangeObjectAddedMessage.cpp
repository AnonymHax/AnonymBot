#include "ExchangeObjectAddedMessage.h"

void ExchangeObjectAddedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectAddedMessage(param1);
}

void ExchangeObjectAddedMessage::serializeAs_ExchangeObjectAddedMessage(Writer *param1)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(param1);
  this->object->serializeAs_ObjectItem(param1);
}

void ExchangeObjectAddedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectAddedMessage(param1);
}

void ExchangeObjectAddedMessage::deserializeAs_ExchangeObjectAddedMessage(Reader *param1)
{
  ExchangeObjectMessage::deserialize(param1);
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(param1);
}

ExchangeObjectAddedMessage::ExchangeObjectAddedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTADDEDMESSAGE;
}

