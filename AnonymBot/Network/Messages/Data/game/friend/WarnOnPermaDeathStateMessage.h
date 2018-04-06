#ifndef WARNONPERMADEATHSTATEMESSAGE_H
#define WARNONPERMADEATHSTATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class WarnOnPermaDeathStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_WarnOnPermaDeathStateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_WarnOnPermaDeathStateMessage(Reader *param1);
  WarnOnPermaDeathStateMessage();

  bool enable;
};

#endif // WARNONPERMADEATHSTATEMESSAGE_H