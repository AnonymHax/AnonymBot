#ifndef CHATSERVERWITHOBJECTMESSAGE_H
#define CHATSERVERWITHOBJECTMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/chat/ChatServerMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ChatServerWithObjectMessage : public ChatServerMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatServerWithObjectMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatServerWithObjectMessage(Reader *param1);
  ChatServerWithObjectMessage();

  QList<QSharedPointer<ObjectItem>> objects;
};

#endif // CHATSERVERWITHOBJECTMESSAGE_H