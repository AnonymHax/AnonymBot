#ifndef SHORTCUTEMOTE_H
#define SHORTCUTEMOTE_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"

class ShortcutEmote : public Shortcut
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutEmote(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutEmote(Reader *param1);
  ShortcutEmote();
  bool operator==(const ShortcutEmote &compared);

  uint emoteId;
};

#endif // SHORTCUTEMOTE_H