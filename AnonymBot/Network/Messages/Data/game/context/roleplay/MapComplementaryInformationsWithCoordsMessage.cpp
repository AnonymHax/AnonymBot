#include "MapComplementaryInformationsWithCoordsMessage.h"

void MapComplementaryInformationsWithCoordsMessage::serialize(Writer *param1)
{
  this->serializeAs_MapComplementaryInformationsWithCoordsMessage(param1);
}

void MapComplementaryInformationsWithCoordsMessage::serializeAs_MapComplementaryInformationsWithCoordsMessage(Writer *param1)
{
  MapComplementaryInformationsDataMessage::serializeAs_MapComplementaryInformationsDataMessage(param1);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsWithCoordsMessage -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  else
  {
    param1->writeShort((short)this->worldX);
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - MapComplementaryInformationsWithCoordsMessage -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
    }
    else
    {
      param1->writeShort((short)this->worldY);
      return;
    }
  }
}

void MapComplementaryInformationsWithCoordsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MapComplementaryInformationsWithCoordsMessage(param1);
}

void MapComplementaryInformationsWithCoordsMessage::deserializeAs_MapComplementaryInformationsWithCoordsMessage(Reader *param1)
{
  MapComplementaryInformationsDataMessage::deserialize(param1);
  this->worldX = param1->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsWithCoordsMessage -"<<"Forbidden value (" << this->worldX << ") on element of MapComplementaryInformationsWithCoordsMessage.worldX.";
  }
  else
  {
    this->worldY = param1->readShort();
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - MapComplementaryInformationsWithCoordsMessage -"<<"Forbidden value (" << this->worldY << ") on element of MapComplementaryInformationsWithCoordsMessage.worldY.";
    }
    else
    {
      return;
    }
  }
}

MapComplementaryInformationsWithCoordsMessage::MapComplementaryInformationsWithCoordsMessage()
{
  m_type = MessageEnum::MAPCOMPLEMENTARYINFORMATIONSWITHCOORDSMESSAGE;
}

