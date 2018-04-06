#include "MapObstacle.h"

void MapObstacle::serialize(Writer *param1)
{
  this->serializeAs_MapObstacle(param1);
}

void MapObstacle::serializeAs_MapObstacle(Writer *param1)
{
  if(this->obstacleCellId < 0 || this->obstacleCellId > 559)
  {
    qDebug()<<"ERREUR - MapObstacle -"<<"Forbidden value (" << this->obstacleCellId << ") on element obstacleCellId.";
  }
  else
  {
    param1->writeVarShort((int)this->obstacleCellId);
    param1->writeByte(this->state);
    return;
  }
}

void MapObstacle::deserialize(Reader *param1)
{
  this->deserializeAs_MapObstacle(param1);
}

void MapObstacle::deserializeAs_MapObstacle(Reader *param1)
{
  this->obstacleCellId = param1->readVarUhShort();
  if(this->obstacleCellId < 0 || this->obstacleCellId > 559)
  {
    qDebug()<<"ERREUR - MapObstacle -"<<"Forbidden value (" << this->obstacleCellId << ") on element of MapObstacle.obstacleCellId.";
  }
  else
  {
    this->state = param1->readByte();
    if(this->state < 0)
    {
      qDebug()<<"ERREUR - MapObstacle -"<<"Forbidden value (" << this->state << ") on element of MapObstacle.state.";
    }
    else
    {
      return;
    }
  }
}

MapObstacle::MapObstacle()
{
  m_types<<ClassEnum::MAPOBSTACLE;
}

bool MapObstacle::operator==(const MapObstacle &compared)
{
  if(obstacleCellId == compared.obstacleCellId)
  if(state == compared.state)
  return true;
  
  return false;
}

