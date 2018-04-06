#include "ExchangeObjectPutInBagMessage.h"

void ExchangeObjectPutInBagMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectPutInBagMessage(param1);
}

void ExchangeObjectPutInBagMessage::serializeAs_ExchangeObjectPutInBagMessage(Writer *param1)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(param1);
  this->object->serializeAs_ObjectItem(param1);
}

void ExchangeObjectPutInBagMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectPutInBagMessage(param1);
}

void ExchangeObjectPutInBagMessage::deserializeAs_ExchangeObjectPutInBagMessage(Reader *param1)
{
  ExchangeObjectMessage::deserialize(param1);
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(param1);
}

ExchangeObjectPutInBagMessage::ExchangeObjectPutInBagMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTPUTINBAGMESSAGE;
}

