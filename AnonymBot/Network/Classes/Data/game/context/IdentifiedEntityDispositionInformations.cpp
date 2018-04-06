#include "IdentifiedEntityDispositionInformations.h"

void IdentifiedEntityDispositionInformations::serialize(Writer *param1)
{
  this->serializeAs_IdentifiedEntityDispositionInformations(param1);
}

void IdentifiedEntityDispositionInformations::serializeAs_IdentifiedEntityDispositionInformations(Writer *param1)
{
  EntityDispositionInformations::serializeAs_EntityDispositionInformations(param1);
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentifiedEntityDispositionInformations -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeDouble(this->id);
    return;
  }
}

void IdentifiedEntityDispositionInformations::deserialize(Reader *param1)
{
  this->deserializeAs_IdentifiedEntityDispositionInformations(param1);
}

void IdentifiedEntityDispositionInformations::deserializeAs_IdentifiedEntityDispositionInformations(Reader *param1)
{
  EntityDispositionInformations::deserialize(param1);
  this->id = param1->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentifiedEntityDispositionInformations -"<<"Forbidden value (" << this->id << ") on element of IdentifiedEntityDispositionInformations.id.";
  }
  else
  {
    return;
  }
}

IdentifiedEntityDispositionInformations::IdentifiedEntityDispositionInformations()
{
  m_types<<ClassEnum::IDENTIFIEDENTITYDISPOSITIONINFORMATIONS;
}

bool IdentifiedEntityDispositionInformations::operator==(const IdentifiedEntityDispositionInformations &compared)
{
  if(id == compared.id)
  return true;
  
  return false;
}

