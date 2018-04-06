#ifndef SHORTCUTBARSWAPERRORMESSAGE_H
#define SHORTCUTBARSWAPERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ShortcutBarSwapErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutBarSwapErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutBarSwapErrorMessage(Reader *param1);
  ShortcutBarSwapErrorMessage();

  uint error;
};

#endif // SHORTCUTBARSWAPERRORMESSAGE_H