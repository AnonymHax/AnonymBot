#include "FightResultMutantListEntry.h"

void FightResultMutantListEntry::serialize(Writer *param1)
{
  this->serializeAs_FightResultMutantListEntry(param1);
}

void FightResultMutantListEntry::serializeAs_FightResultMutantListEntry(Writer *param1)
{
  FightResultFighterListEntry::serializeAs_FightResultFighterListEntry(param1);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - FightResultMutantListEntry -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  else
  {
    param1->writeVarShort((int)this->level);
    return;
  }
}

void FightResultMutantListEntry::deserialize(Reader *param1)
{
  this->deserializeAs_FightResultMutantListEntry(param1);
}

void FightResultMutantListEntry::deserializeAs_FightResultMutantListEntry(Reader *param1)
{
  FightResultFighterListEntry::deserialize(param1);
  this->level = param1->readVarUhShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - FightResultMutantListEntry -"<<"Forbidden value (" << this->level << ") on element of FightResultMutantListEntry.level.";
  }
  else
  {
    return;
  }
}

FightResultMutantListEntry::FightResultMutantListEntry()
{
  m_types<<ClassEnum::FIGHTRESULTMUTANTLISTENTRY;
}

bool FightResultMutantListEntry::operator==(const FightResultMutantListEntry &compared)
{
  if(level == compared.level)
  return true;
  
  return false;
}

