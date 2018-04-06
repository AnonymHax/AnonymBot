#ifndef SHORTCUTSMILEY_H
#define SHORTCUTSMILEY_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"

class ShortcutSmiley : public Shortcut
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutSmiley(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutSmiley(Reader *param1);
  ShortcutSmiley();
  bool operator==(const ShortcutSmiley &compared);

  uint smileyId;
};

#endif // SHORTCUTSMILEY_H