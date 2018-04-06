#include "ExchangeHandleMountsStableMessage.h"

void ExchangeHandleMountsStableMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeHandleMountsStableMessage(param1);
}

void ExchangeHandleMountsStableMessage::serializeAs_ExchangeHandleMountsStableMessage(Writer *param1)
{
  param1->writeByte(this->actionType);
  param1->writeShort((short)this->ridesId.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->ridesId.size())
  {
    if(this->ridesId[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - ExchangeHandleMountsStableMessage -"<<"Forbidden value (" << this->ridesId[_loc2_] << ") on element 2 (starting at 1) of ridesId.";
    }
    else
    {
      param1->writeVarInt((int)this->ridesId[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void ExchangeHandleMountsStableMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeHandleMountsStableMessage(param1);
}

void ExchangeHandleMountsStableMessage::deserializeAs_ExchangeHandleMountsStableMessage(Reader *param1)
{
  uint _loc4_ = 0;
  this->actionType = param1->readByte();
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhInt();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - ExchangeHandleMountsStableMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of ridesId.";
    }
    else
    {
      this->ridesId.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

ExchangeHandleMountsStableMessage::ExchangeHandleMountsStableMessage()
{
  m_type = MessageEnum::EXCHANGEHANDLEMOUNTSSTABLEMESSAGE;
}

