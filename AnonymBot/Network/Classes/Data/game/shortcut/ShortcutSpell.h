#ifndef SHORTCUTSPELL_H
#define SHORTCUTSPELL_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"

class ShortcutSpell : public Shortcut
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutSpell(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutSpell(Reader *param1);
  ShortcutSpell();
  bool operator==(const ShortcutSpell &compared);

  uint spellId;
};

#endif // SHORTCUTSPELL_H