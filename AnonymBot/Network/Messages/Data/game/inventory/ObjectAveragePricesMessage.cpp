#include "ObjectAveragePricesMessage.h"

void ObjectAveragePricesMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectAveragePricesMessage(param1);
}

void ObjectAveragePricesMessage::serializeAs_ObjectAveragePricesMessage(Writer *param1)
{
  param1->writeShort((short)this->ids.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->ids.size())
  {
    if(this->ids[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - ObjectAveragePricesMessage -"<<"Forbidden value (" << this->ids[_loc2_] << ") on element 1 (starting at 1) of ids.";
    }
    else
    {
      param1->writeVarShort((int)this->ids[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->avgPrices.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->avgPrices.size())
  {
    if(this->avgPrices[_loc3_] < 0)
    {
      qDebug()<<"ERREUR - ObjectAveragePricesMessage -"<<"Forbidden value (" << this->avgPrices[_loc3_] << ") on element 2 (starting at 1) of avgPrices.";
    }
    else
    {
      param1->writeVarInt((int)this->avgPrices[_loc3_]);
      _loc3_++;
      continue;
    }
  }
}

void ObjectAveragePricesMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectAveragePricesMessage(param1);
}

void ObjectAveragePricesMessage::deserializeAs_ObjectAveragePricesMessage(Reader *param1)
{
  uint _loc6_ = 0;
  uint _loc7_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readVarUhShort();
    if(_loc6_ < 0)
    {
      qDebug()<<"ERREUR - ObjectAveragePricesMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of ids.";
    }
    else
    {
      this->ids.append(_loc6_);
      _loc3_++;
      continue;
    }
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = param1->readVarUhInt();
    if(_loc7_ < 0)
    {
      qDebug()<<"ERREUR - ObjectAveragePricesMessage -"<<"Forbidden value (" << _loc7_ << ") on elements of avgPrices.";
    }
    else
    {
      this->avgPrices.append(_loc7_);
      _loc5_++;
      continue;
    }
  }
}

ObjectAveragePricesMessage::ObjectAveragePricesMessage()
{
  m_type = MessageEnum::OBJECTAVERAGEPRICESMESSAGE;
}

