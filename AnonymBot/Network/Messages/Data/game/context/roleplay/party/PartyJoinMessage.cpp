#include "PartyJoinMessage.h"

void PartyJoinMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyJoinMessage(param1);
}

void PartyJoinMessage::serializeAs_PartyJoinMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  param1->writeByte(this->partyType);
  if(this->partyLeaderId < 0 || this->partyLeaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyJoinMessage -"<<"Forbidden value (" << this->partyLeaderId << ") on element partyLeaderId.";
  }
  else
  {
    param1->writeVarLong((double)this->partyLeaderId);
    if(this->maxParticipants < 0)
    {
      qDebug()<<"ERREUR - PartyJoinMessage -"<<"Forbidden value (" << this->maxParticipants << ") on element maxParticipants.";
    }
    else
    {
      param1->writeByte(this->maxParticipants);
      param1->writeShort((short)this->members.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->members.size())
      {
        param1->writeShort((short)qSharedPointerCast<PartyMemberInformations>(this->members[_loc2_])->getTypes().last());
        qSharedPointerCast<PartyMemberInformations>(this->members[_loc2_])->serialize(param1);
        _loc2_++;
      }
      param1->writeShort((short)this->guests.size());
      uint _loc3_ = 0;
      while(_loc3_ < this->guests.size())
      {
        qSharedPointerCast<PartyGuestInformations>(this->guests[_loc3_])->serializeAs_PartyGuestInformations(param1);
        _loc3_++;
      }
      param1->writeBool(this->restricted);
      param1->writeUTF(this->partyName);
      return;
    }
  }
}

void PartyJoinMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyJoinMessage(param1);
}

void PartyJoinMessage::deserializeAs_PartyJoinMessage(Reader *param1)
{
  uint _loc6_ = 0;
  QSharedPointer<PartyMemberInformations> _loc7_ ;
  QSharedPointer<PartyGuestInformations> _loc8_ ;
  AbstractPartyMessage::deserialize(param1);
  this->partyType = param1->readByte();
  if(this->partyType < 0)
  {
    qDebug()<<"ERREUR - PartyJoinMessage -"<<"Forbidden value (" << this->partyType << ") on element of PartyJoinMessage.partyType.";
  }
  else
  {
    this->partyLeaderId = param1->readVarUhLong();
    if(this->partyLeaderId < 0 || this->partyLeaderId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PartyJoinMessage -"<<"Forbidden value (" << this->partyLeaderId << ") on element of PartyJoinMessage.partyLeaderId.";
    }
    else
    {
      this->maxParticipants = param1->readByte();
      if(this->maxParticipants < 0)
      {
        qDebug()<<"ERREUR - PartyJoinMessage -"<<"Forbidden value (" << this->maxParticipants << ") on element of PartyJoinMessage.maxParticipants.";
      }
      else
      {
        uint _loc2_ = param1->readUShort();
        uint _loc3_ = 0;
        while(_loc3_ < _loc2_)
        {
          _loc6_ = param1->readUShort();
          _loc7_ = qSharedPointerCast<PartyMemberInformations>(ClassManagerSingleton::get()->getClass(_loc6_));
          _loc7_->deserialize(param1);
          this->members.append(_loc7_);
          _loc3_++;
        }
        uint _loc4_ = param1->readUShort();
        uint _loc5_ = 0;
        while(_loc5_ < _loc4_)
        {
          _loc8_ = QSharedPointer<PartyGuestInformations>(new PartyGuestInformations() );
          _loc8_->deserialize(param1);
          this->guests.append(_loc8_);
          _loc5_++;
        }
        this->restricted = param1->readBool();
        this->partyName = param1->readUTF();
        return;
      }
    }
  }
}

PartyJoinMessage::PartyJoinMessage()
{
  m_type = MessageEnum::PARTYJOINMESSAGE;
}

