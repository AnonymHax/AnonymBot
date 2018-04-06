#include "ChatAbstractClientMessage.h"

void ChatAbstractClientMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatAbstractClientMessage(param1);
}

void ChatAbstractClientMessage::serializeAs_ChatAbstractClientMessage(Writer *param1)
{
  param1->writeUTF(this->content);
}

void ChatAbstractClientMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatAbstractClientMessage(param1);
}

void ChatAbstractClientMessage::deserializeAs_ChatAbstractClientMessage(Reader *param1)
{
  this->content = param1->readUTF();
}

ChatAbstractClientMessage::ChatAbstractClientMessage()
{
  m_type = MessageEnum::CHATABSTRACTCLIENTMESSAGE;
}

