#ifndef SHORTCUTBARSWAPREQUESTMESSAGE_H
#define SHORTCUTBARSWAPREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ShortcutBarSwapRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutBarSwapRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutBarSwapRequestMessage(Reader *param1);
  ShortcutBarSwapRequestMessage();

  uint barType;
  uint firstSlot;
  uint secondSlot;
};

#endif // SHORTCUTBARSWAPREQUESTMESSAGE_H