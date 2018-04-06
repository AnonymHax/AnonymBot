#include "ClientKeyMessage.h"

void ClientKeyMessage::serialize(Writer *param1)
{
  this->serializeAs_ClientKeyMessage(param1);
}

void ClientKeyMessage::serializeAs_ClientKeyMessage(Writer *param1)
{
  param1->writeUTF(this->key);
}

void ClientKeyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ClientKeyMessage(param1);
}

void ClientKeyMessage::deserializeAs_ClientKeyMessage(Reader *param1)
{
  this->key = param1->readUTF();
}

ClientKeyMessage::ClientKeyMessage()
{
  m_type = MessageEnum::CLIENTKEYMESSAGE;
  m_needsHash = true;
}

