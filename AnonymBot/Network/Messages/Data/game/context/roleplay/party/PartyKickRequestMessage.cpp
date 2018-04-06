#include "PartyKickRequestMessage.h"

void PartyKickRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyKickRequestMessage(param1);
}

void PartyKickRequestMessage::serializeAs_PartyKickRequestMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyKickRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    return;
  }
}

void PartyKickRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyKickRequestMessage(param1);
}

void PartyKickRequestMessage::deserializeAs_PartyKickRequestMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyKickRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element of PartyKickRequestMessage.playerId.";
  }
  else
  {
    return;
  }
}

PartyKickRequestMessage::PartyKickRequestMessage()
{
  m_type = MessageEnum::PARTYKICKREQUESTMESSAGE;
}

