#ifndef SHORTCUTOBJECT_H
#define SHORTCUTOBJECT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"

class ShortcutObject : public Shortcut
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutObject(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutObject(Reader *param1);
  ShortcutObject();
  bool operator==(const ShortcutObject &compared);
};

#endif // SHORTCUTOBJECT_H