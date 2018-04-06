#include "CharacterMinimalInformations.h"

void CharacterMinimalInformations::serialize(Writer *param1)
{
  this->serializeAs_CharacterMinimalInformations(param1);
}

void CharacterMinimalInformations::serializeAs_CharacterMinimalInformations(Writer *param1)
{
  CharacterBasicMinimalInformations::serializeAs_CharacterBasicMinimalInformations(param1);
  if(this->level < 1 || this->level > 206)
  {
    qDebug()<<"ERREUR - CharacterMinimalInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  else
  {
    param1->writeByte(this->level);
    return;
  }
}

void CharacterMinimalInformations::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterMinimalInformations(param1);
}

void CharacterMinimalInformations::deserializeAs_CharacterMinimalInformations(Reader *param1)
{
  CharacterBasicMinimalInformations::deserialize(param1);
  this->level = param1->readUByte();
  if(this->level < 1 || this->level > 206)
  {
    qDebug()<<"ERREUR - CharacterMinimalInformations -"<<"Forbidden value (" << this->level << ") on element of CharacterMinimalInformations.level.";
  }
  else
  {
    return;
  }
}

CharacterMinimalInformations::CharacterMinimalInformations()
{
  m_types<<ClassEnum::CHARACTERMINIMALINFORMATIONS;
}

bool CharacterMinimalInformations::operator==(const CharacterMinimalInformations &compared)
{
  if(level == compared.level)
  return true;
  
  return false;
}

