#ifndef EMOTEREMOVEMESSAGE_H
#define EMOTEREMOVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class EmoteRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EmoteRemoveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EmoteRemoveMessage(Reader *param1);
  EmoteRemoveMessage();

  uint emoteId;
};

#endif // EMOTEREMOVEMESSAGE_H