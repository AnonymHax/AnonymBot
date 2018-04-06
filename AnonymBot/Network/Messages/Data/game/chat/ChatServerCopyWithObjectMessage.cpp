#include "ChatServerCopyWithObjectMessage.h"

void ChatServerCopyWithObjectMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatServerCopyWithObjectMessage(param1);
}

void ChatServerCopyWithObjectMessage::serializeAs_ChatServerCopyWithObjectMessage(Writer *param1)
{
  ChatServerCopyMessage::serializeAs_ChatServerCopyMessage(param1);
  param1->writeShort((short)this->objects.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objects.size())
  {
    qSharedPointerCast<ObjectItem>(this->objects[_loc2_])->serializeAs_ObjectItem(param1);
    _loc2_++;
  }
}

void ChatServerCopyWithObjectMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatServerCopyWithObjectMessage(param1);
}

void ChatServerCopyWithObjectMessage::deserializeAs_ChatServerCopyWithObjectMessage(Reader *param1)
{
  QSharedPointer<ObjectItem> _loc4_ ;
  ChatServerCopyMessage::deserialize(param1);
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

ChatServerCopyWithObjectMessage::ChatServerCopyWithObjectMessage()
{
  m_type = MessageEnum::CHATSERVERCOPYWITHOBJECTMESSAGE;
}

