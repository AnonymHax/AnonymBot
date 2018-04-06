#include "FightEntityDispositionInformations.h"

void FightEntityDispositionInformations::serialize(Writer *param1)
{
  this->serializeAs_FightEntityDispositionInformations(param1);
}

void FightEntityDispositionInformations::serializeAs_FightEntityDispositionInformations(Writer *param1)
{
  EntityDispositionInformations::serializeAs_EntityDispositionInformations(param1);
  if(this->carryingCharacterId < -9.007199254740992E15 || this->carryingCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightEntityDispositionInformations -"<<"Forbidden value (" << this->carryingCharacterId << ") on element carryingCharacterId.";
  }
  else
  {
    param1->writeDouble(this->carryingCharacterId);
    return;
  }
}

void FightEntityDispositionInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightEntityDispositionInformations(param1);
}

void FightEntityDispositionInformations::deserializeAs_FightEntityDispositionInformations(Reader *param1)
{
  EntityDispositionInformations::deserialize(param1);
  this->carryingCharacterId = param1->readDouble();
  if(this->carryingCharacterId < -9.007199254740992E15 || this->carryingCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightEntityDispositionInformations -"<<"Forbidden value (" << this->carryingCharacterId << ") on element of FightEntityDispositionInformations.carryingCharacterId.";
  }
  else
  {
    return;
  }
}

FightEntityDispositionInformations::FightEntityDispositionInformations()
{
  m_types<<ClassEnum::FIGHTENTITYDISPOSITIONINFORMATIONS;
}

bool FightEntityDispositionInformations::operator==(const FightEntityDispositionInformations &compared)
{
  if(carryingCharacterId == compared.carryingCharacterId)
  return true;
  
  return false;
}

