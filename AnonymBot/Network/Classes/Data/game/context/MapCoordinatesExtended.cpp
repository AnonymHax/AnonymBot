#include "MapCoordinatesExtended.h"

void MapCoordinatesExtended::serialize(Writer *param1)
{
  this->serializeAs_MapCoordinatesExtended(param1);
}

void MapCoordinatesExtended::serializeAs_MapCoordinatesExtended(Writer *param1)
{
  MapCoordinatesAndId::serializeAs_MapCoordinatesAndId(param1);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - MapCoordinatesExtended -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    return;
  }
}

void MapCoordinatesExtended::deserialize(Reader *param1)
{
  this->deserializeAs_MapCoordinatesExtended(param1);
}

void MapCoordinatesExtended::deserializeAs_MapCoordinatesExtended(Reader *param1)
{
  MapCoordinatesAndId::deserialize(param1);
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - MapCoordinatesExtended -"<<"Forbidden value (" << this->subAreaId << ") on element of MapCoordinatesExtended.subAreaId.";
  }
  else
  {
    return;
  }
}

MapCoordinatesExtended::MapCoordinatesExtended()
{
  m_types<<ClassEnum::MAPCOORDINATESEXTENDED;
}

bool MapCoordinatesExtended::operator==(const MapCoordinatesExtended &compared)
{
  if(subAreaId == compared.subAreaId)
  return true;
  
  return false;
}

