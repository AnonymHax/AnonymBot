#ifndef SHORTCUTBARREPLACEDMESSAGE_H
#define SHORTCUTBARREPLACEDMESSAGE_H

#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/ClassManager.h"

class ShortcutBarReplacedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutBarReplacedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutBarReplacedMessage(Reader *param1);
  ShortcutBarReplacedMessage();

  uint barType;
  QSharedPointer<Shortcut> shortcut;
};

#endif // SHORTCUTBARREPLACEDMESSAGE_H