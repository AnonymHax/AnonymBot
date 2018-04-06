#include "ShortcutObjectItem.h"

void ShortcutObjectItem::serialize(Writer *param1)
{
  this->serializeAs_ShortcutObjectItem(param1);
}

void ShortcutObjectItem::serializeAs_ShortcutObjectItem(Writer *param1)
{
  ShortcutObject::serializeAs_ShortcutObject(param1);
  param1->writeInt((int)this->itemUID);
  param1->writeInt((int)this->itemGID);
}

void ShortcutObjectItem::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutObjectItem(param1);
}

void ShortcutObjectItem::deserializeAs_ShortcutObjectItem(Reader *param1)
{
  ShortcutObject::deserialize(param1);
  this->itemUID = param1->readInt();
  this->itemGID = param1->readInt();
}

ShortcutObjectItem::ShortcutObjectItem()
{
  m_types<<ClassEnum::SHORTCUTOBJECTITEM;
}

bool ShortcutObjectItem::operator==(const ShortcutObjectItem &compared)
{
  if(itemUID == compared.itemUID)
  if(itemGID == compared.itemGID)
  return true;
  
  return false;
}

