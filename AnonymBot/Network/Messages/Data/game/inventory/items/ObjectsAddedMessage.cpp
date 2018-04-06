#include "ObjectsAddedMessage.h"

void ObjectsAddedMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectsAddedMessage(param1);
}

void ObjectsAddedMessage::serializeAs_ObjectsAddedMessage(Writer *param1)
{
  param1->writeShort((short)this->object.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->object.size())
  {
    qSharedPointerCast<ObjectItem>(this->object[_loc2_])->serializeAs_ObjectItem(param1);
    _loc2_++;
  }
}

void ObjectsAddedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectsAddedMessage(param1);
}

void ObjectsAddedMessage::deserializeAs_ObjectsAddedMessage(Reader *param1)
{
  QSharedPointer<ObjectItem> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<ObjectItem>(new ObjectItem() );
    _loc4_->deserialize(param1);
    this->object.append(_loc4_);
    _loc3_++;
  }
}

ObjectsAddedMessage::ObjectsAddedMessage()
{
  m_type = MessageEnum::OBJECTSADDEDMESSAGE;
}

