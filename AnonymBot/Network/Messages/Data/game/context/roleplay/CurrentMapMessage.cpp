#include "CurrentMapMessage.h"

void CurrentMapMessage::serialize(Writer *param1)
{
  this->serializeAs_CurrentMapMessage(param1);
}

void CurrentMapMessage::serializeAs_CurrentMapMessage(Writer *param1)
{
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - CurrentMapMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  else
  {
    param1->writeInt((int)this->mapId);
    param1->writeUTF(this->mapKey);
    return;
  }
}

void CurrentMapMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CurrentMapMessage(param1);
}

void CurrentMapMessage::deserializeAs_CurrentMapMessage(Reader *param1)
{
  this->mapId = param1->readInt();
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - CurrentMapMessage -"<<"Forbidden value (" << this->mapId << ") on element of CurrentMapMessage.mapId.";
  }
  else
  {
    this->mapKey = param1->readUTF();
    return;
  }
}

CurrentMapMessage::CurrentMapMessage()
{
  m_type = MessageEnum::CURRENTMAPMESSAGE;
}

