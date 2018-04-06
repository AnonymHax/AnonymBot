#include "PartyInvitationDungeonDetailsMessage.h"

void PartyInvitationDungeonDetailsMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyInvitationDungeonDetailsMessage(param1);
}

void PartyInvitationDungeonDetailsMessage::serializeAs_PartyInvitationDungeonDetailsMessage(Writer *param1)
{
  PartyInvitationDetailsMessage::serializeAs_PartyInvitationDetailsMessage(param1);
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDungeonDetailsMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  else
  {
    param1->writeVarShort((int)this->dungeonId);
    param1->writeShort((short)this->playersDungeonReady.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->playersDungeonReady.size())
    {
      param1->writeBool(this->playersDungeonReady[_loc2_]);
      _loc2_++;
    }
    return;
  }
}

void PartyInvitationDungeonDetailsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyInvitationDungeonDetailsMessage(param1);
}

void PartyInvitationDungeonDetailsMessage::deserializeAs_PartyInvitationDungeonDetailsMessage(Reader *param1)
{
  auto _loc4_ = false;
  PartyInvitationDetailsMessage::deserialize(param1);
  this->dungeonId = param1->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDungeonDetailsMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of PartyInvitationDungeonDetailsMessage.dungeonId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readBool();
      this->playersDungeonReady.append(_loc4_);
      _loc3_++;
    }
    return;
  }
}

PartyInvitationDungeonDetailsMessage::PartyInvitationDungeonDetailsMessage()
{
  m_type = MessageEnum::PARTYINVITATIONDUNGEONDETAILSMESSAGE;
}

