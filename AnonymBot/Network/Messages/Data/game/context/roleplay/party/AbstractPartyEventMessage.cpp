#include "AbstractPartyEventMessage.h"

void AbstractPartyEventMessage::serialize(Writer *param1)
{
  this->serializeAs_AbstractPartyEventMessage(param1);
}

void AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
}

void AbstractPartyEventMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AbstractPartyEventMessage(param1);
}

void AbstractPartyEventMessage::deserializeAs_AbstractPartyEventMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
}

AbstractPartyEventMessage::AbstractPartyEventMessage()
{
  m_type = MessageEnum::ABSTRACTPARTYEVENTMESSAGE;
}

