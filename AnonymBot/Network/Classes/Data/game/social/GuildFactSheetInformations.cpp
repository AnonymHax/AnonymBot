#include "GuildFactSheetInformations.h"

void GuildFactSheetInformations::serialize(Writer *param1)
{
  this->serializeAs_GuildFactSheetInformations(param1);
}

void GuildFactSheetInformations::serializeAs_GuildFactSheetInformations(Writer *param1)
{
  GuildInformations::serializeAs_GuildInformations(param1);
  if(this->leaderId < 0 || this->leaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFactSheetInformations -"<<"Forbidden value (" << this->leaderId << ") on element leaderId.";
  }
  else
  {
    param1->writeVarLong((double)this->leaderId);
    if(this->nbMembers < 0)
    {
      qDebug()<<"ERREUR - GuildFactSheetInformations -"<<"Forbidden value (" << this->nbMembers << ") on element nbMembers.";
    }
    else
    {
      param1->writeVarShort((int)this->nbMembers);
      return;
    }
  }
}

void GuildFactSheetInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GuildFactSheetInformations(param1);
}

void GuildFactSheetInformations::deserializeAs_GuildFactSheetInformations(Reader *param1)
{
  GuildInformations::deserialize(param1);
  this->leaderId = param1->readVarUhLong();
  if(this->leaderId < 0 || this->leaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFactSheetInformations -"<<"Forbidden value (" << this->leaderId << ") on element of GuildFactSheetInformations.leaderId.";
  }
  else
  {
    this->nbMembers = param1->readVarUhShort();
    if(this->nbMembers < 0)
    {
      qDebug()<<"ERREUR - GuildFactSheetInformations -"<<"Forbidden value (" << this->nbMembers << ") on element of GuildFactSheetInformations.nbMembers.";
    }
    else
    {
      return;
    }
  }
}

GuildFactSheetInformations::GuildFactSheetInformations()
{
  m_types<<ClassEnum::GUILDFACTSHEETINFORMATIONS;
}

bool GuildFactSheetInformations::operator==(const GuildFactSheetInformations &compared)
{
  if(leaderId == compared.leaderId)
  if(nbMembers == compared.nbMembers)
  return true;
  
  return false;
}

