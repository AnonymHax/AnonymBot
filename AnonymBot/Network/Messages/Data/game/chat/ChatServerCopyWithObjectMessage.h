#ifndef CHATSERVERCOPYWITHOBJECTMESSAGE_H
#define CHATSERVERCOPYWITHOBJECTMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/chat/ChatServerCopyMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ChatServerCopyWithObjectMessage : public ChatServerCopyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatServerCopyWithObjectMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatServerCopyWithObjectMessage(Reader *param1);
  ChatServerCopyWithObjectMessage();

  QList<QSharedPointer<ObjectItem>> objects;
};

#endif // CHATSERVERCOPYWITHOBJECTMESSAGE_H