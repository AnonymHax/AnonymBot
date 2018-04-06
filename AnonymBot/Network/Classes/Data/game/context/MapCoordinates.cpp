#include "MapCoordinates.h"

void MapCoordinates::serialize(Writer *param1)
{
  this->serializeAs_MapCoordinates(param1);
}

void MapCoordinates::serializeAs_MapCoordinates(Writer *param1)
{
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - MapCoordinates -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  else
  {
    param1->writeShort((short)this->worldX);
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - MapCoordinates -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
    }
    else
    {
      param1->writeShort((short)this->worldY);
      return;
    }
  }
}

void MapCoordinates::deserialize(Reader *param1)
{
  this->deserializeAs_MapCoordinates(param1);
}

void MapCoordinates::deserializeAs_MapCoordinates(Reader *param1)
{
  this->worldX = param1->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - MapCoordinates -"<<"Forbidden value (" << this->worldX << ") on element of MapCoordinates.worldX.";
  }
  else
  {
    this->worldY = param1->readShort();
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - MapCoordinates -"<<"Forbidden value (" << this->worldY << ") on element of MapCoordinates.worldY.";
    }
    else
    {
      return;
    }
  }
}

MapCoordinates::MapCoordinates()
{
  m_types<<ClassEnum::MAPCOORDINATES;
}

bool MapCoordinates::operator==(const MapCoordinates &compared)
{
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  return true;
  
  return false;
}

