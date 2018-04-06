#ifndef EMOTEPLAYERRORMESSAGE_H
#define EMOTEPLAYERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class EmotePlayErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EmotePlayErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EmotePlayErrorMessage(Reader *param1);
  EmotePlayErrorMessage();

  uint emoteId;
};

#endif // EMOTEPLAYERRORMESSAGE_H