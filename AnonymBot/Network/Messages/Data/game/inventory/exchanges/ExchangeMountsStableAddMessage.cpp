#include "ExchangeMountsStableAddMessage.h"

void ExchangeMountsStableAddMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeMountsStableAddMessage(param1);
}

void ExchangeMountsStableAddMessage::serializeAs_ExchangeMountsStableAddMessage(Writer *param1)
{
  param1->writeShort((short)this->mountDescription.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->mountDescription.size())
  {
    qSharedPointerCast<MountClientData>(this->mountDescription[_loc2_])->serializeAs_MountClientData(param1);
    _loc2_++;
  }
}

void ExchangeMountsStableAddMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeMountsStableAddMessage(param1);
}

void ExchangeMountsStableAddMessage::deserializeAs_ExchangeMountsStableAddMessage(Reader *param1)
{
  QSharedPointer<MountClientData> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<MountClientData>(new MountClientData() );
    _loc4_->deserialize(param1);
    this->mountDescription.append(_loc4_);
    _loc3_++;
  }
}

ExchangeMountsStableAddMessage::ExchangeMountsStableAddMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTSSTABLEADDMESSAGE;
}

