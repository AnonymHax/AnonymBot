#ifndef SERVERSELECTIONMESSAGE_H
#define SERVERSELECTIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ServerSelectionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ServerSelectionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ServerSelectionMessage(Reader *param1);
  ServerSelectionMessage();

  uint serverId;
};

#endif // SERVERSELECTIONMESSAGE_H