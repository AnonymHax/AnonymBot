#ifndef SHORTCUTBARADDERRORMESSAGE_H
#define SHORTCUTBARADDERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ShortcutBarAddErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutBarAddErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutBarAddErrorMessage(Reader *param1);
  ShortcutBarAddErrorMessage();

  uint error;
};

#endif // SHORTCUTBARADDERRORMESSAGE_H