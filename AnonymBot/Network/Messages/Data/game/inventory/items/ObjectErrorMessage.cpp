#include "ObjectErrorMessage.h"

void ObjectErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectErrorMessage(param1);
}

void ObjectErrorMessage::serializeAs_ObjectErrorMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void ObjectErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectErrorMessage(param1);
}

void ObjectErrorMessage::deserializeAs_ObjectErrorMessage(Reader *param1)
{
  this->reason = param1->readByte();
}

ObjectErrorMessage::ObjectErrorMessage()
{
  m_type = MessageEnum::OBJECTERRORMESSAGE;
}

