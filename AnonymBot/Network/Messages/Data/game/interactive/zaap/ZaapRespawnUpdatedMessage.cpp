#include "ZaapRespawnUpdatedMessage.h"

void ZaapRespawnUpdatedMessage::serialize(Writer *param1)
{
  this->serializeAs_ZaapRespawnUpdatedMessage(param1);
}

void ZaapRespawnUpdatedMessage::serializeAs_ZaapRespawnUpdatedMessage(Writer *param1)
{
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - ZaapRespawnUpdatedMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  else
  {
    param1->writeInt((int)this->mapId);
    return;
  }
}

void ZaapRespawnUpdatedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ZaapRespawnUpdatedMessage(param1);
}

void ZaapRespawnUpdatedMessage::deserializeAs_ZaapRespawnUpdatedMessage(Reader *param1)
{
  this->mapId = param1->readInt();
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - ZaapRespawnUpdatedMessage -"<<"Forbidden value (" << this->mapId << ") on element of ZaapRespawnUpdatedMessage.mapId.";
  }
  else
  {
    return;
  }
}

ZaapRespawnUpdatedMessage::ZaapRespawnUpdatedMessage()
{
  m_type = MessageEnum::ZAAPRESPAWNUPDATEDMESSAGE;
}

