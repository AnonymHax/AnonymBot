#include "FightResultListEntry.h"

void FightResultListEntry::serialize(Writer *param1)
{
  this->serializeAs_FightResultListEntry(param1);
}

void FightResultListEntry::serializeAs_FightResultListEntry(Writer *param1)
{
  param1->writeVarShort((int)this->outcome);
  if(this->wave < 0)
  {
    qDebug()<<"ERREUR - FightResultListEntry -"<<"Forbidden value (" << this->wave << ") on element wave.";
  }
  else
  {
    param1->writeByte(this->wave);
    this->rewards.serializeAs_FightLoot(param1);
    return;
  }
}

void FightResultListEntry::deserialize(Reader *param1)
{
  this->deserializeAs_FightResultListEntry(param1);
}

void FightResultListEntry::deserializeAs_FightResultListEntry(Reader *param1)
{
  this->outcome = param1->readVarUhShort();
  if(this->outcome < 0)
  {
    qDebug()<<"ERREUR - FightResultListEntry -"<<"Forbidden value (" << this->outcome << ") on element of FightResultListEntry.outcome.";
  }
  else
  {
    this->wave = param1->readByte();
    if(this->wave < 0)
    {
      qDebug()<<"ERREUR - FightResultListEntry -"<<"Forbidden value (" << this->wave << ") on element of FightResultListEntry.wave.";
    }
    else
    {
      this->rewards = FightLoot();
      this->rewards.deserialize(param1);
      return;
    }
  }
}

FightResultListEntry::FightResultListEntry()
{
  m_types<<ClassEnum::FIGHTRESULTLISTENTRY;
}

bool FightResultListEntry::operator==(const FightResultListEntry &compared)
{
  if(outcome == compared.outcome)
  if(wave == compared.wave)
  if(rewards == compared.rewards)
  return true;
  
  return false;
}

