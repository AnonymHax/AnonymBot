#include "ObjectModifiedMessage.h"

void ObjectModifiedMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectModifiedMessage(param1);
}

void ObjectModifiedMessage::serializeAs_ObjectModifiedMessage(Writer *param1)
{
  this->object->serializeAs_ObjectItem(param1);
}

void ObjectModifiedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectModifiedMessage(param1);
}

void ObjectModifiedMessage::deserializeAs_ObjectModifiedMessage(Reader *param1)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(param1);
}

ObjectModifiedMessage::ObjectModifiedMessage()
{
  m_type = MessageEnum::OBJECTMODIFIEDMESSAGE;
}

