#ifndef CHATSMILEYREQUESTMESSAGE_H
#define CHATSMILEYREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChatSmileyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatSmileyRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatSmileyRequestMessage(Reader *param1);
  ChatSmileyRequestMessage();

  uint smileyId;
};

#endif // CHATSMILEYREQUESTMESSAGE_H