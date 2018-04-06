#include "MapRunningFightListMessage.h"

void MapRunningFightListMessage::serialize(Writer *param1)
{
  this->serializeAs_MapRunningFightListMessage(param1);
}

void MapRunningFightListMessage::serializeAs_MapRunningFightListMessage(Writer *param1)
{
  param1->writeShort((short)this->fights.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->fights.size())
  {
    (this->fights[_loc2_]).serializeAs_FightExternalInformations(param1);
    _loc2_++;
  }
}

void MapRunningFightListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MapRunningFightListMessage(param1);
}

void MapRunningFightListMessage::deserializeAs_MapRunningFightListMessage(Reader *param1)
{
  FightExternalInformations _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = FightExternalInformations();
    _loc4_.deserialize(param1);
    this->fights.append(_loc4_);
    _loc3_++;
  }
}

MapRunningFightListMessage::MapRunningFightListMessage()
{
  m_type = MessageEnum::MAPRUNNINGFIGHTLISTMESSAGE;
}

