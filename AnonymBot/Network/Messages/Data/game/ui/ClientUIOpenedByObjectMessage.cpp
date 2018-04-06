#include "ClientUIOpenedByObjectMessage.h"

void ClientUIOpenedByObjectMessage::serialize(Writer *param1)
{
  this->serializeAs_ClientUIOpenedByObjectMessage(param1);
}

void ClientUIOpenedByObjectMessage::serializeAs_ClientUIOpenedByObjectMessage(Writer *param1)
{
  ClientUIOpenedMessage::serializeAs_ClientUIOpenedMessage(param1);
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - ClientUIOpenedByObjectMessage -"<<"Forbidden value (" << this->uid << ") on element uid.";
  }
  else
  {
    param1->writeVarInt((int)this->uid);
    return;
  }
}

void ClientUIOpenedByObjectMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ClientUIOpenedByObjectMessage(param1);
}

void ClientUIOpenedByObjectMessage::deserializeAs_ClientUIOpenedByObjectMessage(Reader *param1)
{
  ClientUIOpenedMessage::deserialize(param1);
  this->uid = param1->readVarUhInt();
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - ClientUIOpenedByObjectMessage -"<<"Forbidden value (" << this->uid << ") on element of ClientUIOpenedByObjectMessage.uid.";
  }
  else
  {
    return;
  }
}

ClientUIOpenedByObjectMessage::ClientUIOpenedByObjectMessage()
{
  m_type = MessageEnum::CLIENTUIOPENEDBYOBJECTMESSAGE;
}

