#include "AdminQuietCommandMessage.h"

void AdminQuietCommandMessage::serialize(Writer *param1)
{
  this->serializeAs_AdminQuietCommandMessage(param1);
}

void AdminQuietCommandMessage::serializeAs_AdminQuietCommandMessage(Writer *param1)
{
  AdminCommandMessage::serializeAs_AdminCommandMessage(param1);
}

void AdminQuietCommandMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AdminQuietCommandMessage(param1);
}

void AdminQuietCommandMessage::deserializeAs_AdminQuietCommandMessage(Reader *param1)
{
  AdminCommandMessage::deserialize(param1);
}

AdminQuietCommandMessage::AdminQuietCommandMessage()
{
  m_type = MessageEnum::ADMINQUIETCOMMANDMESSAGE;
}

