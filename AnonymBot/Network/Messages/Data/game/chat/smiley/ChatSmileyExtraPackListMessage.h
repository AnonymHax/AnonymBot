#ifndef CHATSMILEYEXTRAPACKLISTMESSAGE_H
#define CHATSMILEYEXTRAPACKLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChatSmileyExtraPackListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatSmileyExtraPackListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatSmileyExtraPackListMessage(Reader *param1);
  ChatSmileyExtraPackListMessage();

  QList<uint> packIds;
};

#endif // CHATSMILEYEXTRAPACKLISTMESSAGE_H