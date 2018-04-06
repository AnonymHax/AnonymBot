#include "ChatClientMultiWithObjectMessage.h"

void ChatClientMultiWithObjectMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatClientMultiWithObjectMessage(param1);
}

void ChatClientMultiWithObjectMessage::serializeAs_ChatClientMultiWithObjectMessage(Writer *param1)
{
  ChatClientMultiMessage::serializeAs_ChatClientMultiMessage(param1);
  param1->writeShort((short)this->objects.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objects.size())
  {
    qSharedPointerCast<ObjectItem>(this->objects[_loc2_])->serializeAs_ObjectItem(param1);
    _loc2_++;
  }
}

void ChatClientMultiWithObjectMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatClientMultiWithObjectMessage(param1);
}

void ChatClientMultiWithObjectMessage::deserializeAs_ChatClientMultiWithObjectMessage(Reader *param1)
{
  QSharedPointer<ObjectItem> _loc4_ ;
  ChatClientMultiMessage::deserialize(param1);
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

ChatClientMultiWithObjectMessage::ChatClientMultiWithObjectMessage()
{
  m_type = MessageEnum::CHATCLIENTMULTIWITHOBJECTMESSAGE;
  m_needsHash = true;
}

