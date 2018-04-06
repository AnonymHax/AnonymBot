#include "GuildChangeMemberParametersMessage.h"

void GuildChangeMemberParametersMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildChangeMemberParametersMessage(param1);
}

void GuildChangeMemberParametersMessage::serializeAs_GuildChangeMemberParametersMessage(Writer *param1)
{
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  else
  {
    param1->writeVarLong((double)this->memberId);
    if(this->rank < 0)
    {
      qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->rank << ") on element rank.";
    }
    else
    {
      param1->writeVarShort((int)this->rank);
      if(this->experienceGivenPercent < 0 || this->experienceGivenPercent > 100)
      {
        qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->experienceGivenPercent << ") on element experienceGivenPercent.";
      }
      else
      {
        param1->writeByte(this->experienceGivenPercent);
        if(this->rights < 0)
        {
          qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->rights << ") on element rights.";
        }
        else
        {
          param1->writeVarInt((int)this->rights);
          return;
        }
      }
    }
  }
}

void GuildChangeMemberParametersMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildChangeMemberParametersMessage(param1);
}

void GuildChangeMemberParametersMessage::deserializeAs_GuildChangeMemberParametersMessage(Reader *param1)
{
  this->memberId = param1->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->memberId << ") on element of GuildChangeMemberParametersMessage.memberId.";
  }
  else
  {
    this->rank = param1->readVarUhShort();
    if(this->rank < 0)
    {
      qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->rank << ") on element of GuildChangeMemberParametersMessage.rank.";
    }
    else
    {
      this->experienceGivenPercent = param1->readByte();
      if(this->experienceGivenPercent < 0 || this->experienceGivenPercent > 100)
      {
        qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->experienceGivenPercent << ") on element of GuildChangeMemberParametersMessage.experienceGivenPercent.";
      }
      else
      {
        this->rights = param1->readVarUhInt();
        if(this->rights < 0)
        {
          qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->rights << ") on element of GuildChangeMemberParametersMessage.rights.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

GuildChangeMemberParametersMessage::GuildChangeMemberParametersMessage()
{
  m_type = MessageEnum::GUILDCHANGEMEMBERPARAMETERSMESSAGE;
}

