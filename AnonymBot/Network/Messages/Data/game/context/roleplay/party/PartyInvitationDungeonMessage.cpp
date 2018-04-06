#include "PartyInvitationDungeonMessage.h"

void PartyInvitationDungeonMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyInvitationDungeonMessage(param1);
}

void PartyInvitationDungeonMessage::serializeAs_PartyInvitationDungeonMessage(Writer *param1)
{
  PartyInvitationMessage::serializeAs_PartyInvitationMessage(param1);
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDungeonMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  else
  {
    param1->writeVarShort((int)this->dungeonId);
    return;
  }
}

void PartyInvitationDungeonMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyInvitationDungeonMessage(param1);
}

void PartyInvitationDungeonMessage::deserializeAs_PartyInvitationDungeonMessage(Reader *param1)
{
  PartyInvitationMessage::deserialize(param1);
  this->dungeonId = param1->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDungeonMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of PartyInvitationDungeonMessage.dungeonId.";
  }
  else
  {
    return;
  }
}

PartyInvitationDungeonMessage::PartyInvitationDungeonMessage()
{
  m_type = MessageEnum::PARTYINVITATIONDUNGEONMESSAGE;
}

