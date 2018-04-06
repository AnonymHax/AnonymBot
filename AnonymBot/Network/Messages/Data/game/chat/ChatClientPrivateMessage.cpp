#include "ChatClientPrivateMessage.h"

void ChatClientPrivateMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatClientPrivateMessage(param1);
}

void ChatClientPrivateMessage::serializeAs_ChatClientPrivateMessage(Writer *param1)
{
  ChatAbstractClientMessage::serializeAs_ChatAbstractClientMessage(param1);
  param1->writeUTF(this->receiver);
}

void ChatClientPrivateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatClientPrivateMessage(param1);
}

void ChatClientPrivateMessage::deserializeAs_ChatClientPrivateMessage(Reader *param1)
{
  ChatAbstractClientMessage::deserialize(param1);
  this->receiver = param1->readUTF();
}

ChatClientPrivateMessage::ChatClientPrivateMessage()
{
  m_type = MessageEnum::CHATCLIENTPRIVATEMESSAGE;
  m_needsHash = true;
}

