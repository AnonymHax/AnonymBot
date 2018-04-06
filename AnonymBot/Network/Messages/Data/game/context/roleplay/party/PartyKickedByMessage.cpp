#include "PartyKickedByMessage.h"

void PartyKickedByMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyKickedByMessage(param1);
}

void PartyKickedByMessage::serializeAs_PartyKickedByMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  if(this->kickerId < 0 || this->kickerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyKickedByMessage -"<<"Forbidden value (" << this->kickerId << ") on element kickerId.";
  }
  else
  {
    param1->writeVarLong((double)this->kickerId);
    return;
  }
}

void PartyKickedByMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyKickedByMessage(param1);
}

void PartyKickedByMessage::deserializeAs_PartyKickedByMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->kickerId = param1->readVarUhLong();
  if(this->kickerId < 0 || this->kickerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyKickedByMessage -"<<"Forbidden value (" << this->kickerId << ") on element of PartyKickedByMessage.kickerId.";
  }
  else
  {
    return;
  }
}

PartyKickedByMessage::PartyKickedByMessage()
{
  m_type = MessageEnum::PARTYKICKEDBYMESSAGE;
}

