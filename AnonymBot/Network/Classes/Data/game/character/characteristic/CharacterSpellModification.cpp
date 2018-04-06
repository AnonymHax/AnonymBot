#include "CharacterSpellModification.h"

void CharacterSpellModification::serialize(Writer *param1)
{
  this->serializeAs_CharacterSpellModification(param1);
}

void CharacterSpellModification::serializeAs_CharacterSpellModification(Writer *param1)
{
  param1->writeByte(this->modificationType);
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - CharacterSpellModification -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  else
  {
    param1->writeVarShort((int)this->spellId);
    this->value.serializeAs_CharacterBaseCharacteristic(param1);
    return;
  }
}

void CharacterSpellModification::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterSpellModification(param1);
}

void CharacterSpellModification::deserializeAs_CharacterSpellModification(Reader *param1)
{
  this->modificationType = param1->readByte();
  if(this->modificationType < 0)
  {
    qDebug()<<"ERREUR - CharacterSpellModification -"<<"Forbidden value (" << this->modificationType << ") on element of CharacterSpellModification.modificationType.";
  }
  else
  {
    this->spellId = param1->readVarUhShort();
    if(this->spellId < 0)
    {
      qDebug()<<"ERREUR - CharacterSpellModification -"<<"Forbidden value (" << this->spellId << ") on element of CharacterSpellModification.spellId.";
    }
    else
    {
      this->value = CharacterBaseCharacteristic();
      this->value.deserialize(param1);
      return;
    }
  }
}

CharacterSpellModification::CharacterSpellModification()
{
  m_types<<ClassEnum::CHARACTERSPELLMODIFICATION;
}

bool CharacterSpellModification::operator==(const CharacterSpellModification &compared)
{
  if(modificationType == compared.modificationType)
  if(spellId == compared.spellId)
  if(value == compared.value)
  return true;
  
  return false;
}

