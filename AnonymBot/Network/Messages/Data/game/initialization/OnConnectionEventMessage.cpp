#include "OnConnectionEventMessage.h"

void OnConnectionEventMessage::serialize(Writer *param1)
{
  this->serializeAs_OnConnectionEventMessage(param1);
}

void OnConnectionEventMessage::serializeAs_OnConnectionEventMessage(Writer *param1)
{
  param1->writeByte(this->eventType);
}

void OnConnectionEventMessage::deserialize(Reader *param1)
{
  this->deserializeAs_OnConnectionEventMessage(param1);
}

void OnConnectionEventMessage::deserializeAs_OnConnectionEventMessage(Reader *param1)
{
  this->eventType = param1->readByte();
  if(this->eventType < 0)
  {
    qDebug()<<"ERREUR - OnConnectionEventMessage -"<<"Forbidden value (" << this->eventType << ") on element of OnConnectionEventMessage.eventType.";
  }
  else
  {
    return;
  }
}

OnConnectionEventMessage::OnConnectionEventMessage()
{
  m_type = MessageEnum::ONCONNECTIONEVENTMESSAGE;
}

