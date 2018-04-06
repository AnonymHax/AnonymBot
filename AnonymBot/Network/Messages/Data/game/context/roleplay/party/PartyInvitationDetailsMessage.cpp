#include "PartyInvitationDetailsMessage.h"

void PartyInvitationDetailsMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyInvitationDetailsMessage(param1);
}

void PartyInvitationDetailsMessage::serializeAs_PartyInvitationDetailsMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  param1->writeByte(this->partyType);
  param1->writeUTF(this->partyName);
  if(this->fromId < 0 || this->fromId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyInvitationDetailsMessage -"<<"Forbidden value (" << this->fromId << ") on element fromId.";
  }
  else
  {
    param1->writeVarLong((double)this->fromId);
    param1->writeUTF(this->fromName);
    if(this->leaderId < 0 || this->leaderId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PartyInvitationDetailsMessage -"<<"Forbidden value (" << this->leaderId << ") on element leaderId.";
    }
    else
    {
      param1->writeVarLong((double)this->leaderId);
      param1->writeShort((short)this->members.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->members.size())
      {
        qSharedPointerCast<PartyInvitationMemberInformations>(this->members[_loc2_])->serializeAs_PartyInvitationMemberInformations(param1);
        _loc2_++;
      }
      param1->writeShort((short)this->guests.size());
      uint _loc3_ = 0;
      while(_loc3_ < this->guests.size())
      {
        qSharedPointerCast<PartyGuestInformations>(this->guests[_loc3_])->serializeAs_PartyGuestInformations(param1);
        _loc3_++;
      }
      return;
    }
  }
}

void PartyInvitationDetailsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyInvitationDetailsMessage(param1);
}

void PartyInvitationDetailsMessage::deserializeAs_PartyInvitationDetailsMessage(Reader *param1)
{
  QSharedPointer<PartyInvitationMemberInformations> _loc6_ ;
  QSharedPointer<PartyGuestInformations> _loc7_ ;
  AbstractPartyMessage::deserialize(param1);
  this->partyType = param1->readByte();
  if(this->partyType < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDetailsMessage -"<<"Forbidden value (" << this->partyType << ") on element of PartyInvitationDetailsMessage.partyType.";
  }
  else
  {
    this->partyName = param1->readUTF();
    this->fromId = param1->readVarUhLong();
    if(this->fromId < 0 || this->fromId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PartyInvitationDetailsMessage -"<<"Forbidden value (" << this->fromId << ") on element of PartyInvitationDetailsMessage.fromId.";
    }
    else
    {
      this->fromName = param1->readUTF();
      this->leaderId = param1->readVarUhLong();
      if(this->leaderId < 0 || this->leaderId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - PartyInvitationDetailsMessage -"<<"Forbidden value (" << this->leaderId << ") on element of PartyInvitationDetailsMessage.leaderId.";
      }
      else
      {
        uint _loc2_ = param1->readUShort();
        uint _loc3_ = 0;
        while(_loc3_ < _loc2_)
        {
          _loc6_ = QSharedPointer<PartyInvitationMemberInformations>(new PartyInvitationMemberInformations() );
          _loc6_->deserialize(param1);
          this->members.append(_loc6_);
          _loc3_++;
        }
        uint _loc4_ = param1->readUShort();
        uint _loc5_ = 0;
        while(_loc5_ < _loc4_)
        {
          _loc7_ = QSharedPointer<PartyGuestInformations>(new PartyGuestInformations() );
          _loc7_->deserialize(param1);
          this->guests.append(_loc7_);
          _loc5_++;
        }
        return;
      }
    }
  }
}

PartyInvitationDetailsMessage::PartyInvitationDetailsMessage()
{
  m_type = MessageEnum::PARTYINVITATIONDETAILSMESSAGE;
}

