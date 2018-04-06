#include "GuildInAllianceInformations.h"

void GuildInAllianceInformations::serialize(Writer *param1)
{
  this->serializeAs_GuildInAllianceInformations(param1);
}

void GuildInAllianceInformations::serializeAs_GuildInAllianceInformations(Writer *param1)
{
  GuildInformations::serializeAs_GuildInformations(param1);
  if(this->nbMembers < 1 || this->nbMembers > 240)
  {
    qDebug()<<"ERREUR - GuildInAllianceInformations -"<<"Forbidden value (" << this->nbMembers << ") on element nbMembers.";
  }
  else
  {
    param1->writeByte(this->nbMembers);
    return;
  }
}

void GuildInAllianceInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInAllianceInformations(param1);
}

void GuildInAllianceInformations::deserializeAs_GuildInAllianceInformations(Reader *param1)
{
  GuildInformations::deserialize(param1);
  this->nbMembers = param1->readUByte();
  if(this->nbMembers < 1 || this->nbMembers > 240)
  {
    qDebug()<<"ERREUR - GuildInAllianceInformations -"<<"Forbidden value (" << this->nbMembers << ") on element of GuildInAllianceInformations.nbMembers.";
  }
  else
  {
    return;
  }
}

GuildInAllianceInformations::GuildInAllianceInformations()
{
  m_types<<ClassEnum::GUILDINALLIANCEINFORMATIONS;
}

bool GuildInAllianceInformations::operator==(const GuildInAllianceInformations &compared)
{
  if(nbMembers == compared.nbMembers)
  return true;
  
  return false;
}

