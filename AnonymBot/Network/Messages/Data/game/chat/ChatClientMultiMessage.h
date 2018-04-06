#ifndef CHATCLIENTMULTIMESSAGE_H
#define CHATCLIENTMULTIMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/chat/ChatAbstractClientMessage.h"

class ChatClientMultiMessage : public ChatAbstractClientMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatClientMultiMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatClientMultiMessage(Reader *param1);
  ChatClientMultiMessage();

  uint channel;
};

#endif // CHATCLIENTMULTIMESSAGE_H