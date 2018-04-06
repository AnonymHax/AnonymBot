#include "IgnoredDeleteResultMessage.h"

void IgnoredDeleteResultMessage::serialize(Writer *param1)
{
  this->serializeAs_IgnoredDeleteResultMessage(param1);
}

void IgnoredDeleteResultMessage::serializeAs_IgnoredDeleteResultMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->success);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->session);
  param1->writeByte(_loc2_);
  param1->writeUTF(this->name);
}

void IgnoredDeleteResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IgnoredDeleteResultMessage(param1);
}

void IgnoredDeleteResultMessage::deserializeAs_IgnoredDeleteResultMessage(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->success = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->session = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->name = param1->readUTF();
}

IgnoredDeleteResultMessage::IgnoredDeleteResultMessage()
{
  m_type = MessageEnum::IGNOREDDELETERESULTMESSAGE;
}

