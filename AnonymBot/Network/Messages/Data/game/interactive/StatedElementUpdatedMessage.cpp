#include "StatedElementUpdatedMessage.h"

void StatedElementUpdatedMessage::serialize(Writer *param1)
{
  this->serializeAs_StatedElementUpdatedMessage(param1);
}

void StatedElementUpdatedMessage::serializeAs_StatedElementUpdatedMessage(Writer *param1)
{
  this->statedElement.serializeAs_StatedElement(param1);
}

void StatedElementUpdatedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StatedElementUpdatedMessage(param1);
}

void StatedElementUpdatedMessage::deserializeAs_StatedElementUpdatedMessage(Reader *param1)
{
  this->statedElement = StatedElement();
  this->statedElement.deserialize(param1);
}

StatedElementUpdatedMessage::StatedElementUpdatedMessage()
{
  m_type = MessageEnum::STATEDELEMENTUPDATEDMESSAGE;
}

