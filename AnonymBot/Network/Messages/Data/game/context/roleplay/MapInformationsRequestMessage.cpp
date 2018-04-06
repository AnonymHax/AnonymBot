#include "MapInformationsRequestMessage.h"

void MapInformationsRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_MapInformationsRequestMessage(param1);
}

void MapInformationsRequestMessage::serializeAs_MapInformationsRequestMessage(Writer *param1)
{
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - MapInformationsRequestMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  else
  {
    param1->writeInt((int)this->mapId);
    return;
  }
}

void MapInformationsRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MapInformationsRequestMessage(param1);
}

void MapInformationsRequestMessage::deserializeAs_MapInformationsRequestMessage(Reader *param1)
{
  this->mapId = param1->readInt();
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - MapInformationsRequestMessage -"<<"Forbidden value (" << this->mapId << ") on element of MapInformationsRequestMessage.mapId.";
  }
  else
  {
    return;
  }
}

MapInformationsRequestMessage::MapInformationsRequestMessage()
{
  m_type = MessageEnum::MAPINFORMATIONSREQUESTMESSAGE;
}

