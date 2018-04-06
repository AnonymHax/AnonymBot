#ifndef SHORTCUTOBJECTIDOLSPRESET_H
#define SHORTCUTOBJECTIDOLSPRESET_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/shortcut/ShortcutObject.h"
#include "Network/Classes/Data/game/shortcut/ShortcutObject.h"

class ShortcutObjectIdolsPreset : public ShortcutObject
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutObjectIdolsPreset(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutObjectIdolsPreset(Reader *param1);
  ShortcutObjectIdolsPreset();
  bool operator==(const ShortcutObjectIdolsPreset &compared);

  uint presetId;
};

#endif // SHORTCUTOBJECTIDOLSPRESET_H