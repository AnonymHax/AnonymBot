#ifndef CHATSERVERCOPYMESSAGE_H
#define CHATSERVERCOPYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/chat/ChatAbstractServerMessage.h"

class ChatServerCopyMessage : public ChatAbstractServerMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatServerCopyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatServerCopyMessage(Reader *param1);
  ChatServerCopyMessage();

  double receiverId;
  QString receiverName;
};

#endif // CHATSERVERCOPYMESSAGE_H