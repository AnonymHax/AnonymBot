#include "ServerStatusUpdateMessage.h"

void ServerStatusUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_ServerStatusUpdateMessage(param1);
}

void ServerStatusUpdateMessage::serializeAs_ServerStatusUpdateMessage(Writer *param1)
{
  this->server.serializeAs_GameServerInformations(param1);
}

void ServerStatusUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ServerStatusUpdateMessage(param1);
}

void ServerStatusUpdateMessage::deserializeAs_ServerStatusUpdateMessage(Reader *param1)
{
  this->server = GameServerInformations();
  this->server.deserialize(param1);
}

ServerStatusUpdateMessage::ServerStatusUpdateMessage()
{
  m_type = MessageEnum::SERVERSTATUSUPDATEMESSAGE;
}

