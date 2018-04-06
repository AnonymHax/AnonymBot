#include "GuildInAllianceVersatileInformations.h"

void GuildInAllianceVersatileInformations::serialize(Writer *param1)
{
  this->serializeAs_GuildInAllianceVersatileInformations(param1);
}

void GuildInAllianceVersatileInformations::serializeAs_GuildInAllianceVersatileInformations(Writer *param1)
{
  GuildVersatileInformations::serializeAs_GuildVersatileInformations(param1);
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - GuildInAllianceVersatileInformations -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
  }
  else
  {
    param1->writeVarInt((int)this->allianceId);
    return;
  }
}

void GuildInAllianceVersatileInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInAllianceVersatileInformations(param1);
}

void GuildInAllianceVersatileInformations::deserializeAs_GuildInAllianceVersatileInformations(Reader *param1)
{
  GuildVersatileInformations::deserialize(param1);
  this->allianceId = param1->readVarUhInt();
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - GuildInAllianceVersatileInformations -"<<"Forbidden value (" << this->allianceId << ") on element of GuildInAllianceVersatileInformations.allianceId.";
  }
  else
  {
    return;
  }
}

GuildInAllianceVersatileInformations::GuildInAllianceVersatileInformations()
{
  m_types<<ClassEnum::GUILDINALLIANCEVERSATILEINFORMATIONS;
}

bool GuildInAllianceVersatileInformations::operator==(const GuildInAllianceVersatileInformations &compared)
{
  if(allianceId == compared.allianceId)
  return true;
  
  return false;
}

