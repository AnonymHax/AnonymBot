#include "ServerSelectionMessage.h"

void ServerSelectionMessage::serialize(Writer *param1)
{
  this->serializeAs_ServerSelectionMessage(param1);
}

void ServerSelectionMessage::serializeAs_ServerSelectionMessage(Writer *param1)
{
  if(this->serverId < 0)
  {
    qDebug()<<"ERREUR - ServerSelectionMessage -"<<"Forbidden value (" << this->serverId << ") on element serverId.";
  }
  else
  {
    param1->writeVarShort((int)this->serverId);
    return;
  }
}

void ServerSelectionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ServerSelectionMessage(param1);
}

void ServerSelectionMessage::deserializeAs_ServerSelectionMessage(Reader *param1)
{
  this->serverId = param1->readVarUhShort();
  if(this->serverId < 0)
  {
    qDebug()<<"ERREUR - ServerSelectionMessage -"<<"Forbidden value (" << this->serverId << ") on element of ServerSelectionMessage.serverId.";
  }
  else
  {
    return;
  }
}

ServerSelectionMessage::ServerSelectionMessage()
{
  m_type = MessageEnum::SERVERSELECTIONMESSAGE;
}

