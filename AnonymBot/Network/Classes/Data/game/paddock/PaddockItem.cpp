#include "PaddockItem.h"

void PaddockItem::serialize(Writer *param1)
{
  this->serializeAs_PaddockItem(param1);
}

void PaddockItem::serializeAs_PaddockItem(Writer *param1)
{
  ObjectItemInRolePlay::serializeAs_ObjectItemInRolePlay(param1);
  this->durability.serializeAs_ItemDurability(param1);
}

void PaddockItem::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockItem(param1);
}

void PaddockItem::deserializeAs_PaddockItem(Reader *param1)
{
  ObjectItemInRolePlay::deserialize(param1);
  this->durability = ItemDurability();
  this->durability.deserialize(param1);
}

PaddockItem::PaddockItem()
{
  m_types<<ClassEnum::PADDOCKITEM;
}

bool PaddockItem::operator==(const PaddockItem &compared)
{
  if(durability == compared.durability)
  return true;
  
  return false;
}

