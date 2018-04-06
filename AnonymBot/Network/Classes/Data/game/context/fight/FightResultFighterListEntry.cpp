#include "FightResultFighterListEntry.h"

void FightResultFighterListEntry::serialize(Writer *param1)
{
  this->serializeAs_FightResultFighterListEntry(param1);
}

void FightResultFighterListEntry::serializeAs_FightResultFighterListEntry(Writer *param1)
{
  FightResultListEntry::serializeAs_FightResultListEntry(param1);
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightResultFighterListEntry -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeDouble(this->id);
    param1->writeBool(this->alive);
    return;
  }
}

void FightResultFighterListEntry::deserialize(Reader *param1)
{
  this->deserializeAs_FightResultFighterListEntry(param1);
}

void FightResultFighterListEntry::deserializeAs_FightResultFighterListEntry(Reader *param1)
{
  FightResultListEntry::deserialize(param1);
  this->id = param1->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightResultFighterListEntry -"<<"Forbidden value (" << this->id << ") on element of FightResultFighterListEntry.id.";
  }
  else
  {
    this->alive = param1->readBool();
    return;
  }
}

FightResultFighterListEntry::FightResultFighterListEntry()
{
  m_types<<ClassEnum::FIGHTRESULTFIGHTERLISTENTRY;
}

bool FightResultFighterListEntry::operator==(const FightResultFighterListEntry &compared)
{
  if(id == compared.id)
  if(alive == compared.alive)
  return true;
  
  return false;
}

