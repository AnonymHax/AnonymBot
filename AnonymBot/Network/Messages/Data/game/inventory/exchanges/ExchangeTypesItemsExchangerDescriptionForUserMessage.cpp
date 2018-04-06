#include "ExchangeTypesItemsExchangerDescriptionForUserMessage.h"

void ExchangeTypesItemsExchangerDescriptionForUserMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(param1);
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::serializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(Writer *param1)
{
  param1->writeShort((short)this->itemTypeDescriptions.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->itemTypeDescriptions.size())
  {
    qSharedPointerCast<BidExchangerObjectInfo>(this->itemTypeDescriptions[_loc2_])->serializeAs_BidExchangerObjectInfo(param1);
    _loc2_++;
  }
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(param1);
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::deserializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(Reader *param1)
{
  QSharedPointer<BidExchangerObjectInfo> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<BidExchangerObjectInfo>(new BidExchangerObjectInfo() );
    _loc4_->deserialize(param1);
    this->itemTypeDescriptions.append(_loc4_);
    _loc3_++;
  }
}

ExchangeTypesItemsExchangerDescriptionForUserMessage::ExchangeTypesItemsExchangerDescriptionForUserMessage()
{
  m_type = MessageEnum::EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE;
}

