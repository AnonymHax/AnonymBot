#include "ExchangeObjectsRemovedMessage.h"

void ExchangeObjectsRemovedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectsRemovedMessage(param1);
}

void ExchangeObjectsRemovedMessage::serializeAs_ExchangeObjectsRemovedMessage(Writer *param1)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(param1);
  param1->writeShort((short)this->objectUID.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objectUID.size())
  {
    if(this->objectUID[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectsRemovedMessage -"<<"Forbidden value (" << this->objectUID[_loc2_] << ") on element 1 (starting at 1) of objectUID.";
    }
    else
    {
      param1->writeVarInt((int)this->objectUID[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void ExchangeObjectsRemovedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectsRemovedMessage(param1);
}

void ExchangeObjectsRemovedMessage::deserializeAs_ExchangeObjectsRemovedMessage(Reader *param1)
{
  uint _loc4_ = 0;
  ExchangeObjectMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhInt();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectsRemovedMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of objectUID.";
    }
    else
    {
      this->objectUID.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

ExchangeObjectsRemovedMessage::ExchangeObjectsRemovedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTSREMOVEDMESSAGE;
}

