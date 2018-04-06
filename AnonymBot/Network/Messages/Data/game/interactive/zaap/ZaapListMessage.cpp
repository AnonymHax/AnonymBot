#include "ZaapListMessage.h"

void ZaapListMessage::serialize(Writer *param1)
{
  this->serializeAs_ZaapListMessage(param1);
}

void ZaapListMessage::serializeAs_ZaapListMessage(Writer *param1)
{
  TeleportDestinationsListMessage::serializeAs_TeleportDestinationsListMessage(param1);
  if(this->spawnMapId < 0)
  {
    qDebug()<<"ERREUR - ZaapListMessage -"<<"Forbidden value (" << this->spawnMapId << ") on element spawnMapId.";
  }
  else
  {
    param1->writeInt((int)this->spawnMapId);
    return;
  }
}

void ZaapListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ZaapListMessage(param1);
}

void ZaapListMessage::deserializeAs_ZaapListMessage(Reader *param1)
{
  TeleportDestinationsListMessage::deserialize(param1);
  this->spawnMapId = param1->readInt();
  if(this->spawnMapId < 0)
  {
    qDebug()<<"ERREUR - ZaapListMessage -"<<"Forbidden value (" << this->spawnMapId << ") on element of ZaapListMessage.spawnMapId.";
  }
  else
  {
    return;
  }
}

ZaapListMessage::ZaapListMessage()
{
  m_type = MessageEnum::ZAAPLISTMESSAGE;
}

