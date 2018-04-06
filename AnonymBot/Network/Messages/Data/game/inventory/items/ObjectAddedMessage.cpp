#include "ObjectAddedMessage.h"

void ObjectAddedMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectAddedMessage(param1);
}

void ObjectAddedMessage::serializeAs_ObjectAddedMessage(Writer *param1)
{
  this->object->serializeAs_ObjectItem(param1);
}

void ObjectAddedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectAddedMessage(param1);
}

void ObjectAddedMessage::deserializeAs_ObjectAddedMessage(Reader *param1)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(param1);
}

ObjectAddedMessage::ObjectAddedMessage()
{
  m_type = MessageEnum::OBJECTADDEDMESSAGE;
}

