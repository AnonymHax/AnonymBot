#include "InteractiveElementWithAgeBonus.h"

void InteractiveElementWithAgeBonus::serialize(Writer *param1)
{
  this->serializeAs_InteractiveElementWithAgeBonus(param1);
}

void InteractiveElementWithAgeBonus::serializeAs_InteractiveElementWithAgeBonus(Writer *param1)
{
  InteractiveElement::serializeAs_InteractiveElement(param1);
  if(this->ageBonus < -1 || this->ageBonus > 1000)
  {
    qDebug()<<"ERREUR - InteractiveElementWithAgeBonus -"<<"Forbidden value (" << this->ageBonus << ") on element ageBonus.";
  }
  else
  {
    param1->writeShort((short)this->ageBonus);
    return;
  }
}

void InteractiveElementWithAgeBonus::deserialize(Reader *param1)
{
  this->deserializeAs_InteractiveElementWithAgeBonus(param1);
}

void InteractiveElementWithAgeBonus::deserializeAs_InteractiveElementWithAgeBonus(Reader *param1)
{
  InteractiveElement::deserialize(param1);
  this->ageBonus = param1->readShort();
  if(this->ageBonus < -1 || this->ageBonus > 1000)
  {
    qDebug()<<"ERREUR - InteractiveElementWithAgeBonus -"<<"Forbidden value (" << this->ageBonus << ") on element of InteractiveElementWithAgeBonus.ageBonus.";
  }
  else
  {
    return;
  }
}

InteractiveElementWithAgeBonus::InteractiveElementWithAgeBonus()
{
  m_types<<ClassEnum::INTERACTIVEELEMENTWITHAGEBONUS;
}

bool InteractiveElementWithAgeBonus::operator==(const InteractiveElementWithAgeBonus &compared)
{
  if(ageBonus == compared.ageBonus)
  return true;
  
  return false;
}

