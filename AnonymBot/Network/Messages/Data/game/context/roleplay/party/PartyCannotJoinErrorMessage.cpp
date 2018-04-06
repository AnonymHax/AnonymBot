#include "PartyCannotJoinErrorMessage.h"

void PartyCannotJoinErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyCannotJoinErrorMessage(param1);
}

void PartyCannotJoinErrorMessage::serializeAs_PartyCannotJoinErrorMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  param1->writeByte(this->reason);
}

void PartyCannotJoinErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyCannotJoinErrorMessage(param1);
}

void PartyCannotJoinErrorMessage::deserializeAs_PartyCannotJoinErrorMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - PartyCannotJoinErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of PartyCannotJoinErrorMessage.reason.";
  }
  else
  {
    return;
  }
}

PartyCannotJoinErrorMessage::PartyCannotJoinErrorMessage()
{
  m_type = MessageEnum::PARTYCANNOTJOINERRORMESSAGE;
}

