#include "HelloGameMessage.h"

void HelloGameMessage::serialize(Writer *param1)
{
}

void HelloGameMessage::serializeAs_HelloGameMessage(Writer *param1)
{
}

void HelloGameMessage::deserialize(Reader *param1)
{
}

void HelloGameMessage::deserializeAs_HelloGameMessage(Reader *param1)
{
}

HelloGameMessage::HelloGameMessage()
{
  m_type = MessageEnum::HELLOGAMEMESSAGE;
}

