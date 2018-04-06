#include "MapRunningFightDetailsExtendedMessage.h"

void MapRunningFightDetailsExtendedMessage::serialize(Writer *param1)
{
  this->serializeAs_MapRunningFightDetailsExtendedMessage(param1);
}

void MapRunningFightDetailsExtendedMessage::serializeAs_MapRunningFightDetailsExtendedMessage(Writer *param1)
{
  MapRunningFightDetailsMessage::serializeAs_MapRunningFightDetailsMessage(param1);
  param1->writeShort((short)this->namedPartyTeams.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->namedPartyTeams.size())
  {
    (this->namedPartyTeams[_loc2_]).serializeAs_NamedPartyTeam(param1);
    _loc2_++;
  }
}

void MapRunningFightDetailsExtendedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MapRunningFightDetailsExtendedMessage(param1);
}

void MapRunningFightDetailsExtendedMessage::deserializeAs_MapRunningFightDetailsExtendedMessage(Reader *param1)
{
  NamedPartyTeam _loc4_ ;
  MapRunningFightDetailsMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = NamedPartyTeam();
    _loc4_.deserialize(param1);
    this->namedPartyTeams.append(_loc4_);
    _loc3_++;
  }
}

MapRunningFightDetailsExtendedMessage::MapRunningFightDetailsExtendedMessage()
{
  m_type = MessageEnum::MAPRUNNINGFIGHTDETAILSEXTENDEDMESSAGE;
}

