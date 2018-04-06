#include "ChatServerWithObjectMessage.h"

void ChatServerWithObjectMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatServerWithObjectMessage(param1);
}

void ChatServerWithObjectMessage::serializeAs_ChatServerWithObjectMessage(Writer *param1)
{
  ChatServerMessage::serializeAs_ChatServerMessage(param1);
  param1->writeShort((short)this->objects.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objects.size())
  {
    qSharedPointerCast<ObjectItem>(this->objects[_loc2_])->serializeAs_ObjectItem(param1);
    _loc2_++;
  }
}

void ChatServerWithObjectMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatServerWithObjectMessage(param1);
}

void ChatServerWithObjectMessage::deserializeAs_ChatServerWithObjectMessage(Reader *param1)
{
  QSharedPointer<ObjectItem> _loc4_ ;
  ChatServerMessage::deserialize(param1);
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

ChatServerWithObjectMessage::ChatServerWithObjectMessage()
{
  m_type = MessageEnum::CHATSERVERWITHOBJECTMESSAGE;
}

