#ifndef LOCALIZEDCHATSMILEYMESSAGE_H
#define LOCALIZEDCHATSMILEYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/chat/smiley/ChatSmileyMessage.h"

class LocalizedChatSmileyMessage : public ChatSmileyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LocalizedChatSmileyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LocalizedChatSmileyMessage(Reader *param1);
  LocalizedChatSmileyMessage();

  uint cellId;
};

#endif // LOCALIZEDCHATSMILEYMESSAGE_H