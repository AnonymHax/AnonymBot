#include "ItemDurability.h"

void ItemDurability::serialize(Writer *param1)
{
  this->serializeAs_ItemDurability(param1);
}

void ItemDurability::serializeAs_ItemDurability(Writer *param1)
{
  param1->writeShort((short)this->durability);
  param1->writeShort((short)this->durabilityMax);
}

void ItemDurability::deserialize(Reader *param1)
{
  this->deserializeAs_ItemDurability(param1);
}

void ItemDurability::deserializeAs_ItemDurability(Reader *param1)
{
  this->durability = param1->readShort();
  this->durabilityMax = param1->readShort();
}

ItemDurability::ItemDurability()
{
  m_types<<ClassEnum::ITEMDURABILITY;
}

bool ItemDurability::operator==(const ItemDurability &compared)
{
  if(durability == compared.durability)
  if(durabilityMax == compared.durabilityMax)
  return true;
  
  return false;
}

