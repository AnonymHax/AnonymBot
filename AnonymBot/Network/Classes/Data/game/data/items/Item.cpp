#include "Item.h"

void Item::serialize(Writer *param1)
{
}

void Item::serializeAs_Item(Writer *param1)
{
}

void Item::deserialize(Reader *param1)
{
}

void Item::deserializeAs_Item(Reader *param1)
{
}

Item::Item()
{
  m_types<<ClassEnum::ITEM;
}

bool Item::operator==(const Item &compared)
{
  return true;
}

