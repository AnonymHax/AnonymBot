#ifndef SHORTCUTOBJECTITEM_H
#define SHORTCUTOBJECTITEM_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/shortcut/ShortcutObject.h"
#include "Network/Classes/Data/game/shortcut/ShortcutObject.h"

class ShortcutObjectItem : public ShortcutObject
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutObjectItem(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutObjectItem(Reader *param1);
  ShortcutObjectItem();
  bool operator==(const ShortcutObjectItem &compared);

  int itemUID;
  int itemGID;
};

#endif // SHORTCUTOBJECTITEM_H