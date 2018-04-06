#include "ActorAlignmentInformations.h"

void ActorAlignmentInformations::serialize(Writer *param1)
{
  this->serializeAs_ActorAlignmentInformations(param1);
}

void ActorAlignmentInformations::serializeAs_ActorAlignmentInformations(Writer *param1)
{
  param1->writeByte(this->alignmentSide);
  if(this->alignmentValue < 0)
  {
    qDebug()<<"ERREUR - ActorAlignmentInformations -"<<"Forbidden value (" << this->alignmentValue << ") on element alignmentValue.";
  }
  else
  {
    param1->writeByte(this->alignmentValue);
    if(this->alignmentGrade < 0)
    {
      qDebug()<<"ERREUR - ActorAlignmentInformations -"<<"Forbidden value (" << this->alignmentGrade << ") on element alignmentGrade.";
    }
    else
    {
      param1->writeByte(this->alignmentGrade);
      if(this->characterPower < -9.007199254740992E15 || this->characterPower > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - ActorAlignmentInformations -"<<"Forbidden value (" << this->characterPower << ") on element characterPower.";
      }
      else
      {
        param1->writeDouble(this->characterPower);
        return;
      }
    }
  }
}

void ActorAlignmentInformations::deserialize(Reader *param1)
{
  this->deserializeAs_ActorAlignmentInformations(param1);
}

void ActorAlignmentInformations::deserializeAs_ActorAlignmentInformations(Reader *param1)
{
  this->alignmentSide = param1->readByte();
  this->alignmentValue = param1->readByte();
  if(this->alignmentValue < 0)
  {
    qDebug()<<"ERREUR - ActorAlignmentInformations -"<<"Forbidden value (" << this->alignmentValue << ") on element of ActorAlignmentInformations.alignmentValue.";
  }
  else
  {
    this->alignmentGrade = param1->readByte();
    if(this->alignmentGrade < 0)
    {
      qDebug()<<"ERREUR - ActorAlignmentInformations -"<<"Forbidden value (" << this->alignmentGrade << ") on element of ActorAlignmentInformations.alignmentGrade.";
    }
    else
    {
      this->characterPower = param1->readDouble();
      if(this->characterPower < -9.007199254740992E15 || this->characterPower > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - ActorAlignmentInformations -"<<"Forbidden value (" << this->characterPower << ") on element of ActorAlignmentInformations.characterPower.";
      }
      else
      {
        return;
      }
    }
  }
}

ActorAlignmentInformations::ActorAlignmentInformations()
{
  m_types<<ClassEnum::ACTORALIGNMENTINFORMATIONS;
}

bool ActorAlignmentInformations::operator==(const ActorAlignmentInformations &compared)
{
  if(alignmentSide == compared.alignmentSide)
  if(alignmentValue == compared.alignmentValue)
  if(alignmentGrade == compared.alignmentGrade)
  if(characterPower == compared.characterPower)
  return true;
  
  return false;
}

