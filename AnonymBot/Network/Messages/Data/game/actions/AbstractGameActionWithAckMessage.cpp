#include "AbstractGameActionWithAckMessage.h"

void AbstractGameActionWithAckMessage::serialize(Writer *param1)
{
  this->serializeAs_AbstractGameActionWithAckMessage(param1);
}

void AbstractGameActionWithAckMessage::serializeAs_AbstractGameActionWithAckMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  param1->writeShort((short)this->waitAckId);
}

void AbstractGameActionWithAckMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AbstractGameActionWithAckMessage(param1);
}

void AbstractGameActionWithAckMessage::deserializeAs_AbstractGameActionWithAckMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->waitAckId = param1->readShort();
}

AbstractGameActionWithAckMessage::AbstractGameActionWithAckMessage()
{
  m_type = MessageEnum::ABSTRACTGAMEACTIONWITHACKMESSAGE;
}

