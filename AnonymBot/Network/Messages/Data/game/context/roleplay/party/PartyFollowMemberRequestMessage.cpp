#include "PartyFollowMemberRequestMessage.h"

void PartyFollowMemberRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyFollowMemberRequestMessage(param1);
}

void PartyFollowMemberRequestMessage::serializeAs_PartyFollowMemberRequestMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyFollowMemberRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    return;
  }
}

void PartyFollowMemberRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyFollowMemberRequestMessage(param1);
}

void PartyFollowMemberRequestMessage::deserializeAs_PartyFollowMemberRequestMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyFollowMemberRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element of PartyFollowMemberRequestMessage.playerId.";
  }
  else
  {
    return;
  }
}

PartyFollowMemberRequestMessage::PartyFollowMemberRequestMessage()
{
  m_type = MessageEnum::PARTYFOLLOWMEMBERREQUESTMESSAGE;
}

