#ifndef CHATCLIENTPRIVATEMESSAGE_H
#define CHATCLIENTPRIVATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/chat/ChatAbstractClientMessage.h"

class ChatClientPrivateMessage : public ChatAbstractClientMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatClientPrivateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatClientPrivateMessage(Reader *param1);
  ChatClientPrivateMessage();

  QString receiver;
};

#endif // CHATCLIENTPRIVATEMESSAGE_H