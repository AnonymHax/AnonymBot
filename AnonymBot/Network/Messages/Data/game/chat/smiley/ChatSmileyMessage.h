#ifndef CHATSMILEYMESSAGE_H
#define CHATSMILEYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChatSmileyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatSmileyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatSmileyMessage(Reader *param1);
  ChatSmileyMessage();

  double entityId;
  uint smileyId;
  uint accountId;
};

#endif // CHATSMILEYMESSAGE_H