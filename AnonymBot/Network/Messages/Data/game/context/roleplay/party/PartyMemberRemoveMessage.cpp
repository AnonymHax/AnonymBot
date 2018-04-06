#include "PartyMemberRemoveMessage.h"

void PartyMemberRemoveMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyMemberRemoveMessage(param1);
}

void PartyMemberRemoveMessage::serializeAs_PartyMemberRemoveMessage(Writer *param1)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(param1);
  if(this->leavingPlayerId < 0 || this->leavingPlayerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyMemberRemoveMessage -"<<"Forbidden value (" << this->leavingPlayerId << ") on element leavingPlayerId.";
  }
  else
  {
    param1->writeVarLong((double)this->leavingPlayerId);
    return;
  }
}

void PartyMemberRemoveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyMemberRemoveMessage(param1);
}

void PartyMemberRemoveMessage::deserializeAs_PartyMemberRemoveMessage(Reader *param1)
{
  AbstractPartyEventMessage::deserialize(param1);
  this->leavingPlayerId = param1->readVarUhLong();
  if(this->leavingPlayerId < 0 || this->leavingPlayerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyMemberRemoveMessage -"<<"Forbidden value (" << this->leavingPlayerId << ") on element of PartyMemberRemoveMessage.leavingPlayerId.";
  }
  else
  {
    return;
  }
}

PartyMemberRemoveMessage::PartyMemberRemoveMessage()
{
  m_type = MessageEnum::PARTYMEMBERREMOVEMESSAGE;
}

