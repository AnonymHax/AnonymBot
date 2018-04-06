#include "PartyInvitationDungeonRequestMessage.h"

void PartyInvitationDungeonRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyInvitationDungeonRequestMessage(param1);
}

void PartyInvitationDungeonRequestMessage::serializeAs_PartyInvitationDungeonRequestMessage(Writer *param1)
{
  PartyInvitationRequestMessage::serializeAs_PartyInvitationRequestMessage(param1);
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDungeonRequestMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  else
  {
    param1->writeVarShort((int)this->dungeonId);
    return;
  }
}

void PartyInvitationDungeonRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyInvitationDungeonRequestMessage(param1);
}

void PartyInvitationDungeonRequestMessage::deserializeAs_PartyInvitationDungeonRequestMessage(Reader *param1)
{
  PartyInvitationRequestMessage::deserialize(param1);
  this->dungeonId = param1->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDungeonRequestMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of PartyInvitationDungeonRequestMessage.dungeonId.";
  }
  else
  {
    return;
  }
}

PartyInvitationDungeonRequestMessage::PartyInvitationDungeonRequestMessage()
{
  m_type = MessageEnum::PARTYINVITATIONDUNGEONREQUESTMESSAGE;
}

