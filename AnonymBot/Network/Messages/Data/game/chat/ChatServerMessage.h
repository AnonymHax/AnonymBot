#ifndef CHATSERVERMESSAGE_H
#define CHATSERVERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/chat/ChatAbstractServerMessage.h"

class ChatServerMessage : public ChatAbstractServerMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatServerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatServerMessage(Reader *param1);
  ChatServerMessage();

  double senderId;
  QString senderName;
  uint senderAccountId;
};

#endif // CHATSERVERMESSAGE_H