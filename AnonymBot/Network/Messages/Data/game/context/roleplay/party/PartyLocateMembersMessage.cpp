#include "PartyLocateMembersMessage.h"

void PartyLocateMembersMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyLocateMembersMessage(param1);
}

void PartyLocateMembersMessage::serializeAs_PartyLocateMembersMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  param1->writeShort((short)this->geopositions.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->geopositions.size())
  {
    (this->geopositions[_loc2_]).serializeAs_PartyMemberGeoPosition(param1);
    _loc2_++;
  }
}

void PartyLocateMembersMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyLocateMembersMessage(param1);
}

void PartyLocateMembersMessage::deserializeAs_PartyLocateMembersMessage(Reader *param1)
{
  PartyMemberGeoPosition _loc4_ ;
  AbstractPartyMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = PartyMemberGeoPosition();
    _loc4_.deserialize(param1);
    this->geopositions.append(_loc4_);
    _loc3_++;
  }
}

PartyLocateMembersMessage::PartyLocateMembersMessage()
{
  m_type = MessageEnum::PARTYLOCATEMEMBERSMESSAGE;
}

