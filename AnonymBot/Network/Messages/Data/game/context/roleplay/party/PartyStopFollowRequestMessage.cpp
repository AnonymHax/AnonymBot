#include "PartyStopFollowRequestMessage.h"

void PartyStopFollowRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyStopFollowRequestMessage(param1);
}

void PartyStopFollowRequestMessage::serializeAs_PartyStopFollowRequestMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyStopFollowRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    return;
  }
}

void PartyStopFollowRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyStopFollowRequestMessage(param1);
}

void PartyStopFollowRequestMessage::deserializeAs_PartyStopFollowRequestMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyStopFollowRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element of PartyStopFollowRequestMessage.playerId.";
  }
  else
  {
    return;
  }
}

PartyStopFollowRequestMessage::PartyStopFollowRequestMessage()
{
  m_type = MessageEnum::PARTYSTOPFOLLOWREQUESTMESSAGE;
}

