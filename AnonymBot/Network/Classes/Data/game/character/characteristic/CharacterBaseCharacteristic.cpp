#include "CharacterBaseCharacteristic.h"

void CharacterBaseCharacteristic::serialize(Writer *param1)
{
  this->serializeAs_CharacterBaseCharacteristic(param1);
}

void CharacterBaseCharacteristic::serializeAs_CharacterBaseCharacteristic(Writer *param1)
{
  param1->writeVarShort((int)this->base);
  param1->writeVarShort((int)this->additionnal);
  param1->writeVarShort((int)this->objectsAndMountBonus);
  param1->writeVarShort((int)this->alignGiftBonus);
  param1->writeVarShort((int)this->contextModif);
}

void CharacterBaseCharacteristic::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterBaseCharacteristic(param1);
}

void CharacterBaseCharacteristic::deserializeAs_CharacterBaseCharacteristic(Reader *param1)
{
  this->base = param1->readVarShort();
  this->additionnal = param1->readVarShort();
  this->objectsAndMountBonus = param1->readVarShort();
  this->alignGiftBonus = param1->readVarShort();
  this->contextModif = param1->readVarShort();
}

CharacterBaseCharacteristic::CharacterBaseCharacteristic()
{
  m_types<<ClassEnum::CHARACTERBASECHARACTERISTIC;
}

bool CharacterBaseCharacteristic::operator==(const CharacterBaseCharacteristic &compared)
{
  if(base == compared.base)
  if(additionnal == compared.additionnal)
  if(objectsAndMountBonus == compared.objectsAndMountBonus)
  if(alignGiftBonus == compared.alignGiftBonus)
  if(contextModif == compared.contextModif)
  return true;
  
  return false;
}

