#include "ExchangeObjectModifiedInBagMessage.h"

void ExchangeObjectModifiedInBagMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectModifiedInBagMessage(param1);
}

void ExchangeObjectModifiedInBagMessage::serializeAs_ExchangeObjectModifiedInBagMessage(Writer *param1)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(param1);
  this->object->serializeAs_ObjectItem(param1);
}

void ExchangeObjectModifiedInBagMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectModifiedInBagMessage(param1);
}

void ExchangeObjectModifiedInBagMessage::deserializeAs_ExchangeObjectModifiedInBagMessage(Reader *param1)
{
  ExchangeObjectMessage::deserialize(param1);
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(param1);
}

ExchangeObjectModifiedInBagMessage::ExchangeObjectModifiedInBagMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMODIFIEDINBAGMESSAGE;
}

