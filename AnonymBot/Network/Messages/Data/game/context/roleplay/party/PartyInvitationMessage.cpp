#include "PartyInvitationMessage.h"

void PartyInvitationMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyInvitationMessage(param1);
}

void PartyInvitationMessage::serializeAs_PartyInvitationMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  param1->writeByte(this->partyType);
  param1->writeUTF(this->partyName);
  if(this->maxParticipants < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->maxParticipants << ") on element maxParticipants.";
  }
  else
  {
    param1->writeByte(this->maxParticipants);
    if(this->fromId < 0 || this->fromId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->fromId << ") on element fromId.";
    }
    else
    {
      param1->writeVarLong((double)this->fromId);
      param1->writeUTF(this->fromName);
      if(this->toId < 0 || this->toId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->toId << ") on element toId.";
      }
      else
      {
        param1->writeVarLong((double)this->toId);
        return;
      }
    }
  }
}

void PartyInvitationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyInvitationMessage(param1);
}

void PartyInvitationMessage::deserializeAs_PartyInvitationMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->partyType = param1->readByte();
  if(this->partyType < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->partyType << ") on element of PartyInvitationMessage.partyType.";
  }
  else
  {
    this->partyName = param1->readUTF();
    this->maxParticipants = param1->readByte();
    if(this->maxParticipants < 0)
    {
      qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->maxParticipants << ") on element of PartyInvitationMessage.maxParticipants.";
    }
    else
    {
      this->fromId = param1->readVarUhLong();
      if(this->fromId < 0 || this->fromId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->fromId << ") on element of PartyInvitationMessage.fromId.";
      }
      else
      {
        this->fromName = param1->readUTF();
        this->toId = param1->readVarUhLong();
        if(this->toId < 0 || this->toId > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->toId << ") on element of PartyInvitationMessage.toId.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

PartyInvitationMessage::PartyInvitationMessage()
{
  m_type = MessageEnum::PARTYINVITATIONMESSAGE;
}

