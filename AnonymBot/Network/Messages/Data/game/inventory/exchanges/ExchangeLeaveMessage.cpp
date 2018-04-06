#include "ExchangeLeaveMessage.h"

void ExchangeLeaveMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeLeaveMessage(param1);
}

void ExchangeLeaveMessage::serializeAs_ExchangeLeaveMessage(Writer *param1)
{
  LeaveDialogMessage::serializeAs_LeaveDialogMessage(param1);
  param1->writeBool(this->success);
}

void ExchangeLeaveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeLeaveMessage(param1);
}

void ExchangeLeaveMessage::deserializeAs_ExchangeLeaveMessage(Reader *param1)
{
  LeaveDialogMessage::deserialize(param1);
  this->success = param1->readBool();
}

ExchangeLeaveMessage::ExchangeLeaveMessage()
{
  m_type = MessageEnum::EXCHANGELEAVEMESSAGE;
}

