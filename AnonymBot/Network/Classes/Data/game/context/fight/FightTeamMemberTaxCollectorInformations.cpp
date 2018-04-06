#include "FightTeamMemberTaxCollectorInformations.h"

void FightTeamMemberTaxCollectorInformations::serialize(Writer *param1)
{
  this->serializeAs_FightTeamMemberTaxCollectorInformations(param1);
}

void FightTeamMemberTaxCollectorInformations::serializeAs_FightTeamMemberTaxCollectorInformations(Writer *param1)
{
  FightTeamMemberInformations::serializeAs_FightTeamMemberInformations(param1);
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->firstNameId << ") on element firstNameId.";
  }
  else
  {
    param1->writeVarShort((int)this->firstNameId);
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
    }
    else
    {
      param1->writeVarShort((int)this->lastNameId);
      if(this->level < 1 || this->level > 200)
      {
        qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->level << ") on element level.";
      }
      else
      {
        param1->writeByte(this->level);
        if(this->guildId < 0)
        {
          qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
        }
        else
        {
          param1->writeVarInt((int)this->guildId);
          if(this->uid < 0)
          {
            qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->uid << ") on element uid.";
          }
          else
          {
            param1->writeVarInt((int)this->uid);
            return;
          }
        }
      }
    }
  }
}

void FightTeamMemberTaxCollectorInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightTeamMemberTaxCollectorInformations(param1);
}

void FightTeamMemberTaxCollectorInformations::deserializeAs_FightTeamMemberTaxCollectorInformations(Reader *param1)
{
  FightTeamMemberInformations::deserialize(param1);
  this->firstNameId = param1->readVarUhShort();
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->firstNameId << ") on element of FightTeamMemberTaxCollectorInformations.firstNameId.";
  }
  else
  {
    this->lastNameId = param1->readVarUhShort();
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->lastNameId << ") on element of FightTeamMemberTaxCollectorInformations.lastNameId.";
    }
    else
    {
      this->level = param1->readUByte();
      if(this->level < 1 || this->level > 200)
      {
        qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->level << ") on element of FightTeamMemberTaxCollectorInformations.level.";
      }
      else
      {
        this->guildId = param1->readVarUhInt();
        if(this->guildId < 0)
        {
          qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->guildId << ") on element of FightTeamMemberTaxCollectorInformations.guildId.";
        }
        else
        {
          this->uid = param1->readVarUhInt();
          if(this->uid < 0)
          {
            qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->uid << ") on element of FightTeamMemberTaxCollectorInformations.uid.";
          }
          else
          {
            return;
          }
        }
      }
    }
  }
}

FightTeamMemberTaxCollectorInformations::FightTeamMemberTaxCollectorInformations()
{
  m_types<<ClassEnum::FIGHTTEAMMEMBERTAXCOLLECTORINFORMATIONS;
}

bool FightTeamMemberTaxCollectorInformations::operator==(const FightTeamMemberTaxCollectorInformations &compared)
{
  if(firstNameId == compared.firstNameId)
  if(lastNameId == compared.lastNameId)
  if(level == compared.level)
  if(guildId == compared.guildId)
  if(uid == compared.uid)
  return true;
  
  return false;
}

