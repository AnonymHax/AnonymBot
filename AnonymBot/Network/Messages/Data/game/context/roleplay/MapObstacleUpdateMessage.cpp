#include "MapObstacleUpdateMessage.h"

void MapObstacleUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_MapObstacleUpdateMessage(param1);
}

void MapObstacleUpdateMessage::serializeAs_MapObstacleUpdateMessage(Writer *param1)
{
  param1->writeShort((short)this->obstacles.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->obstacles.size())
  {
    (this->obstacles[_loc2_]).serializeAs_MapObstacle(param1);
    _loc2_++;
  }
}

void MapObstacleUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MapObstacleUpdateMessage(param1);
}

void MapObstacleUpdateMessage::deserializeAs_MapObstacleUpdateMessage(Reader *param1)
{
  MapObstacle _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = MapObstacle();
    _loc4_.deserialize(param1);
    this->obstacles.append(_loc4_);
    _loc3_++;
  }
}

MapObstacleUpdateMessage::MapObstacleUpdateMessage()
{
  m_type = MessageEnum::MAPOBSTACLEUPDATEMESSAGE;
}

