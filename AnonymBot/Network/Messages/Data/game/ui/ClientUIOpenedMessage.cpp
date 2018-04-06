#include "ClientUIOpenedMessage.h"

void ClientUIOpenedMessage::serialize(Writer *param1)
{
  this->serializeAs_ClientUIOpenedMessage(param1);
}

void ClientUIOpenedMessage::serializeAs_ClientUIOpenedMessage(Writer *param1)
{
  param1->writeByte(this->type);
}

void ClientUIOpenedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ClientUIOpenedMessage(param1);
}

void ClientUIOpenedMessage::deserializeAs_ClientUIOpenedMessage(Reader *param1)
{
  this->type = param1->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - ClientUIOpenedMessage -"<<"Forbidden value (" << this->type << ") on element of ClientUIOpenedMessage.type.";
  }
  else
  {
    return;
  }
}

ClientUIOpenedMessage::ClientUIOpenedMessage()
{
  m_type = MessageEnum::CLIENTUIOPENEDMESSAGE;
}

