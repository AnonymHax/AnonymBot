#include "CharacterToRemodelInformations.h"

void CharacterToRemodelInformations::serialize(Writer *param1)
{
  this->serializeAs_CharacterToRemodelInformations(param1);
}

void CharacterToRemodelInformations::serializeAs_CharacterToRemodelInformations(Writer *param1)
{
  CharacterRemodelingInformation::serializeAs_CharacterRemodelingInformation(param1);
  if(this->possibleChangeMask < 0)
  {
    qDebug()<<"ERREUR - CharacterToRemodelInformations -"<<"Forbidden value (" << this->possibleChangeMask << ") on element possibleChangeMask.";
  }
  else
  {
    param1->writeByte(this->possibleChangeMask);
    if(this->mandatoryChangeMask < 0)
    {
      qDebug()<<"ERREUR - CharacterToRemodelInformations -"<<"Forbidden value (" << this->mandatoryChangeMask << ") on element mandatoryChangeMask.";
    }
    else
    {
      param1->writeByte(this->mandatoryChangeMask);
      return;
    }
  }
}

void CharacterToRemodelInformations::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterToRemodelInformations(param1);
}

void CharacterToRemodelInformations::deserializeAs_CharacterToRemodelInformations(Reader *param1)
{
  CharacterRemodelingInformation::deserialize(param1);
  this->possibleChangeMask = param1->readByte();
  if(this->possibleChangeMask < 0)
  {
    qDebug()<<"ERREUR - CharacterToRemodelInformations -"<<"Forbidden value (" << this->possibleChangeMask << ") on element of CharacterToRemodelInformations.possibleChangeMask.";
  }
  else
  {
    this->mandatoryChangeMask = param1->readByte();
    if(this->mandatoryChangeMask < 0)
    {
      qDebug()<<"ERREUR - CharacterToRemodelInformations -"<<"Forbidden value (" << this->mandatoryChangeMask << ") on element of CharacterToRemodelInformations.mandatoryChangeMask.";
    }
    else
    {
      return;
    }
  }
}

CharacterToRemodelInformations::CharacterToRemodelInformations()
{
  m_types<<ClassEnum::CHARACTERTOREMODELINFORMATIONS;
}

bool CharacterToRemodelInformations::operator==(const CharacterToRemodelInformations &compared)
{
  if(possibleChangeMask == compared.possibleChangeMask)
  if(mandatoryChangeMask == compared.mandatoryChangeMask)
  return true;
  
  return false;
}

