#ifndef SHORTCUTBARREFRESHMESSAGE_H
#define SHORTCUTBARREFRESHMESSAGE_H

#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/ClassManager.h"

class ShortcutBarRefreshMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutBarRefreshMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutBarRefreshMessage(Reader *param1);
  ShortcutBarRefreshMessage();

  uint barType;
  QSharedPointer<Shortcut> shortcut;
};

#endif // SHORTCUTBARREFRESHMESSAGE_H