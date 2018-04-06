#ifndef WARNONPERMADEATHMESSAGE_H
#define WARNONPERMADEATHMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class WarnOnPermaDeathMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_WarnOnPermaDeathMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_WarnOnPermaDeathMessage(Reader *param1);
  WarnOnPermaDeathMessage();

  bool enable;
};

#endif // WARNONPERMADEATHMESSAGE_H