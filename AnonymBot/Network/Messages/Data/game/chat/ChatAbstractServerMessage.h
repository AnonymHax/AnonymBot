#ifndef CHATABSTRACTSERVERMESSAGE_H
#define CHATABSTRACTSERVERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChatAbstractServerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatAbstractServerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatAbstractServerMessage(Reader *param1);
  ChatAbstractServerMessage();

  uint channel;
  QString content;
  uint timestamp;
  QString fingerprint;
};

#endif // CHATABSTRACTSERVERMESSAGE_H