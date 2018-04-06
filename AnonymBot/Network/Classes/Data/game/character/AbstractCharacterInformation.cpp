#include "AbstractCharacterInformation.h"

void AbstractCharacterInformation::serialize(Writer *param1)
{
  this->serializeAs_AbstractCharacterInformation(param1);
}

void AbstractCharacterInformation::serializeAs_AbstractCharacterInformation(Writer *param1)
{
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AbstractCharacterInformation -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarLong((double)this->id);
    return;
  }
}

void AbstractCharacterInformation::deserialize(Reader *param1)
{
  this->deserializeAs_AbstractCharacterInformation(param1);
}

void AbstractCharacterInformation::deserializeAs_AbstractCharacterInformation(Reader *param1)
{
  this->id = param1->readVarUhLong();
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AbstractCharacterInformation -"<<"Forbidden value (" << this->id << ") on element of AbstractCharacterInformation.id.";
  }
  else
  {
    return;
  }
}

AbstractCharacterInformation::AbstractCharacterInformation()
{
  m_types<<ClassEnum::ABSTRACTCHARACTERINFORMATION;
}

bool AbstractCharacterInformation::operator==(const AbstractCharacterInformation &compared)
{
  if(id == compared.id)
  return true;
  
  return false;
}

