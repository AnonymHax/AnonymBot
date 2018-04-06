#include "CurrentServerStatusUpdateMessage.h"

void CurrentServerStatusUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_CurrentServerStatusUpdateMessage(param1);
}

void CurrentServerStatusUpdateMessage::serializeAs_CurrentServerStatusUpdateMessage(Writer *param1)
{
  param1->writeByte(this->status);
}

void CurrentServerStatusUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CurrentServerStatusUpdateMessage(param1);
}

void CurrentServerStatusUpdateMessage::deserializeAs_CurrentServerStatusUpdateMessage(Reader *param1)
{
  this->status = param1->readByte();
  if(this->status < 0)
  {
    qDebug()<<"ERREUR - CurrentServerStatusUpdateMessage -"<<"Forbidden value (" << this->status << ") on element of CurrentServerStatusUpdateMessage.status.";
  }
  else
  {
    return;
  }
}

CurrentServerStatusUpdateMessage::CurrentServerStatusUpdateMessage()
{
  m_type = MessageEnum::CURRENTSERVERSTATUSUPDATEMESSAGE;
}

