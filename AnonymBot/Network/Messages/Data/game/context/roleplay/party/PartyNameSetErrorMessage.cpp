#include "PartyNameSetErrorMessage.h"

void PartyNameSetErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyNameSetErrorMessage(param1);
}

void PartyNameSetErrorMessage::serializeAs_PartyNameSetErrorMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  param1->writeByte(this->result);
}

void PartyNameSetErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyNameSetErrorMessage(param1);
}

void PartyNameSetErrorMessage::deserializeAs_PartyNameSetErrorMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->result = param1->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - PartyNameSetErrorMessage -"<<"Forbidden value (" << this->result << ") on element of PartyNameSetErrorMessage.result.";
  }
  else
  {
    return;
  }
}

PartyNameSetErrorMessage::PartyNameSetErrorMessage()
{
  m_type = MessageEnum::PARTYNAMESETERRORMESSAGE;
}

