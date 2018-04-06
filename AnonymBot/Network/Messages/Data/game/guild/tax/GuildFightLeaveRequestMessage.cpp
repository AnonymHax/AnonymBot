#include "GuildFightLeaveRequestMessage.h"

void GuildFightLeaveRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildFightLeaveRequestMessage(param1);
}

void GuildFightLeaveRequestMessage::serializeAs_GuildFightLeaveRequestMessage(Writer *param1)
{
  if(this->taxCollectorId < 0)
  {
    qDebug()<<"ERREUR - GuildFightLeaveRequestMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element taxCollectorId.";
  }
  else
  {
    param1->writeInt((int)this->taxCollectorId);
    if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GuildFightLeaveRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
    }
    else
    {
      param1->writeVarLong((double)this->characterId);
      return;
    }
  }
}

void GuildFightLeaveRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildFightLeaveRequestMessage(param1);
}

void GuildFightLeaveRequestMessage::deserializeAs_GuildFightLeaveRequestMessage(Reader *param1)
{
  this->taxCollectorId = param1->readInt();
  if(this->taxCollectorId < 0)
  {
    qDebug()<<"ERREUR - GuildFightLeaveRequestMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element of GuildFightLeaveRequestMessage.taxCollectorId.";
  }
  else
  {
    this->characterId = param1->readVarUhLong();
    if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GuildFightLeaveRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element of GuildFightLeaveRequestMessage.characterId.";
    }
    else
    {
      return;
    }
  }
}

GuildFightLeaveRequestMessage::GuildFightLeaveRequestMessage()
{
  m_type = MessageEnum::GUILDFIGHTLEAVEREQUESTMESSAGE;
}

