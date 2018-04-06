#include "LockableStateUpdateAbstractMessage.h"

void LockableStateUpdateAbstractMessage::serialize(Writer *param1)
{
  this->serializeAs_LockableStateUpdateAbstractMessage(param1);
}

void LockableStateUpdateAbstractMessage::serializeAs_LockableStateUpdateAbstractMessage(Writer *param1)
{
  param1->writeBool(this->locked);
}

void LockableStateUpdateAbstractMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LockableStateUpdateAbstractMessage(param1);
}

void LockableStateUpdateAbstractMessage::deserializeAs_LockableStateUpdateAbstractMessage(Reader *param1)
{
  this->locked = param1->readBool();
}

LockableStateUpdateAbstractMessage::LockableStateUpdateAbstractMessage()
{
  m_type = MessageEnum::LOCKABLESTATEUPDATEABSTRACTMESSAGE;
}

