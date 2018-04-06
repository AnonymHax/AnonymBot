#ifndef EMOTEPLAYREQUESTMESSAGE_H
#define EMOTEPLAYREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class EmotePlayRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EmotePlayRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EmotePlayRequestMessage(Reader *param1);
  EmotePlayRequestMessage();

  uint emoteId;
};

#endif // EMOTEPLAYREQUESTMESSAGE_H