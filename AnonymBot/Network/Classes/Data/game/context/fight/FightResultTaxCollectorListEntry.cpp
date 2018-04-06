#include "FightResultTaxCollectorListEntry.h"

void FightResultTaxCollectorListEntry::serialize(Writer *param1)
{
  this->serializeAs_FightResultTaxCollectorListEntry(param1);
}

void FightResultTaxCollectorListEntry::serializeAs_FightResultTaxCollectorListEntry(Writer *param1)
{
  FightResultFighterListEntry::serializeAs_FightResultFighterListEntry(param1);
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - FightResultTaxCollectorListEntry -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  else
  {
    param1->writeByte(this->level);
    this->guildInfo->serializeAs_BasicGuildInformations(param1);
    param1->writeInt((int)this->experienceForGuild);
    return;
  }
}

void FightResultTaxCollectorListEntry::deserialize(Reader *param1)
{
  this->deserializeAs_FightResultTaxCollectorListEntry(param1);
}

void FightResultTaxCollectorListEntry::deserializeAs_FightResultTaxCollectorListEntry(Reader *param1)
{
  FightResultFighterListEntry::deserialize(param1);
  this->level = param1->readUByte();
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - FightResultTaxCollectorListEntry -"<<"Forbidden value (" << this->level << ") on element of FightResultTaxCollectorListEntry.level.";
  }
  else
  {
    this->guildInfo = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
    this->guildInfo->deserialize(param1);
    this->experienceForGuild = param1->readInt();
    return;
  }
}

FightResultTaxCollectorListEntry::FightResultTaxCollectorListEntry()
{
  m_types<<ClassEnum::FIGHTRESULTTAXCOLLECTORLISTENTRY;
}

bool FightResultTaxCollectorListEntry::operator==(const FightResultTaxCollectorListEntry &compared)
{
  if(level == compared.level)
  if(guildInfo == compared.guildInfo)
  if(experienceForGuild == compared.experienceForGuild)
  return true;
  
  return false;
}

