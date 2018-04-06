#include "PartyMemberInFightMessage.h"

void PartyMemberInFightMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyMemberInFightMessage(param1);
}

void PartyMemberInFightMessage::serializeAs_PartyMemberInFightMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  param1->writeByte(this->reason);
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyMemberInFightMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  else
  {
    param1->writeVarLong((double)this->memberId);
    if(this->memberAccountId < 0)
    {
      qDebug()<<"ERREUR - PartyMemberInFightMessage -"<<"Forbidden value (" << this->memberAccountId << ") on element memberAccountId.";
    }
    else
    {
      param1->writeInt((int)this->memberAccountId);
      param1->writeUTF(this->memberName);
      param1->writeInt((int)this->fightId);
      this->fightMap->serializeAs_MapCoordinatesExtended(param1);
      param1->writeVarShort((int)this->timeBeforeFightStart);
      return;
    }
  }
}

void PartyMemberInFightMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyMemberInFightMessage(param1);
}

void PartyMemberInFightMessage::deserializeAs_PartyMemberInFightMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInFightMessage -"<<"Forbidden value (" << this->reason << ") on element of PartyMemberInFightMessage.reason.";
  }
  else
  {
    this->memberId = param1->readVarUhLong();
    if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PartyMemberInFightMessage -"<<"Forbidden value (" << this->memberId << ") on element of PartyMemberInFightMessage.memberId.";
    }
    else
    {
      this->memberAccountId = param1->readInt();
      if(this->memberAccountId < 0)
      {
        qDebug()<<"ERREUR - PartyMemberInFightMessage -"<<"Forbidden value (" << this->memberAccountId << ") on element of PartyMemberInFightMessage.memberAccountId.";
      }
      else
      {
        this->memberName = param1->readUTF();
        this->fightId = param1->readInt();
        this->fightMap = QSharedPointer<MapCoordinatesExtended>(new MapCoordinatesExtended() );
        this->fightMap->deserialize(param1);
        this->timeBeforeFightStart = param1->readVarShort();
        return;
      }
    }
  }
}

PartyMemberInFightMessage::PartyMemberInFightMessage()
{
  m_type = MessageEnum::PARTYMEMBERINFIGHTMESSAGE;
}

