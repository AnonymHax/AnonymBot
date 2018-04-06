#ifndef MOUNTEMOTEICONUSEDOKMESSAGE_H
#define MOUNTEMOTEICONUSEDOKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountEmoteIconUsedOkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountEmoteIconUsedOkMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountEmoteIconUsedOkMessage(Reader *param1);
  MountEmoteIconUsedOkMessage();

  int mountId;
  uint reactionType;
};

#endif // MOUNTEMOTEICONUSEDOKMESSAGE_H