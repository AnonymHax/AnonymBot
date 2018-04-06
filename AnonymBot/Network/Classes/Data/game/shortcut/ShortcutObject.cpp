#include "ShortcutObject.h"

void ShortcutObject::serialize(Writer *param1)
{
  this->serializeAs_ShortcutObject(param1);
}

void ShortcutObject::serializeAs_ShortcutObject(Writer *param1)
{
  Shortcut::serializeAs_Shortcut(param1);
}

void ShortcutObject::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutObject(param1);
}

void ShortcutObject::deserializeAs_ShortcutObject(Reader *param1)
{
  Shortcut::deserialize(param1);
}

ShortcutObject::ShortcutObject()
{
  m_types<<ClassEnum::SHORTCUTOBJECT;
}

bool ShortcutObject::operator==(const ShortcutObject &compared)
{
  return true;
}

