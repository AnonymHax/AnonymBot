#include "InteractiveElementUpdatedMessage.h"

void InteractiveElementUpdatedMessage::serialize(Writer *param1)
{
  this->serializeAs_InteractiveElementUpdatedMessage(param1);
}

void InteractiveElementUpdatedMessage::serializeAs_InteractiveElementUpdatedMessage(Writer *param1)
{
  this->interactiveElement->serializeAs_InteractiveElement(param1);
}

void InteractiveElementUpdatedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InteractiveElementUpdatedMessage(param1);
}

void InteractiveElementUpdatedMessage::deserializeAs_InteractiveElementUpdatedMessage(Reader *param1)
{
  this->interactiveElement = QSharedPointer<InteractiveElement>(new InteractiveElement() );
  this->interactiveElement->deserialize(param1);
}

InteractiveElementUpdatedMessage::InteractiveElementUpdatedMessage()
{
  m_type = MessageEnum::INTERACTIVEELEMENTUPDATEDMESSAGE;
}

