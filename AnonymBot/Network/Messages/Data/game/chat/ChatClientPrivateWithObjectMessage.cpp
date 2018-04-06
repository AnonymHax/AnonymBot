#include "ChatClientPrivateWithObjectMessage.h"

void ChatClientPrivateWithObjectMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatClientPrivateWithObjectMessage(param1);
}

void ChatClientPrivateWithObjectMessage::serializeAs_ChatClientPrivateWithObjectMessage(Writer *param1)
{
  ChatClientPrivateMessage::serializeAs_ChatClientPrivateMessage(param1);
  param1->writeShort((short)this->objects.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objects.size())
  {
    qSharedPointerCast<ObjectItem>(this->objects[_loc2_])->serializeAs_ObjectItem(param1);
    _loc2_++;
  }
}

void ChatClientPrivateWithObjectMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatClientPrivateWithObjectMessage(param1);
}

void ChatClientPrivateWithObjectMessage::deserializeAs_ChatClientPrivateWithObjectMessage(Reader *param1)
{
  QSharedPointer<ObjectItem> _loc4_ ;
  ChatClientPrivateMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<ObjectItem>(new ObjectItem() );
    _loc4_->deserialize(param1);
    this->objects.append(_loc4_);
    _loc3_++;
  }
}

ChatClientPrivateWithObjectMessage::ChatClientPrivateWithObjectMessage()
{
  m_type = MessageEnum::CHATCLIENTPRIVATEWITHOBJECTMESSAGE;
  m_needsHash = true;
}

