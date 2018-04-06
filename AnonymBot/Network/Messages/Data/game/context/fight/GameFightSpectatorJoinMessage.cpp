#include "GameFightSpectatorJoinMessage.h"

void GameFightSpectatorJoinMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightSpectatorJoinMessage(param1);
}

void GameFightSpectatorJoinMessage::serializeAs_GameFightSpectatorJoinMessage(Writer *param1)
{
  GameFightJoinMessage::serializeAs_GameFightJoinMessage(param1);
  param1->writeShort((short)this->namedPartyTeams.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->namedPartyTeams.size())
  {
    (this->namedPartyTeams[_loc2_]).serializeAs_NamedPartyTeam(param1);
    _loc2_++;
  }
}

void GameFightSpectatorJoinMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightSpectatorJoinMessage(param1);
}

void GameFightSpectatorJoinMessage::deserializeAs_GameFightSpectatorJoinMessage(Reader *param1)
{
  NamedPartyTeam _loc4_ ;
  GameFightJoinMessage::deserialize(param1);
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

GameFightSpectatorJoinMessage::GameFightSpectatorJoinMessage()
{
  m_type = MessageEnum::GAMEFIGHTSPECTATORJOINMESSAGE;
}

