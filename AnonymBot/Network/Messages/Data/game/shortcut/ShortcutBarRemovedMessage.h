#ifndef SHORTCUTBARREMOVEDMESSAGE_H
#define SHORTCUTBARREMOVEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ShortcutBarRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutBarRemovedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutBarRemovedMessage(Reader *param1);
  ShortcutBarRemovedMessage();

  uint barType;
  uint slot;
};

#endif // SHORTCUTBARREMOVEDMESSAGE_H