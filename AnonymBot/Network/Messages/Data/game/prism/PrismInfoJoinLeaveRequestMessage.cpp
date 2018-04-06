#include "PrismInfoJoinLeaveRequestMessage.h"

void PrismInfoJoinLeaveRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismInfoJoinLeaveRequestMessage(param1);
}

void PrismInfoJoinLeaveRequestMessage::serializeAs_PrismInfoJoinLeaveRequestMessage(Writer *param1)
{
  param1->writeBool(this->join);
}

void PrismInfoJoinLeaveRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismInfoJoinLeaveRequestMessage(param1);
}

void PrismInfoJoinLeaveRequestMessage::deserializeAs_PrismInfoJoinLeaveRequestMessage(Reader *param1)
{
  this->join = param1->readBool();
}

PrismInfoJoinLeaveRequestMessage::PrismInfoJoinLeaveRequestMessage()
{
  m_type = MessageEnum::PRISMINFOJOINLEAVEREQUESTMESSAGE;
}

