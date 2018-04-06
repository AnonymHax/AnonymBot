#ifndef CHATADMINSERVERMESSAGE_H
#define CHATADMINSERVERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/chat/ChatServerMessage.h"

class ChatAdminServerMessage : public ChatServerMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatAdminServerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatAdminServerMessage(Reader *param1);
  ChatAdminServerMessage();
};

#endif // CHATADMINSERVERMESSAGE_H