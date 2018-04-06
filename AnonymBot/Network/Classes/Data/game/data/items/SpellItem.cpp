#include "SpellItem.h"

void SpellItem::serialize(Writer *param1)
{
  this->serializeAs_SpellItem(param1);
}

void SpellItem::serializeAs_SpellItem(Writer *param1)
{
  Item::serializeAs_Item(param1);
  param1->writeInt((int)this->spellId);
  if(this->spellLevel < 1 || this->spellLevel > 200)
  {
    qDebug()<<"ERREUR - SpellItem -"<<"Forbidden value (" << this->spellLevel << ") on element spellLevel.";
  }
  else
  {
    param1->writeShort((short)this->spellLevel);
    return;
  }
}

void SpellItem::deserialize(Reader *param1)
{
  this->deserializeAs_SpellItem(param1);
}

void SpellItem::deserializeAs_SpellItem(Reader *param1)
{
  Item::deserialize(param1);
  this->spellId = param1->readInt();
  this->spellLevel = param1->readShort();
  if(this->spellLevel < 1 || this->spellLevel > 200)
  {
    qDebug()<<"ERREUR - SpellItem -"<<"Forbidden value (" << this->spellLevel << ") on element of SpellItem.spellLevel.";
  }
  else
  {
    return;
  }
}

SpellItem::SpellItem()
{
  m_types<<ClassEnum::SPELLITEM;
}

bool SpellItem::operator==(const SpellItem &compared)
{
  if(spellId == compared.spellId)
  if(spellLevel == compared.spellLevel)
  return true;
  
  return false;
}

