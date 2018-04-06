#include "AllianceVersatileInformations.h"

void AllianceVersatileInformations::serialize(Writer *param1)
{
  this->serializeAs_AllianceVersatileInformations(param1);
}

void AllianceVersatileInformations::serializeAs_AllianceVersatileInformations(Writer *param1)
{
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
  }
  else
  {
    param1->writeVarInt((int)this->allianceId);
    if(this->nbGuilds < 0)
    {
      qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->nbGuilds << ") on element nbGuilds.";
    }
    else
    {
      param1->writeVarShort((int)this->nbGuilds);
      if(this->nbMembers < 0)
      {
        qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->nbMembers << ") on element nbMembers.";
      }
      else
      {
        param1->writeVarShort((int)this->nbMembers);
        if(this->nbSubarea < 0)
        {
          qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->nbSubarea << ") on element nbSubarea.";
        }
        else
        {
          param1->writeVarShort((int)this->nbSubarea);
          return;
        }
      }
    }
  }
}

void AllianceVersatileInformations::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceVersatileInformations(param1);
}

void AllianceVersatileInformations::deserializeAs_AllianceVersatileInformations(Reader *param1)
{
  this->allianceId = param1->readVarUhInt();
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->allianceId << ") on element of AllianceVersatileInformations.allianceId.";
  }
  else
  {
    this->nbGuilds = param1->readVarUhShort();
    if(this->nbGuilds < 0)
    {
      qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->nbGuilds << ") on element of AllianceVersatileInformations.nbGuilds.";
    }
    else
    {
      this->nbMembers = param1->readVarUhShort();
      if(this->nbMembers < 0)
      {
        qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->nbMembers << ") on element of AllianceVersatileInformations.nbMembers.";
      }
      else
      {
        this->nbSubarea = param1->readVarUhShort();
        if(this->nbSubarea < 0)
        {
          qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->nbSubarea << ") on element of AllianceVersatileInformations.nbSubarea.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

AllianceVersatileInformations::AllianceVersatileInformations()
{
  m_types<<ClassEnum::ALLIANCEVERSATILEINFORMATIONS;
}

bool AllianceVersatileInformations::operator==(const AllianceVersatileInformations &compared)
{
  if(allianceId == compared.allianceId)
  if(nbGuilds == compared.nbGuilds)
  if(nbMembers == compared.nbMembers)
  if(nbSubarea == compared.nbSubarea)
  return true;
  
  return false;
}

