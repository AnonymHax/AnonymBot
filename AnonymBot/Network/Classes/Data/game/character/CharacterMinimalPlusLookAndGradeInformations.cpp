#include "CharacterMinimalPlusLookAndGradeInformations.h"

void CharacterMinimalPlusLookAndGradeInformations::serialize(Writer *param1)
{
  this->serializeAs_CharacterMinimalPlusLookAndGradeInformations(param1);
}

void CharacterMinimalPlusLookAndGradeInformations::serializeAs_CharacterMinimalPlusLookAndGradeInformations(Writer *param1)
{
  CharacterMinimalPlusLookInformations::serializeAs_CharacterMinimalPlusLookInformations(param1);
  if(this->grade < 0)
  {
    qDebug()<<"ERREUR - CharacterMinimalPlusLookAndGradeInformations -"<<"Forbidden value (" << this->grade << ") on element grade.";
  }
  else
  {
    param1->writeVarInt((int)this->grade);
    return;
  }
}

void CharacterMinimalPlusLookAndGradeInformations::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterMinimalPlusLookAndGradeInformations(param1);
}

void CharacterMinimalPlusLookAndGradeInformations::deserializeAs_CharacterMinimalPlusLookAndGradeInformations(Reader *param1)
{
  CharacterMinimalPlusLookInformations::deserialize(param1);
  this->grade = param1->readVarUhInt();
  if(this->grade < 0)
  {
    qDebug()<<"ERREUR - CharacterMinimalPlusLookAndGradeInformations -"<<"Forbidden value (" << this->grade << ") on element of CharacterMinimalPlusLookAndGradeInformations.grade.";
  }
  else
  {
    return;
  }
}

CharacterMinimalPlusLookAndGradeInformations::CharacterMinimalPlusLookAndGradeInformations()
{
  m_types<<ClassEnum::CHARACTERMINIMALPLUSLOOKANDGRADEINFORMATIONS;
}

bool CharacterMinimalPlusLookAndGradeInformations::operator==(const CharacterMinimalPlusLookAndGradeInformations &compared)
{
  if(grade == compared.grade)
  return true;
  
  return false;
}

