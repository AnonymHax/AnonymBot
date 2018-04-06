#ifndef SERVERSTATUSUPDATEMESSAGE_H
#define SERVERSTATUSUPDATEMESSAGE_H

#include "Network/Classes/Data/connection/GameServerInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/connection/GameServerInformations.h"

class ServerStatusUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ServerStatusUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ServerStatusUpdateMessage(Reader *param1);
  ServerStatusUpdateMessage();

  GameServerInformations server;
};

#endif // SERVERSTATUSUPDATEMESSAGE_H