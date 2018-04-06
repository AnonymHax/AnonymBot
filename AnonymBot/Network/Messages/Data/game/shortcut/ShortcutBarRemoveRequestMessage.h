#ifndef SHORTCUTBARREMOVEREQUESTMESSAGE_H
#define SHORTCUTBARREMOVEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ShortcutBarRemoveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutBarRemoveRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutBarRemoveRequestMessage(Reader *param1);
  ShortcutBarRemoveRequestMessage();

  uint barType;
  uint slot;
};

#endif // SHORTCUTBARREMOVEREQUESTMESSAGE_H