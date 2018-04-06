#ifndef NPCDIALOGREPLYMESSAGE_H
#define NPCDIALOGREPLYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NpcDialogReplyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NpcDialogReplyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NpcDialogReplyMessage(Reader *param1);
  NpcDialogReplyMessage();

  uint replyId;
};

#endif // NPCDIALOGREPLYMESSAGE_H