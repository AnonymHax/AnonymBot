#include "ChatAdminServerMessage.h"

void ChatAdminServerMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatAdminServerMessage(param1);
}

void ChatAdminServerMessage::serializeAs_ChatAdminServerMessage(Writer *param1)
{
  ChatServerMessage::serializeAs_ChatServerMessage(param1);
}

void ChatAdminServerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatAdminServerMessage(param1);
}

void ChatAdminServerMessage::deserializeAs_ChatAdminServerMessage(Reader *param1)
{
  ChatServerMessage::deserialize(param1);
}

ChatAdminServerMessage::ChatAdminServerMessage()
{
  m_type = MessageEnum::CHATADMINSERVERMESSAGE;
}

