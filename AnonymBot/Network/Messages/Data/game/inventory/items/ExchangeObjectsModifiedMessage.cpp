#include "ExchangeObjectsModifiedMessage.h"

void ExchangeObjectsModifiedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectsModifiedMessage(param1);
}

void ExchangeObjectsModifiedMessage::serializeAs_ExchangeObjectsModifiedMessage(Writer *param1)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(param1);
  param1->writeShort((short)this->object.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->object.size())
  {
    qSharedPointerCast<ObjectItem>(this->object[_loc2_])->serializeAs_ObjectItem(param1);
    _loc2_++;
  }
}

void ExchangeObjectsModifiedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectsModifiedMessage(param1);
}

void ExchangeObjectsModifiedMessage::deserializeAs_ExchangeObjectsModifiedMessage(Reader *param1)
{
  QSharedPointer<ObjectItem> _loc4_ ;
  ExchangeObjectMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<ObjectItem>(new ObjectItem() );
    _loc4_->deserialize(param1);
    this->object.append(_loc4_);
    _loc3_++;
  }
}

ExchangeObjectsModifiedMessage::ExchangeObjectsModifiedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTSMODIFIEDMESSAGE;
}

