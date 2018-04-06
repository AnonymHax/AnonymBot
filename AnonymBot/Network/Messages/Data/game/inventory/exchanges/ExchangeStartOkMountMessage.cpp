#include "ExchangeStartOkMountMessage.h"

void ExchangeStartOkMountMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartOkMountMessage(param1);
}

void ExchangeStartOkMountMessage::serializeAs_ExchangeStartOkMountMessage(Writer *param1)
{
  ExchangeStartOkMountWithOutPaddockMessage::serializeAs_ExchangeStartOkMountWithOutPaddockMessage(param1);
  param1->writeShort((short)this->paddockedMountsDescription.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->paddockedMountsDescription.size())
  {
    qSharedPointerCast<MountClientData>(this->paddockedMountsDescription[_loc2_])->serializeAs_MountClientData(param1);
    _loc2_++;
  }
}

void ExchangeStartOkMountMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartOkMountMessage(param1);
}

void ExchangeStartOkMountMessage::deserializeAs_ExchangeStartOkMountMessage(Reader *param1)
{
  QSharedPointer<MountClientData> _loc4_ ;
  ExchangeStartOkMountWithOutPaddockMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<MountClientData>(new MountClientData() );
    _loc4_->deserialize(param1);
    this->paddockedMountsDescription.append(_loc4_);
    _loc3_++;
  }
}

ExchangeStartOkMountMessage::ExchangeStartOkMountMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKMOUNTMESSAGE;
}

