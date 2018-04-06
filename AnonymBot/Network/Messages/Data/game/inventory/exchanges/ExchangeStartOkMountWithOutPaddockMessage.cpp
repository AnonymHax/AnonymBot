#include "ExchangeStartOkMountWithOutPaddockMessage.h"

void ExchangeStartOkMountWithOutPaddockMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartOkMountWithOutPaddockMessage(param1);
}

void ExchangeStartOkMountWithOutPaddockMessage::serializeAs_ExchangeStartOkMountWithOutPaddockMessage(Writer *param1)
{
  param1->writeShort((short)this->stabledMountsDescription.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->stabledMountsDescription.size())
  {
    qSharedPointerCast<MountClientData>(this->stabledMountsDescription[_loc2_])->serializeAs_MountClientData(param1);
    _loc2_++;
  }
}

void ExchangeStartOkMountWithOutPaddockMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartOkMountWithOutPaddockMessage(param1);
}

void ExchangeStartOkMountWithOutPaddockMessage::deserializeAs_ExchangeStartOkMountWithOutPaddockMessage(Reader *param1)
{
  QSharedPointer<MountClientData> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<MountClientData>(new MountClientData() );
    _loc4_->deserialize(param1);
    this->stabledMountsDescription.append(_loc4_);
    _loc3_++;
  }
}

ExchangeStartOkMountWithOutPaddockMessage::ExchangeStartOkMountWithOutPaddockMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKMOUNTWITHOUTPADDOCKMESSAGE;
}

