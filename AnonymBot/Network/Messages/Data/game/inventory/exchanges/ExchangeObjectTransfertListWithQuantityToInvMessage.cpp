#include "ExchangeObjectTransfertListWithQuantityToInvMessage.h"

void ExchangeObjectTransfertListWithQuantityToInvMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectTransfertListWithQuantityToInvMessage(param1);
}

void ExchangeObjectTransfertListWithQuantityToInvMessage::serializeAs_ExchangeObjectTransfertListWithQuantityToInvMessage(Writer *param1)
{
  param1->writeShort((short)this->ids.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->ids.size())
  {
    if(this->ids[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectTransfertListWithQuantityToInvMessage -"<<"Forbidden value (" << this->ids[_loc2_] << ") on element 1 (starting at 1) of ids.";
    }
    else
    {
      param1->writeVarInt((int)this->ids[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->qtys.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->qtys.size())
  {
    if(this->qtys[_loc3_] < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectTransfertListWithQuantityToInvMessage -"<<"Forbidden value (" << this->qtys[_loc3_] << ") on element 2 (starting at 1) of qtys.";
    }
    else
    {
      param1->writeVarInt((int)this->qtys[_loc3_]);
      _loc3_++;
      continue;
    }
  }
}

void ExchangeObjectTransfertListWithQuantityToInvMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectTransfertListWithQuantityToInvMessage(param1);
}

void ExchangeObjectTransfertListWithQuantityToInvMessage::deserializeAs_ExchangeObjectTransfertListWithQuantityToInvMessage(Reader *param1)
{
  uint _loc6_ = 0;
  uint _loc7_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readVarUhInt();
    if(_loc6_ < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectTransfertListWithQuantityToInvMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of ids.";
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
      qDebug()<<"ERREUR - ExchangeObjectTransfertListWithQuantityToInvMessage -"<<"Forbidden value (" << _loc7_ << ") on elements of qtys.";
    }
    else
    {
      this->qtys.append(_loc7_);
      _loc5_++;
      continue;
    }
  }
}

ExchangeObjectTransfertListWithQuantityToInvMessage::ExchangeObjectTransfertListWithQuantityToInvMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTTRANSFERTLISTWITHQUANTITYTOINVMESSAGE;
}

