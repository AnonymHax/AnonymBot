#include "LockableUseCodeMessage.h"

void LockableUseCodeMessage::serialize(Writer *param1)
{
  this->serializeAs_LockableUseCodeMessage(param1);
}

void LockableUseCodeMessage::serializeAs_LockableUseCodeMessage(Writer *param1)
{
  param1->writeUTF(this->code);
}

void LockableUseCodeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LockableUseCodeMessage(param1);
}

void LockableUseCodeMessage::deserializeAs_LockableUseCodeMessage(Reader *param1)
{
  this->code = param1->readUTF();
}

LockableUseCodeMessage::LockableUseCodeMessage()
{
  m_type = MessageEnum::LOCKABLEUSECODEMESSAGE;
}

