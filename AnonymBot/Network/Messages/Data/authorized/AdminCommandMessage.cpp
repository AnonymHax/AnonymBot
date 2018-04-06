#include "AdminCommandMessage.h"

void AdminCommandMessage::serialize(Writer *param1)
{
  this->serializeAs_AdminCommandMessage(param1);
}

void AdminCommandMessage::serializeAs_AdminCommandMessage(Writer *param1)
{
  param1->writeUTF(this->content);
}

void AdminCommandMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AdminCommandMessage(param1);
}

void AdminCommandMessage::deserializeAs_AdminCommandMessage(Reader *param1)
{
  this->content = param1->readUTF();
}

AdminCommandMessage::AdminCommandMessage()
{
  m_type = MessageEnum::ADMINCOMMANDMESSAGE;
}

