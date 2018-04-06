#include "HumanOptionOrnament.h"

void HumanOptionOrnament::serialize(Writer *param1)
{
  this->serializeAs_HumanOptionOrnament(param1);
}

void HumanOptionOrnament::serializeAs_HumanOptionOrnament(Writer *param1)
{
  HumanOption::serializeAs_HumanOption(param1);
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionOrnament -"<<"Forbidden value (" << this->ornamentId << ") on element ornamentId.";
  }
  else
  {
    param1->writeVarShort((int)this->ornamentId);
    return;
  }
}

void HumanOptionOrnament::deserialize(Reader *param1)
{
  this->deserializeAs_HumanOptionOrnament(param1);
}

void HumanOptionOrnament::deserializeAs_HumanOptionOrnament(Reader *param1)
{
  HumanOption::deserialize(param1);
  this->ornamentId = param1->readVarUhShort();
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionOrnament -"<<"Forbidden value (" << this->ornamentId << ") on element of HumanOptionOrnament.ornamentId.";
  }
  else
  {
    return;
  }
}

HumanOptionOrnament::HumanOptionOrnament()
{
  m_types<<ClassEnum::HUMANOPTIONORNAMENT;
}

bool HumanOptionOrnament::operator==(const HumanOptionOrnament &compared)
{
  if(ornamentId == compared.ornamentId)
  return true;
  
  return false;
}

