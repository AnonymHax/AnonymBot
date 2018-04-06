#ifndef CHATABSTRACTCLIENTMESSAGE_H
#define CHATABSTRACTCLIENTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChatAbstractClientMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatAbstractClientMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatAbstractClientMessage(Reader *param1);
  ChatAbstractClientMessage();

  QString content;
};

#endif // CHATABSTRACTCLIENTMESSAGE_H