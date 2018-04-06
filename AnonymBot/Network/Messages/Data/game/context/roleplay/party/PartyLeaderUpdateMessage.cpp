#include "PartyLeaderUpdateMessage.h"

void PartyLeaderUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyLeaderUpdateMessage(param1);
}

void PartyLeaderUpdateMessage::serializeAs_PartyLeaderUpdateMessage(Writer *param1)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(param1);
  if(this->partyLeaderId < 0 || this->partyLeaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyLeaderUpdateMessage -"<<"Forbidden value (" << this->partyLeaderId << ") on element partyLeaderId.";
  }
  else
  {
    param1->writeVarLong((double)this->partyLeaderId);
    return;
  }
}

void PartyLeaderUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyLeaderUpdateMessage(param1);
}

void PartyLeaderUpdateMessage::deserializeAs_PartyLeaderUpdateMessage(Reader *param1)
{
  AbstractPartyEventMessage::deserialize(param1);
  this->partyLeaderId = param1->readVarUhLong();
  if(this->partyLeaderId < 0 || this->partyLeaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyLeaderUpdateMessage -"<<"Forbidden value (" << this->partyLeaderId << ") on element of PartyLeaderUpdateMessage.partyLeaderId.";
  }
  else
  {
    return;
  }
}

PartyLeaderUpdateMessage::PartyLeaderUpdateMessage()
{
  m_type = MessageEnum::PARTYLEADERUPDATEMESSAGE;
}

