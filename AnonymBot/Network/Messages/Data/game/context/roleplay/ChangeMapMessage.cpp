#include "ChangeMapMessage.h"

void ChangeMapMessage::serialize(Writer *param1)
{
  this->serializeAs_ChangeMapMessage(param1);
}

void ChangeMapMessage::serializeAs_ChangeMapMessage(Writer *param1)
{
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - ChangeMapMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  else
  {
    param1->writeInt((int)this->mapId);
    return;
  }
}

void ChangeMapMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChangeMapMessage(param1);
}

void ChangeMapMessage::deserializeAs_ChangeMapMessage(Reader *param1)
{
  this->mapId = param1->readInt();
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - ChangeMapMessage -"<<"Forbidden value (" << this->mapId << ") on element of ChangeMapMessage.mapId.";
  }
  else
  {
    return;
  }
}

ChangeMapMessage::ChangeMapMessage()
{
  m_type = MessageEnum::CHANGEMAPMESSAGE;
}

