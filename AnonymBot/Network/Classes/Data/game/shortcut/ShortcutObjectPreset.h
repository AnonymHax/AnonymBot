#ifndef SHORTCUTOBJECTPRESET_H
#define SHORTCUTOBJECTPRESET_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/shortcut/ShortcutObject.h"
#include "Network/Classes/Data/game/shortcut/ShortcutObject.h"

class ShortcutObjectPreset : public ShortcutObject
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutObjectPreset(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutObjectPreset(Reader *param1);
  ShortcutObjectPreset();
  bool operator==(const ShortcutObjectPreset &compared);

  uint presetId;
};

#endif // SHORTCUTOBJECTPRESET_H