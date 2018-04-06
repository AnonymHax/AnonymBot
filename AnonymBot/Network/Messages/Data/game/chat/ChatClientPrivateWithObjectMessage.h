#ifndef CHATCLIENTPRIVATEWITHOBJECTMESSAGE_H
#define CHATCLIENTPRIVATEWITHOBJECTMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/chat/ChatClientPrivateMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ChatClientPrivateWithObjectMessage : public ChatClientPrivateMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatClientPrivateWithObjectMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatClientPrivateWithObjectMessage(Reader *param1);
  ChatClientPrivateWithObjectMessage();

  QList<QSharedPointer<ObjectItem>> objects;
};

#endif // CHATCLIENTPRIVATEWITHOBJECTMESSAGE_H