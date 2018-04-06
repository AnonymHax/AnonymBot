#include "CharacterHardcoreOrEpicInformations.h"

void CharacterHardcoreOrEpicInformations::serialize(Writer *param1)
{
  this->serializeAs_CharacterHardcoreOrEpicInformations(param1);
}

void CharacterHardcoreOrEpicInformations::serializeAs_CharacterHardcoreOrEpicInformations(Writer *param1)
{
  CharacterBaseInformations::serializeAs_CharacterBaseInformations(param1);
  param1->writeByte(this->deathState);
  if(this->deathCount < 0)
  {
    qDebug()<<"ERREUR - CharacterHardcoreOrEpicInformations -"<<"Forbidden value (" << this->deathCount << ") on element deathCount.";
  }
  else
  {
    param1->writeVarShort((int)this->deathCount);
    if(this->deathMaxLevel < 1 || this->deathMaxLevel > 206)
    {
      qDebug()<<"ERREUR - CharacterHardcoreOrEpicInformations -"<<"Forbidden value (" << this->deathMaxLevel << ") on element deathMaxLevel.";
    }
    else
    {
      param1->writeByte(this->deathMaxLevel);
      return;
    }
  }
}

void CharacterHardcoreOrEpicInformations::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterHardcoreOrEpicInformations(param1);
}

void CharacterHardcoreOrEpicInformations::deserializeAs_CharacterHardcoreOrEpicInformations(Reader *param1)
{
  CharacterBaseInformations::deserialize(param1);
  this->deathState = param1->readByte();
  if(this->deathState < 0)
  {
    qDebug()<<"ERREUR - CharacterHardcoreOrEpicInformations -"<<"Forbidden value (" << this->deathState << ") on element of CharacterHardcoreOrEpicInformations.deathState.";
  }
  else
  {
    this->deathCount = param1->readVarUhShort();
    if(this->deathCount < 0)
    {
      qDebug()<<"ERREUR - CharacterHardcoreOrEpicInformations -"<<"Forbidden value (" << this->deathCount << ") on element of CharacterHardcoreOrEpicInformations.deathCount.";
    }
    else
    {
      this->deathMaxLevel = param1->readUByte();
      if(this->deathMaxLevel < 1 || this->deathMaxLevel > 206)
      {
        qDebug()<<"ERREUR - CharacterHardcoreOrEpicInformations -"<<"Forbidden value (" << this->deathMaxLevel << ") on element of CharacterHardcoreOrEpicInformations.deathMaxLevel.";
      }
      else
      {
        return;
      }
    }
  }
}

CharacterHardcoreOrEpicInformations::CharacterHardcoreOrEpicInformations()
{
  m_types<<ClassEnum::CHARACTERHARDCOREOREPICINFORMATIONS;
}

bool CharacterHardcoreOrEpicInformations::operator==(const CharacterHardcoreOrEpicInformations &compared)
{
  if(deathState == compared.deathState)
  if(deathCount == compared.deathCount)
  if(deathMaxLevel == compared.deathMaxLevel)
  return true;
  
  return false;
}

