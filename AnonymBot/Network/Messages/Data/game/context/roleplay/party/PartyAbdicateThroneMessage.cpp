#include "PartyAbdicateThroneMessage.h"

void PartyAbdicateThroneMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyAbdicateThroneMessage(param1);
}

void PartyAbdicateThroneMessage::serializeAs_PartyAbdicateThroneMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyAbdicateThroneMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    return;
  }
}

void PartyAbdicateThroneMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyAbdicateThroneMessage(param1);
}

void PartyAbdicateThroneMessage::deserializeAs_PartyAbdicateThroneMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyAbdicateThroneMessage -"<<"Forbidden value (" << this->playerId << ") on element of PartyAbdicateThroneMessage.playerId.";
  }
  else
  {
    return;
  }
}

PartyAbdicateThroneMessage::PartyAbdicateThroneMessage()
{
  m_type = MessageEnum::PARTYABDICATETHRONEMESSAGE;
}

