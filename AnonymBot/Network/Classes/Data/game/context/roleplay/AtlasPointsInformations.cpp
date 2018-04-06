#include "AtlasPointsInformations.h"

void AtlasPointsInformations::serialize(Writer *param1)
{
  this->serializeAs_AtlasPointsInformations(param1);
}

void AtlasPointsInformations::serializeAs_AtlasPointsInformations(Writer *param1)
{
  param1->writeByte(this->type);
  param1->writeShort((short)this->coords.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->coords.size())
  {
    qSharedPointerCast<MapCoordinatesExtended>(this->coords[_loc2_])->serializeAs_MapCoordinatesExtended(param1);
    _loc2_++;
  }
}

void AtlasPointsInformations::deserialize(Reader *param1)
{
  this->deserializeAs_AtlasPointsInformations(param1);
}

void AtlasPointsInformations::deserializeAs_AtlasPointsInformations(Reader *param1)
{
  QSharedPointer<MapCoordinatesExtended> _loc4_ ;
  this->type = param1->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - AtlasPointsInformations -"<<"Forbidden value (" << this->type << ") on element of AtlasPointsInformations.type.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = QSharedPointer<MapCoordinatesExtended>(new MapCoordinatesExtended() );
      _loc4_->deserialize(param1);
      this->coords.append(_loc4_);
      _loc3_++;
    }
    return;
  }
}

AtlasPointsInformations::AtlasPointsInformations()
{
  m_types<<ClassEnum::ATLASPOINTSINFORMATIONS;
}

bool AtlasPointsInformations::operator==(const AtlasPointsInformations &compared)
{
  if(type == compared.type)
  if(coords == compared.coords)
  return true;
  
  return false;
}

