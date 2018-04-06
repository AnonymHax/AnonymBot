#include "MapRunningFightDetailsRequestMessage.h"

void MapRunningFightDetailsRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_MapRunningFightDetailsRequestMessage(param1);
}

void MapRunningFightDetailsRequestMessage::serializeAs_MapRunningFightDetailsRequestMessage(Writer *param1)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - MapRunningFightDetailsRequestMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  else
  {
    param1->writeInt((int)this->fightId);
    return;
  }
}

void MapRunningFightDetailsRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MapRunningFightDetailsRequestMessage(param1);
}

void MapRunningFightDetailsRequestMessage::deserializeAs_MapRunningFightDetailsRequestMessage(Reader *param1)
{
  this->fightId = param1->readInt();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - MapRunningFightDetailsRequestMessage -"<<"Forbidden value (" << this->fightId << ") on element of MapRunningFightDetailsRequestMessage.fightId.";
  }
  else
  {
    return;
  }
}

MapRunningFightDetailsRequestMessage::MapRunningFightDetailsRequestMessage()
{
  m_type = MessageEnum::MAPRUNNINGFIGHTDETAILSREQUESTMESSAGE;
}

