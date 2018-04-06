#include "GuildInsiderFactSheetInformations.h"

void GuildInsiderFactSheetInformations::serialize(Writer *param1)
{
  this->serializeAs_GuildInsiderFactSheetInformations(param1);
}

void GuildInsiderFactSheetInformations::serializeAs_GuildInsiderFactSheetInformations(Writer *param1)
{
  GuildFactSheetInformations::serializeAs_GuildFactSheetInformations(param1);
  param1->writeUTF(this->leaderName);
  if(this->nbConnectedMembers < 0)
  {
    qDebug()<<"ERREUR - GuildInsiderFactSheetInformations -"<<"Forbidden value (" << this->nbConnectedMembers << ") on element nbConnectedMembers.";
  }
  else
  {
    param1->writeVarShort((int)this->nbConnectedMembers);
    if(this->nbTaxCollectors < 0)
    {
      qDebug()<<"ERREUR - GuildInsiderFactSheetInformations -"<<"Forbidden value (" << this->nbTaxCollectors << ") on element nbTaxCollectors.";
    }
    else
    {
      param1->writeByte(this->nbTaxCollectors);
      if(this->lastActivity < 0)
      {
        qDebug()<<"ERREUR - GuildInsiderFactSheetInformations -"<<"Forbidden value (" << this->lastActivity << ") on element lastActivity.";
      }
      else
      {
        param1->writeInt((int)this->lastActivity);
        return;
      }
    }
  }
}

void GuildInsiderFactSheetInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInsiderFactSheetInformations(param1);
}

void GuildInsiderFactSheetInformations::deserializeAs_GuildInsiderFactSheetInformations(Reader *param1)
{
  GuildFactSheetInformations::deserialize(param1);
  this->leaderName = param1->readUTF();
  this->nbConnectedMembers = param1->readVarUhShort();
  if(this->nbConnectedMembers < 0)
  {
    qDebug()<<"ERREUR - GuildInsiderFactSheetInformations -"<<"Forbidden value (" << this->nbConnectedMembers << ") on element of GuildInsiderFactSheetInformations.nbConnectedMembers.";
  }
  else
  {
    this->nbTaxCollectors = param1->readByte();
    if(this->nbTaxCollectors < 0)
    {
      qDebug()<<"ERREUR - GuildInsiderFactSheetInformations -"<<"Forbidden value (" << this->nbTaxCollectors << ") on element of GuildInsiderFactSheetInformations.nbTaxCollectors.";
    }
    else
    {
      this->lastActivity = param1->readInt();
      if(this->lastActivity < 0)
      {
        qDebug()<<"ERREUR - GuildInsiderFactSheetInformations -"<<"Forbidden value (" << this->lastActivity << ") on element of GuildInsiderFactSheetInformations.lastActivity.";
      }
      else
      {
        return;
      }
    }
  }
}

GuildInsiderFactSheetInformations::GuildInsiderFactSheetInformations()
{
  m_types<<ClassEnum::GUILDINSIDERFACTSHEETINFORMATIONS;
}

bool GuildInsiderFactSheetInformations::operator==(const GuildInsiderFactSheetInformations &compared)
{
  if(leaderName == compared.leaderName)
  if(nbConnectedMembers == compared.nbConnectedMembers)
  if(nbTaxCollectors == compared.nbTaxCollectors)
  if(lastActivity == compared.lastActivity)
  return true;
  
  return false;
}

