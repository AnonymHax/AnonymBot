#include "AuthenticationTicketMessage.h"

void AuthenticationTicketMessage::serialize(Writer *param1)
{
  this->serializeAs_AuthenticationTicketMessage(param1);
}

void AuthenticationTicketMessage::serializeAs_AuthenticationTicketMessage(Writer *param1)
{
  param1->writeUTF(this->lang);
  param1->writeUTF(this->ticket);
}

void AuthenticationTicketMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AuthenticationTicketMessage(param1);
}

void AuthenticationTicketMessage::deserializeAs_AuthenticationTicketMessage(Reader *param1)
{
  this->lang = param1->readUTF();
  this->ticket = param1->readUTF();
}

AuthenticationTicketMessage::AuthenticationTicketMessage()
{
  m_type = MessageEnum::AUTHENTICATIONTICKETMESSAGE;
}

