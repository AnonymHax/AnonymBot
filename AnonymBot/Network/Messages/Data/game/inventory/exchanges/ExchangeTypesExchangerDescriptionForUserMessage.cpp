#include "ExchangeTypesExchangerDescriptionForUserMessage.h"

void ExchangeTypesExchangerDescriptionForUserMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeTypesExchangerDescriptionForUserMessage(param1);
}

void ExchangeTypesExchangerDescriptionForUserMessage::serializeAs_ExchangeTypesExchangerDescriptionForUserMessage(Writer *param1)
{
  param1->writeShort((short)this->typeDescription.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->typeDescription.size())
  {
    if(this->typeDescription[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - ExchangeTypesExchangerDescriptionForUserMessage -"<<"Forbidden value (" << this->typeDescription[_loc2_] << ") on element 1 (starting at 1) of typeDescription.";
    }
    else
    {
      param1->writeVarInt((int)this->typeDescription[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void ExchangeTypesExchangerDescriptionForUserMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeTypesExchangerDescriptionForUserMessage(param1);
}

void ExchangeTypesExchangerDescriptionForUserMessage::deserializeAs_ExchangeTypesExchangerDescriptionForUserMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhInt();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - ExchangeTypesExchangerDescriptionForUserMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of typeDescription.";
    }
    else
    {
      this->typeDescription.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

ExchangeTypesExchangerDescriptionForUserMessage::ExchangeTypesExchangerDescriptionForUserMessage()
{
  m_type = MessageEnum::EXCHANGETYPESEXCHANGERDESCRIPTIONFORUSERMESSAGE;
}

