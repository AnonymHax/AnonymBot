#include "PartyMemberEjectedMessage.h"

void PartyMemberEjectedMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyMemberEjectedMessage(param1);
}

void PartyMemberEjectedMessage::serializeAs_PartyMemberEjectedMessage(Writer *param1)
{
  PartyMemberRemoveMessage::serializeAs_PartyMemberRemoveMessage(param1);
  if(this->kickerId < 0 || this->kickerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyMemberEjectedMessage -"<<"Forbidden value (" << this->kickerId << ") on element kickerId.";
  }
  else
  {
    param1->writeVarLong((double)this->kickerId);
    return;
  }
}

void PartyMemberEjectedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyMemberEjectedMessage(param1);
}

void PartyMemberEjectedMessage::deserializeAs_PartyMemberEjectedMessage(Reader *param1)
{
  PartyMemberRemoveMessage::deserialize(param1);
  this->kickerId = param1->readVarUhLong();
  if(this->kickerId < 0 || this->kickerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyMemberEjectedMessage -"<<"Forbidden value (" << this->kickerId << ") on element of PartyMemberEjectedMessage.kickerId.";
  }
  else
  {
    return;
  }
}

PartyMemberEjectedMessage::PartyMemberEjectedMessage()
{
  m_type = MessageEnum::PARTYMEMBEREJECTEDMESSAGE;
}

