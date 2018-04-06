#ifndef SHORTCUTBARREMOVEERRORMESSAGE_H
#define SHORTCUTBARREMOVEERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ShortcutBarRemoveErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutBarRemoveErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutBarRemoveErrorMessage(Reader *param1);
  ShortcutBarRemoveErrorMessage();

  uint error;
};

#endif // SHORTCUTBARREMOVEERRORMESSAGE_H