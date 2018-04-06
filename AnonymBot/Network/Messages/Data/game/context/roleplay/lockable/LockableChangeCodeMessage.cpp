#include "LockableChangeCodeMessage.h"

void LockableChangeCodeMessage::serialize(Writer *param1)
{
  this->serializeAs_LockableChangeCodeMessage(param1);
}

void LockableChangeCodeMessage::serializeAs_LockableChangeCodeMessage(Writer *param1)
{
  param1->writeUTF(this->code);
}

void LockableChangeCodeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LockableChangeCodeMessage(param1);
}

void LockableChangeCodeMessage::deserializeAs_LockableChangeCodeMessage(Reader *param1)
{
  this->code = param1->readUTF();
}

LockableChangeCodeMessage::LockableChangeCodeMessage()
{
  m_type = MessageEnum::LOCKABLECHANGECODEMESSAGE;
}

