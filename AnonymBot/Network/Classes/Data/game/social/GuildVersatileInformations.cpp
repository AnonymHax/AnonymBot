#include "GuildVersatileInformations.h"

void GuildVersatileInformations::serialize(Writer *param1)
{
  this->serializeAs_GuildVersatileInformations(param1);
}

void GuildVersatileInformations::serializeAs_GuildVersatileInformations(Writer *param1)
{
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  else
  {
    param1->writeVarInt((int)this->guildId);
    if(this->leaderId < 0 || this->leaderId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->leaderId << ") on element leaderId.";
    }
    else
    {
      param1->writeVarLong((double)this->leaderId);
      if(this->guildLevel < 1 || this->guildLevel > 200)
      {
        qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->guildLevel << ") on element guildLevel.";
      }
      else
      {
        param1->writeByte(this->guildLevel);
        if(this->nbMembers < 1 || this->nbMembers > 240)
        {
          qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->nbMembers << ") on element nbMembers.";
        }
        else
        {
          param1->writeByte(this->nbMembers);
          return;
        }
      }
    }
  }
}

void GuildVersatileInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GuildVersatileInformations(param1);
}

void GuildVersatileInformations::deserializeAs_GuildVersatileInformations(Reader *param1)
{
  this->guildId = param1->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->guildId << ") on element of GuildVersatileInformations.guildId.";
  }
  else
  {
    this->leaderId = param1->readVarUhLong();
    if(this->leaderId < 0 || this->leaderId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->leaderId << ") on element of GuildVersatileInformations.leaderId.";
    }
    else
    {
      this->guildLevel = param1->readUByte();
      if(this->guildLevel < 1 || this->guildLevel > 200)
      {
        qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->guildLevel << ") on element of GuildVersatileInformations.guildLevel.";
      }
      else
      {
        this->nbMembers = param1->readUByte();
        if(this->nbMembers < 1 || this->nbMembers > 240)
        {
          qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->nbMembers << ") on element of GuildVersatileInformations.nbMembers.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

GuildVersatileInformations::GuildVersatileInformations()
{
  m_types<<ClassEnum::GUILDVERSATILEINFORMATIONS;
}

bool GuildVersatileInformations::operator==(const GuildVersatileInformations &compared)
{
  if(guildId == compared.guildId)
  if(leaderId == compared.leaderId)
  if(guildLevel == compared.guildLevel)
  if(nbMembers == compared.nbMembers)
  return true;
  
  return false;
}

