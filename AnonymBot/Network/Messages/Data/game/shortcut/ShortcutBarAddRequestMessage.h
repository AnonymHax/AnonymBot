#ifndef SHORTCUTBARADDREQUESTMESSAGE_H
#define SHORTCUTBARADDREQUESTMESSAGE_H

#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/ClassManager.h"

class ShortcutBarAddRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutBarAddRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutBarAddRequestMessage(Reader *param1);
  ShortcutBarAddRequestMessage();

  uint barType;
  QSharedPointer<Shortcut> shortcut;
};

#endif // SHORTCUTBARADDREQUESTMESSAGE_H