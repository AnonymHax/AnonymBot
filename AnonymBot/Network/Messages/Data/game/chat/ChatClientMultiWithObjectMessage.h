#ifndef CHATCLIENTMULTIWITHOBJECTMESSAGE_H
#define CHATCLIENTMULTIWITHOBJECTMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/chat/ChatClientMultiMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ChatClientMultiWithObjectMessage : public ChatClientMultiMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatClientMultiWithObjectMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatClientMultiWithObjectMessage(Reader *param1);
  ChatClientMultiWithObjectMessage();

  QList<QSharedPointer<ObjectItem>> objects;
};

#endif // CHATCLIENTMULTIWITHOBJECTMESSAGE_H