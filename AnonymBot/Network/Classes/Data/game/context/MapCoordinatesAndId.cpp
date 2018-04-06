#include "MapCoordinatesAndId.h"

void MapCoordinatesAndId::serialize(Writer *param1)
{
  this->serializeAs_MapCoordinatesAndId(param1);
}

void MapCoordinatesAndId::serializeAs_MapCoordinatesAndId(Writer *param1)
{
  MapCoordinates::serializeAs_MapCoordinates(param1);
  param1->writeInt((int)this->mapId);
}

void MapCoordinatesAndId::deserialize(Reader *param1)
{
  this->deserializeAs_MapCoordinatesAndId(param1);
}

void MapCoordinatesAndId::deserializeAs_MapCoordinatesAndId(Reader *param1)
{
  MapCoordinates::deserialize(param1);
  this->mapId = param1->readInt();
}

MapCoordinatesAndId::MapCoordinatesAndId()
{
  m_types<<ClassEnum::MAPCOORDINATESANDID;
}

bool MapCoordinatesAndId::operator==(const MapCoordinatesAndId &compared)
{
  if(mapId == compared.mapId)
  return true;
  
  return false;
}

